from conan import ConanFile
from conan.tools.cmake import CMake, cmake_layout

class Demo(ConanFile):
    name = "demo"
    version = "1.0"
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps", "CMakeToolchain"
    export_source = "CMakeLists.txt", "audio-cpp/*"

    # Putting all of your build-related dependencies here
    def build_requirements(self):
        self.tool_requires("ninja/1.13.2")
        self.tool_requires("cmake/4.2.1")
        self.tool_requires("cmake-modules-toolchain/1.0.3")
        self.tool_requires("engine3d-cmake-utils/5.0")

    # Putting all of your packages here
    def requirements(self):
        self.requires("audio-cpp/2.0")
        self.requires("miniaudio/2.0")

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()
    
    def layout(self):
        cmake_layout(self)
