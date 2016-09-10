//
// Created by zhenghu on 16-9-10.
//

#ifndef REACT_CURSES_GAMEOFLIFECOMPONENT_HH
#define REACT_CURSES_GAMEOFLIFECOMPONENT_HH

#include "GameOfLifeStateContainer.hh"



class GameOfLifeComponent : public Component<GameOfLifeProps, Nothing> {
 public:
  GameOfLifeComponent(GameOfLifeProps &props) {
    this->props = props;
  }
  virtual void render() {
    ::printw("[GameOfLifeComponent]: Rendering game! %p.\n", &props);
    int initX = 2, initY = 2;
    for (int i = 0; i < props.width; ++i) {
      for (int j = 0; j < props.height; ++j) {
        ::move(i, j);
        ::addch(props.get(i, j) ? '*' : ' ');
      }
    }
    ::printw("%d", props.dummy);
    move(5, 0);
    for (int i = 0; i < props.width; ++i) {
      for (int j = 0; j < props.height; ++j) {
        ::printw("Rendering %d, %d, %d!\n", i, j, props.get(i, j));
      }
    }
    ::refresh();
  }
};



#endif //REACT_CURSES_GAMEOFLIFECOMPONENT_HH
