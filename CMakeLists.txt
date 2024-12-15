# CMakeList.txt: проект CMake для OS_Lab2; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project (OS_Lab2)

enable_testing()

add_subdirectory(Threads)
add_subdirectory(tests)
add_subdirectory(googletest)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (OS_Lab2 "main.cpp")

target_include_directories(OS_Lab2 PUBLIC include)
target_include_directories(Threads PUBLIC include)
target_link_libraries (OS_Lab2 PUBLIC Threads)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET OS_Lab2 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
