cmake_minimum_required(VERSION 3.14)
project(Spectrogram)

# add_executable(testSpe)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)


include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
    TestSpectrogram
    test/TestSpectrogram.cpp
)
target_link_libraries(
    TestSpectrogram
    GTest::gtest_main
)

target_compile_options(
  TestSpectrogram
  PUBLIC -fsanitize=address -O1 -fno-omit-frame-pointer -g
)

include(GoogleTest)
gtest_discover_tests(TestSpectrogram)

include_directories(/Users/tomburnip/Library/CloudStorage/OneDrive-Personal/Uni\ Stuff/Level\ 5/RTEP/SynaesthetiQLEDLibrary/src/SynaesthetiQ)