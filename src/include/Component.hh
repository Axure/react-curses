//
// Created by zhenghu on 16-9-8.
//

#ifndef REACT_CURSES_COMPONENT_HH
#define REACT_CURSES_COMPONENT_HH
#include <string>
//namespace ncurses {
#include <ncurses.h>
//}
class ComponentBase {
 public:
  virtual void render() = 0;
//  virtual void setState(void* state) = 0;
};

struct Nothing {
  bool operator!=(Nothing &nothing) const {
    return false;
  }

  bool operator!=(Nothing &&nothing) const {
    return false;
  }
};

template<class Props>
class ComponentWithProps: public virtual ComponentBase {
 protected:
  Props props;
 public:
  ComponentWithProps() {

  }

  ComponentWithProps(Props &props) : props(std::forward<Props&&>(props)) {

  }

  ComponentWithProps(Props &&props) : props(std::forward<Props&&>(props)) {

  }
  virtual void render() = 0;
};

template<class States>
class ComponentWithStates: public virtual ComponentBase  {
 protected:
  States states;
 public:
  virtual void render() = 0;
  virtual void setState(States &state) {
    ::printw("[Component]: Setting state in Component!\n");
    if (this->states != state) {
//      ::printw("[Component]: State unequal, reassigning! Before dummy: %d\n", ((GameOfLifeProps*)(&(this->states)))->dummy);
      this->states = state;
//      ::printw("[Component]: State unequal, rerendering! After dummy: %d\n", ((GameOfLifeProps*)(&(this->states)))->dummy);
      render();
    }
  }
};

template<class Props, class States>
class Component: public ComponentWithProps<Props>, public ComponentWithStates<States> {
 public:
  Component() {

  }
  Component(Props &props) : ComponentWithProps<Props>(std::forward<Props&&>(props)) {

  }

  Component(Props &&props) : ComponentWithProps<Props>(std::forward<Props&&>(props)) {

  }
 public:
  virtual void render() = 0;
};

struct ExampleProps {
  std::string title;
};

class ExampleComponent: public Component<ExampleProps, Nothing> {

 public:
  ExampleComponent(ExampleProps &props) {
    this->props = props;
  }
  virtual void render() {
    printf("%s", props.title.c_str());
    ::mvprintw(0, 0, props.title.c_str());
    ::refresh();
  }
};

#endif //REACT_CURSES_COMPONENT_HH
