include(FetchContent)
FetchContent_Declare(
googletest
GIT_REPOSITORY https://github.com/google/googletest.git
GIT_TAG v1.15.2
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

add_executable(test_my_library test_expression.cpp)
target_link_libraries(test_my_library gtest_main)
target_include_directories(test_my_library PRIVATE ../homework)
gtest_discover_tests(test_my_library)



