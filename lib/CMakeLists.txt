add_library(rt-core)

target_include_directories(rt-core PUBLIC ${PROJECT_SOURCE_DIR}/include)

target_compile_features(rt-core PUBLIC cxx_std_14)

file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/include/*.hpp")

target_sources(rt-core
	PRIVATE
		Vector3.cpp
		Image.cpp
		Ray.cpp
		Surface.cpp
		Group.cpp
		HitRecord.cpp
		Sphere.cpp
		Material.cpp
		Light.cpp
		AmbientLight.cpp
		PointLight.cpp
		DirectionalLight.cpp
		Scene.cpp
		Plane.cpp
		${HEADER_LIST}
)
