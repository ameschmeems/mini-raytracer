add_library(rt-core)

target_include_directories(rt-core PUBLIC ${PROJECT_SOURCE_DIR}/include)

target_compile_features(rt-core PUBLIC cxx_std_14)

file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/include/modern/*.hpp")

target_sources(rt-core
	PRIVATE
		Vector3.cpp
		Image.cpp
		Ray.cpp
		${HEADER_LIST}
)