cmake_minimum_required(VERSION 3.7)
#construct target
add_executable(say-hello main.cpp hello.cpp)
#add compile options
target_compile_features(say-hello PRIVATE cxx_std_17)
#include path of the public header files 
target_include_directories(say-hello 
                            PRIVATE ${PROJECT_SOURCE_DIR}/include)      
#include static /shared library
target_include_directories(say-hello 
                            PRIVATE ${PROJECT_SOURCE_DIR}/lib/box2d)
target_link_libraries(say-hello
                            PRIVATE box2d)               

# target_include_directories(say-hello
#                             PRIVATE ${BOX2D_INCLUDE_DIR})
#external package --- boost
find_package( Boost REQUIRED)
if(Boost_FOUND)
    message ("boost found")
else()
    message (FATAL_ERROR "Cannot find Boost")
endif()
#external package --- opencv
find_package( OpenCV 4 REQUIRED )

if(OpenCV_FOUND)
    message ("OpenCV found")
else()
    message (FATAL_ERROR "Cannot find OpenCV")
endif()


target_include_directories(say-hello 
                            PRIVATE ${Boost_INCLUDE_DIR} 
                            PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(say-hello
                     PRIVATE Boost::headers
                     PRIVATE ${OpenCV_LIBS})


#optional openmp
find_package(OpenMP REQUIRED)
if(OpenMP_CXX_FOUND)
    message("OpenMP found")
    target_link_libraries(say-hello PUBLIC OpenMP::OpenMP_CXX)
endif()

#optional 
find_package(GLEW REQUIRED)
if (GLEW_FOUND)
  message("GLEW found")
  target_link_libraries(say-hello PRIVATE ${GLEW_LIBRARIES})
endif()

#using pkgconfig
find_package(PkgConfig REQUIRED)
if (PkgConfig_FOUND)
    message("PkgConfig found")
    pkg_search_module(GLFW REQUIRED glfw3)
    if(GLFW_FOUND)
        message("GLFW found")
        target_include_directories(say-hello PRIVATE ${GLFW_INCLUDE_DIRS})
    endif()
endif()









