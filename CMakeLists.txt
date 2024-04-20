cmake_minimum_required(VERSION 3.23)
project(
	mini-raytracer
	VERSION 1.0
	DESCRIPTION "Simple ray-tracer"
	LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()
include(GoogleTest)

add_subdirectory(lib)
add_subdirectory(test)
add_subdirectory(src)