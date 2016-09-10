//
// Created by zhenghu on 16-9-10.
//

#ifndef REACT_CURSES_GAMEOFLIFESTATECONTAINER_HH
#define REACT_CURSES_GAMEOFLIFESTATECONTAINER_HH

#include "StateContainer.hh"
#include <array>
struct GameOfLifeProps {
  int width = 5, height = 5;
  int dummy = 100;
  bool *lives = new bool[25] {
      false, false, false, true, false,
      false, false, false, true, false,
      false, true, false, true, true,
      false, false, false, true, false,
  };
  bool set(bool value, int i, int j) {
    this->lives[i * width + j] = value;
  }
  bool get(int i, int j) {
    if (i < 0) return false;
    if (i > width) return false;
    if (j < 0) return false;
    if (j > height) return false;
    return this->lives[i * width + j];
  }
  bool operator!=(GameOfLifeProps &gameOfLifeProps) const {
    return true;
  }
  void operator=(GameOfLifeProps &gameOfLifeProps) {
    ::printw("[GameOfLifeProps]: Copy assigning!\n");
    this->width = gameOfLifeProps.width;
    this->height = gameOfLifeProps.height;
    this->dummy = gameOfLifeProps.dummy;
    if (this->lives != gameOfLifeProps.lives) {
      ::printw("[GameOfLifeProps]: lives pointer unequal!\n");
      delete this->lives;
      this->lives = gameOfLifeProps.lives;
    }
    ::refresh();
  }
};


class GameOfLifeStateContainer : public StateContainer<GameOfLifeProps> {
 public:
  GameOfLifeStateContainer(ReducerType<GameOfLifeProps> &reducer) : StateContainer(reducer) {}

};
using GameOfLifeReducerType = ReducerType<GameOfLifeProps>;

#endif //REACT_CURSES_GAMEOFLIFESTATECONTAINER_HH
