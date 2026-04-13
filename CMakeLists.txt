cmake_minimum_required(VERSION 3.5)
project(Interstonar)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(MAIN
    src/Main.cpp
)

set(SRCS
    src/Parsing/Parsing.cpp
    src/Parsing/ParseConfigFile.cpp
    src/Parsing/ParseConfigFileCommands.cpp
    src/Parsing/ParseConfigFileTypes.cpp
    src/Astre/Astre.cpp
    src/Astre/TypeBox.cpp
    src/Astre/TypeCylinder.cpp
    src/Astre/TypeSphere.cpp
    src/Astre/TypeTorus.cpp
    src/Interstonar.cpp
    src/Vector3D.cpp
)

set(HEADERS
    include/
    include/Astre
)

add_executable(interstonar ${MAIN} ${SRCS})
target_include_directories(interstonar PRIVATE ${HEADERS})

find_library(CRITERION criterion REQUIRED)

set(SRCS_TESTS
    tests/testsArgsParsing.cpp
    tests/testsFilesParsing.cpp
    tests/testsLocalMode.cpp
)

add_executable(tests_run_bin EXCLUDE_FROM_ALL ${SRCS_TESTS} ${SRCS})
target_include_directories(tests_run_bin PRIVATE ${HEADERS})
target_compile_options(tests_run_bin PRIVATE --coverage)
target_link_libraries(tests_run_bin criterion --coverage)

add_custom_target(tests_run
    COMMAND ${CMAKE_COMMAND} -E remove -f ${CMAKE_BINARY_DIR}/*.gcda
    COMMAND ./tests_run_bin
    DEPENDS tests_run_bin
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
