cmake_minimum_required(VERSION 3.14)
project(rsa_cpp)

set(CMAKE_CXX_STANDARD 17)

# Найдём OpenSSL
find_package(OpenSSL REQUIRED)

# Подключаем GTest через FetchContent (автоматическая загрузка)
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip 
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Добавляем нашу библиотеку
add_library(rsa_lib STATIC src/rsa.cpp)
target_include_directories(rsa_lib PUBLIC include)
target_link_libraries(rsa_lib ${OPENSSL_LIBRARIES})

# Добавляем тесты
add_executable(rsa_tests test/rsa_test.cpp)
target_link_libraries(rsa_tests gtest_main gtest pthread rsa_lib ${OPENSSL_LIBRARIES})

enable_testing()
add_test(NAME RSA_Tests COMMAND rsa_tests)
