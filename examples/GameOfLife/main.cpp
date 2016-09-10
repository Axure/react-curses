//
// Created by zhenghu on 16-9-10.
//

#include <ncurses.h>

#include "Component.hh"
#include "StateContainer.hh"
#include "ProviderComponent.hh"
#include "./GameOfLifeComponent.hh"
#include "./GameOfLifeStateContainer.hh"
#include <unistd.h>
#include <thread>
#include <cstring>

int cellCount(GameOfLifeProps &gameOfLifeProps, int x, int y) {
  return (int)gameOfLifeProps.get(x, y + 1) +
      (int)gameOfLifeProps.get(x + 1, y + 1) +
      (int)gameOfLifeProps.get(x + 1, y) +
      (int)gameOfLifeProps.get(x - 1, y) +
      (int)gameOfLifeProps.get(x, y - 1) +
      (int)gameOfLifeProps.get(x - 1, y - 1) +
      (int)gameOfLifeProps.get(x + 1, y - 1) +
      (int)gameOfLifeProps.get(x - 1, y + 1);
}

int main(int argc, char *argv[]) {

  ::initscr();
  ::noecho();
  ::curs_set(FALSE);

  char mesg[] = "Just a string";
  int row, col;
  getmaxyx(stdscr, row, col);        /* get the number of rows and columns */
  mvprintw(row / 2, (col - strlen(mesg)) / 2, "%s", mesg);
  /* print the message at the center of the screen */
  mvprintw(row - 2, 0, "This screen has %d rows and %d columns\n", row, col);
  printw("Try resizing your window(if possible) and then run this program again");
  refresh();
//  ::mvprintw(0, 0, "Hello, world!");

  GameOfLifeProps gameOfLifeProps;
//  gameOfLifeComponent.render();
  GameOfLifeReducerType reducer = [](GameOfLifeProps &a, int actionType) {
    for (int i = 0; i < a.width; ++i) {
      for (int j = 0; j < a.height; ++j) {
        auto count = cellCount(a, i, j);
        if (count <= 1 || count >= 4) a.set(false, i, j);
        else if (count == 3) a.set(true, i, j);
      }
    }
    a.dummy += 1;
    return GameOfLifeProps(a);
  };
  GameOfLifeStateContainer stateContainer(reducer);

  ProviderComponent<GameOfLifeStateContainer,
                    GameOfLifeComponent> providerComponent;
  stateContainer.bindComponent(providerComponent);
  providerComponent.render();
  ::refresh();

  sleep(1);

  gameOfLifeProps.set(true, 1, 0);
  gameOfLifeProps.dummy = 101;
  ::printw("[main 1]: Setting state!\n");
  providerComponent.setState(gameOfLifeProps);
  ::printw("[main 1]: Done!\n");
  ::refresh();

  sleep(1);

  ::printw("[main 2]: Setting state!\n");
  gameOfLifeProps.set(true, 0, 0);
  gameOfLifeProps.dummy = 102;
  providerComponent.setState(gameOfLifeProps);
  ::printw("[main 2]: Done!\n");
  ::refresh();

  sleep(1);

  while (true) {
    stateContainer.dispatch(1);
    sleep(1);
  }

  ::endwin();
}