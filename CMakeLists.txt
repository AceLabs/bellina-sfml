cmake_minimum_required(VERSION 3.5)
project(FML)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#set(GO_ROOT MyApp/_obj)
#set(GO_FILES ${GO_ROOT}/_cgo_export.c ${GO_ROOT}/_cgo_main.c ${GO_ROOT}/MainGo.cgo2.c )
set(SOURCE_FILES samples/main.cpp g2/g2-core.cpp xel/xel.cpp) # ${GO_FILES} )
add_executable(FML ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

find_package(SFML REQUIRED system window graphics)
find_package(GLEW REQUIRED)
find_package(OPENGL REQUIRED)

if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(FML ${SFML_LIBRARIES})
    message(AUTHOR_WARNING "found SFML")
endif()


if (GLEW_FOUND)
    include_directories($(GLEW_INCLUDE_DIRS))
    target_link_libraries(FML ${GLEW_LIBRARIES})
    message(AUTHOR_WARNING "found GLEW")
endif()

if (OPENGL_FOUND)
    target_link_libraries(FML ${OPENGL_LIBRARIES})
    message(AUTHOR_WARNING "found OpenGL")
endif()