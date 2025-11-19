from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake, cmake_layout, CMakeDeps
from conan.tools.scm import Git
from conan.tools.files import copy
import os
import glob
import hashlib
# from conan.tools.files import find_files

class AudioRecipe(ConanFile):
    name = "audio-cpp"
    version = "1.1"
    package_type = "library"
    license = "Apache-2.0"
    homepage = "https://github.com/engine3d-dev/engine3d-audio"

    # Binary configuration
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = {"shared": False, "fPIC": True}
    exports_sources = "CMakeLists.txt", "src/CMakeLists.txt"

    def build_requirements(self):
        self.tool_requires("make/4.4.1")
        self.tool_requires("cmake/3.27.1")
        self.tool_requires("engine3d-cmake-utils/4.0")
        self.requires("boost-ext-ut/2.3.1")
    
    def requirements(self):
        self.requires("miniaudio/1.0")
        self.requires("atlas/0.2")
        self.requires("flecs/4.0.4")
        self.requires("glm/1.0.1")
    
    # This is how exporting the sources work
    def export_sources(self):
        copy(self,"CMakeLists.txt", self.recipe_folder, self.export_sources_folder)
        copy(self,"*.hpp", self.recipe_folder, self.export_sources_folder)
        copy(self,"*.h", self.recipe_folder, self.export_sources_folder)
        copy(self,"*.cpp", self.recipe_folder, self.export_sources_folder)

    def layout(self):
        cmake_layout(self)
    
    def generate(self):
        deps = CMakeDeps(self)
        deps.generate()

        tc = CMakeToolchain(self)
        tc.generate()
    
    def file_changed(self, filepath, previous_hash=None):
        """
        Checks if a file has changed by comparing its current hash with a previous hash.

        Args:
            filepath (str): The path to the file.
            previous_hash (str, optional): The previous hash of the file. Defaults to None.

        Returns:
            tuple: (True, current_hash) if the file has changed or is new, (False, current_hash) otherwise.
                Returns (None, None) if the file does not exist.
        """
        if not os.path.exists(filepath):
            return None, None

        try:
            with open(filepath, 'rb') as f:
                file_content = f.read()
            current_hash = hashlib.md5(file_content).hexdigest()

            if previous_hash is None:  # First time checking the file
                return True, current_hash

            return current_hash != previous_hash, current_hash

        except Exception as e:
            print(f"Error checking file {filepath}: {e}")
            return None, None

    def build(self):
        # Directory to the files tests get generated
        gcda_tests_dir = os.path.join(self.build_folder, "CMakeFiles/unit_test.dir/tests")
        tests_dir = os.path.join(self.source_folder, "tests");
        tests_files = os.path.join(tests_dir, "*.test.cpp")

        gcda_files = os.path.join(gcda_tests_dir, "*.gcda")

        if os.path.exists(gcda_tests_dir):
            for file in glob.glob(gcda_files):
                os.remove(file)

        cmake = CMake(self)
        cmake.verbose = True
        cmake.configure()
        cmake.build()
        
    
    def package(self):
        copy(self, "LICENSE", src=self.source_folder, dst=os.path.join(self.package_folder, "licenses"))
        copy(self, pattern="*.h", src=os.path.join(self.source_folder, "audio-cpp"), dst=os.path.join(self.package_folder, "audio-cpp"))
        copy(self, pattern="*.hpp", src=os.path.join(self.source_folder, "audio-cpp"), dst=os.path.join(self.package_folder, "audio-cpp"))
        copy(self, pattern="*.a", src=self.build_folder, dst=os.path.join(self.package_folder, "lib"), keep_path=False)
        copy(self, pattern="*.so", src=self.build_folder, dst=os.path.join(self.package_folder, "lib"), keep_path=False)
        copy(self, pattern="*.lib", src=self.build_folder, dst=os.path.join(self.package_folder, "lib"), keep_path=False)
        copy(self, pattern="*.dll", src=self.build_folder, dst=os.path.join(self.package_folder, "bin"), keep_path=False)
        copy(self, pattern="*.dylib", src=self.build_folder, dst=os.path.join(self.package_folder, "lib"), keep_path=False)
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.set_property("cmake_target_name", "audio-cpp::audio-cpp")
        self.cpp_info.libs = ["audio-cpp"]
        self.cpp_info.includedirs = ['./', './audio-cpp']
