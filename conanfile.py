# from conan import ConanFile
# from conan.tools.cmake import CMakeToolchain, CMake, cmake_layout, CMakeDeps
# from conan.tools.scm import Git
# from conan.tools.files import copy
# import os
# import glob
# import hashlib

# class AudioRecipe(ConanFile):
#     name = "audio-cpp"
#     version = "2.0"
#     package_type = "static-library"
#     license = "Apache-2.0"
#     homepage = "https://github.com/engine3d-dev/audio-cpp"

#     # Binary configuration
#     settings = "os", "compiler", "build_type", "arch"
#     options = {"shared": [True, False], "fPIC": [True, False]}
#     default_options = {"shared": False, "fPIC": True}
#     exports_sources = "CMakeLists.txt", "audio-cpp/*", "tests/*", "include/*"

#     def build_requirements(self):
#         self.tool_requires("ninja/1.13.2")
#         self.tool_requires("cmake/4.2.1")
#         self.tool_requires("engine3d-cmake-utils/4.0")
#         # self.tool_requires("cmake-modules-toolchain/1.0.3")
#         self.requires("boost-ext-ut/2.1.0")

#     # def export_sources(self):
#     #     copy(self, "include/*", self.source_folder, self.export_sources_folder)
    
#     def requirements(self):
#         self.requires("miniaudio/1.0")

#     def layout(self):
#         cmake_layout(self)
    
#     def generate(self):
#         tc = CMakeToolchain(self)
#         tc.generator = "Ninja"
#         tc.generate()

#         deps = CMakeDeps(self)
#         deps.generate()
    
#     def file_changed(self, filepath, previous_hash=None):
#         """
#         Checks if a file has changed by comparing its current hash with a previous hash.

#         Args:
#             filepath (str): The path to the file.
#             previous_hash (str, optional): The previous hash of the file. Defaults to None.

#         Returns:
#             tuple: (True, current_hash) if the file has changed or is new, (False, current_hash) otherwise.
#                 Returns (None, None) if the file does not exist.
#         """
#         if not os.path.exists(filepath):
#             return None, None

#         try:
#             with open(filepath, 'rb') as f:
#                 file_content = f.read()
#             current_hash = hashlib.md5(file_content).hexdigest()

#             if previous_hash is None:  # First time checking the file
#                 return True, current_hash

#             return current_hash != previous_hash, current_hash

#         except Exception as e:
#             print(f"Error checking file {filepath}: {e}")
#             return None, None

#     def build(self):
#         # Directory to the files tests get generated
#         # gcda_tests_dir = os.path.join(self.build_folder, "CMakeFiles/unit_test.dir/tests")
#         # tests_dir = os.path.join(self.source_folder, "tests");
#         # tests_files = os.path.join(tests_dir, "*.test.cpp")

#         # gcda_files = os.path.join(gcda_tests_dir, "*.gcda")

#         # if os.path.exists(gcda_tests_dir):
#         #     for file in glob.glob(gcda_files):
#         #         os.remove(file)

#         cmake = CMake(self)
#         cmake.verbose = True
#         cmake.configure()
#         cmake.build()
        
    
#     def package(self):
#         copy(self, "LICENSE", src=self.source_folder, dst=os.path.join(self.package_folder, "licenses"))
#         cmake = CMake(self)
#         cmake.install()
#         copy(self, "include/*", self.source_folder, self.package_folder)


    # def package_info(self):
    #     self.cpp_info.set_property("cmake_find_node", "none")
    #     # self.cpp_info.set_property("cmake_target_name", "audio-cpp::audio-cpp")
    #     # self.cpp_info.libs = ["audio-cpp"]
    #     # self.cpp_info.includedirs = ['./audio-cpp']
    #     self.cpp_info.builddirs.append("lib/cmake")

from conan import ConanFile
from conan.tools.cmake import CMake, cmake_layout, CMakeToolchain, CMakeDeps
from conan.tools.files import copy
from conan.errors import ConanInvalidConfiguration
from conan.tools.build import check_min_cppstd
from pathlib import Path


required_conan_version = ">=2.2.0"


class AudioCppRecipe(ConanFile):
    name = "audio-cpp"
    version = "2.0"
    license = "Apache-2.0"
    url = "https://github.com/engine3d-dev/audio-cpp"
    homepage = "https://github.com/engine3d-dev/audio-cpp"
    settings = "compiler", "build_type", "os", "arch"
    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = {"shared": False, "fPIC": True}
    exports_sources = "audio-cpp/*", "tests/*", "CMakeLists.txt", "LICENSE"

    def build_requirements(self):
        self.tool_requires("cmake/[^4.0.0]")
        self.tool_requires("ninja/[^1.3.0]")
        self.test_requires("boost-ext-ut/2.3.1")
        self.tool_requires("engine3d-cmake-utils/4.0")

    def requirements(self):
        self.requires("miniaudio/1.0")

    def layout(self):
        cmake_layout(self)

    def generate(self):
        tc = CMakeToolchain(self)
        tc.generator = "Ninja"
        tc.generate()

        deps = CMakeDeps(self)
        deps.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()

        copy(self, "LICENSE",
             dst=Path(self.package_folder) / "licenses",
             src=self.source_folder)

    def package_info(self):
        # DISABLE Conan's config file generation
        self.cpp_info.set_property("cmake_find_mode", "none")
        # Tell CMake to include this directory in its search path
        self.cpp_info.builddirs.append("lib/cmake")
