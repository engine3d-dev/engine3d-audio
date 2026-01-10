from conan import ConanFile
from conan.tools.cmake import CMake, cmake_layout, CMakeToolchain, CMakeDeps
from conan.tools.files import copy
from pathlib import Path


required_conan_version = ">=2.2.0"


class AudioCppRecipe(ConanFile):
    name = "audio-cpp"
    version = "1.1"
    package_type = "library"
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
        self.requires("boost-ext-ut/2.3.1")
    
    def requirements(self):
        self.requires("miniaudio/1.0")
        self.requires("atlas/0.2")
        self.requires("flecs/4.0.4")
        self.requires("glm/1.0.1")
        self.requires("spdlog/1.15.1")
    
    # This is how exporting the sources work
    def export_sources(self):
        copy(self,"CMakeLists.txt", self.recipe_folder, self.export_sources_folder)
        copy(self,"*.hpp", self.recipe_folder, self.export_sources_folder)
        copy(self,"*.h", self.recipe_folder, self.export_sources_folder)
        copy(self,"*.cpp", self.recipe_folder, self.export_sources_folder)

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
