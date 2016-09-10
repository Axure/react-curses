cmake_minimum_required(VERSION 3.0)
project(react_curses)

set(CURSES_NEED_NCURSES TRUE)
find_package(Curses REQUIRED)

include_directories(${CURSES_INCLUDE_DIR} src/include)

set(SOURCE_FILES main.cpp)
add_executable(react_curses ${SOURCE_FILES} src/include/Component.hh src/include/StateContainer.hh)
target_link_libraries(react_curses ${CURSES_LIBRARY})

set_target_properties(react_curses PROPERTIES CXX_STANDARD 14)

add_library(ReactCurses src/include/Component.hh src/include/StateContainer.hh src/lib.cpp src/include/ProviderComponent.hh src/include/Immutable.hh)
target_link_libraries(ReactCurses ${CURSES_LIBRARY})

add_subdirectory(examples)