# Configure Header File
configure_file("DRTConfig.hpp.in" "DRTConfig.hpp" @ONLY)

# Set the Source, Header Files
set(DIMREDTOOLS_SRC "${CMAKE_CURRENT_SOURCE_DIR}")
set(INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include")
set(DIMREDTOOLS_INCLUDE_DIR "${INCLUDE_DIR}/DimRedTools")
set(DIMREDTOOLS_SOURCE_FILES ${DIMREDTOOLS_SRC}/DimRedTools.cpp ${DIMREDTOOLS_SRC}/DRTConfig.cpp ${DIMREDTOOLS_SRC}/CoverTree.cpp ${DIMREDTOOLS_SRC}/CompressedCoverTree.cpp ${DIMREDTOOLS_SRC}/MDS.cpp ${DIMREDTOOLS_SRC}/Isomap.cpp)
set(DIMREDTOOLS_HEADER_FILES ${DIMREDTOOLS_INCLUDE_DIR}/DimRedTools.hpp ${DIMREDTOOLS_INCLUDE_DIR}/CoverTree.hpp ${DIMREDTOOLS_INCLUDE_DIR}/CompressedCoverTree.hpp ${DIMREDTOOLS_INCLUDE_DIR}/MDS.hpp ${DIMREDTOOLS_INCLUDE_DIR}/Isomap.hpp)

# Create the CPP Library
set(LIB_TYPE STATIC)
add_library(${PROJECT_NAME} ${LIB_TYPE} ${DIMREDTOOLS_SOURCE_FILES})
add_library(DimRedTools::DRT ALIAS ${PROJECT_NAME})

############# Start Build Options ###################

# Configure optimization
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(OPTIMIZATION_FLAGS "-O0 -DDEBUG")
    message("-- Configuring debug build")
else()
    set(OPTIMIZATION_FLAGS "-O3 -DNDEBUG")
    message("-- Configuring release build")
endif()

# Enable warnings, will set to compile with src/CMakeLists.txt
set(DESIRED_WARNINGS "-Wall -Wextra -Wconversion -Wunreachable-code -Wuninitialized -pedantic-errors -Wold-style-cast -Wno-error=unused-variable -Wshadow -Wfloat-equal -Weffc++")
set(MINIMAL_DESIRED_WARNINGS "-Wall -Wextra -pedantic-errors")
if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(DESIRED_WARNINGS "${DESIRED_WARNINGS} -Wmost")
endif()
separate_arguments(DESIRED_WARNINGS)
separate_arguments(MINIMAL_DESIRED_WARNINGS)

if (DRT_BUILD_WERROR)
    set(DESIRED_WARNINGS "${DESIRED_WARNINGS} -Werror")
    set(MINIMAL_DESIRED_WARNINGS "${MINIMAL_DESIRED_WARNINGS} -Werror")
endif()

# Set GLOBAL CMAKE_CXX_FLAGS
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OPTIMIZATION_FLAGS}")

############# End Build Options #####################

# Set Compile Options for ONLY this target.
target_compile_options(${PROJECT_NAME}  PRIVATE
$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
${DESIRED_WARNINGS}>
$<$<CXX_COMPILER_ID:MSVC>:
/W4>)


# To include the DRTConfig.hpp file
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

# OPTION Build with OpenMP Support
if (DRT_WITH_OPENMP)
  find_package(OpenMP)
  target_link_libraries(${PROJECT_NAME} PUBLIC OpenMP::OpenMP_CXX)
endif()

find_package(Eigen3 3.4 REQUIRED NO_MODULE)
target_link_libraries(${PROJECT_NAME} PUBLIC Eigen3::Eigen)

# Set Properties
set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER "${DIMREDTOOLS_HEADER_FILES}")
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION} POSITION_INDEPENDENT_CODE ON)
# Set Public and Private Include Directories
target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIR})
# TODO - This is something that I still do not fully understand, Build vs Install?
target_include_directories(${PROJECT_NAME} PUBLIC
$<BUILD_INTERFACE:${INCLUDE_DIR}>
$<INSTALL_INTERFACE:include>
PRIVATE src)
