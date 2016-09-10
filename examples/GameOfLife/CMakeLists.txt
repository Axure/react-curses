#target_include_directories(../../src/include)

add_executable(GameOfLife
        main.cpp
        GameOfLifeComponent.hh GameOfLifeStateContainer.hh)
target_link_libraries(GameOfLife ReactCurses)