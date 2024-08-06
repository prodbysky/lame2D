file(GLOB_RECURSE EXAMPLE_SOURCES "*.cpp")

foreach(EXAMPLE_SOURCE ${EXAMPLE_SOURCES})
    get_filename_component(EXAMPLE_NAME ${EXAMPLE_SOURCE} NAME_WE)
    set(CMAKE_CXX_FLAGS "-O3")
    # set(CMAKE_CXX_FLAGS "-ggdb")
    add_executable(${EXAMPLE_NAME} ${EXAMPLE_SOURCE})
    target_link_libraries(${EXAMPLE_NAME} lame2D)
endforeach()
