cmake_minimum_required(VERSION 3.27.6)
project(bitlib)

# Подключаем Google Test
add_subdirectory(../extern)

# Ваши исходные файлы и заголовочные файлы
set(SOURCE_FILES 
    ../bitlib.cpp
)

set(HEADER_FILES 
    ../bitlib.h
)

# Тестовые файлы
set(TEST_SOURCE_FILES 
    test_bitlib.cpp
)

# Создаем исполняемый файл с тестами
add_executable(test_bitlib ${SOURCE_FILES} ${HEADER_FILES} ${TEST_SOURCE_FILES})

# Линкуем с Google Test
target_link_libraries(test_bitlib gtest gtest_main)

# Добавляем include директории
target_include_directories(test_bitlib PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/include 
    ${CMAKE_CURRENT_SOURCE_DIR}../extern/googletest/include
)

# Подготовка к запуску тестов
add_test(NAME test_bitlib COMMAND test_bitlib)
