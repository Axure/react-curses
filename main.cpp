
//namespace ncurses {
#include <ncurses.h>
//}

#include "Component.hh"
#include <unistd.h>
int main(int argc, char *argv[]) {

  ::initscr();
  ::noecho();
  ::curs_set(FALSE);

//  ::mvprintw(0, 0, "Hello, world!");

  ExampleProps exampleProps;
  exampleProps.title = "Hello";
  ExampleComponent exampleComponent(exampleProps);
  exampleComponent.render();

  ::refresh();
  sleep(1);

//  ::endwin();
}