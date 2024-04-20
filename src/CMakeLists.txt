add_executable(mini-raytracer)

target_sources(mini-raytracer
	PRIVATE
		main.cpp
)

target_link_libraries(mini-raytracer PRIVATE rt-core)