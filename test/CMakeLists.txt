add_subdirectory(${PROJECT_SOURCE_DIR}/extern/googletest extern/googletest)

macro(package_add_test TESTNAME)
    add_executable(${TESTNAME} ${ARGN})

    target_link_libraries(${TESTNAME} gtest gmock gtest_main rt-core)

    gtest_discover_tests(${TESTNAME}
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
        PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}"
    )
    set_target_properties(${TESTNAME} PROPERTIES FOLDER tests)
endmacro()

package_add_test(Vector3 Vector3Test.cpp)
package_add_test(Ray RayTest.cpp)
package_add_test(Sphere SphereTest.cpp)