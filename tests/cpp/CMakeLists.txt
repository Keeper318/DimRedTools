include(FetchContent)
# This module depend on having doctest installed
FetchContent_Declare(
  extern_doctest
  GIT_REPOSITORY https://github.com/onqtam/doctest.git
  GIT_TAG        v2.4.9
)

FetchContent_MakeAvailable(extern_doctest)

add_executable(run-tests ${CMAKE_CURRENT_SOURCE_DIR}/run-tests.cpp ${CMAKE_CURRENT_SOURCE_DIR}/testdata.cpp ${CMAKE_CURRENT_SOURCE_DIR}/test-dimredtools.cpp ${CMAKE_CURRENT_SOURCE_DIR}/test-trees.cpp ${CMAKE_CURRENT_SOURCE_DIR}/test-manifolds.cpp)
target_link_libraries(run-tests PRIVATE doctest::doctest DimRedTools::DRT)
