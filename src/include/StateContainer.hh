//
// Created by zhenghu on 16-9-10.
//

#ifndef REACT_CURSES_STATECONTAINER_HH
#define REACT_CURSES_STATECONTAINER_HH
#include <functional>
#include "Component.hh"

class StateContainerBase {};

template<class StateType>
using ReducerType = std::function<StateType(StateType &, int)>;

template<class StateType_>
class StateContainer: public StateContainerBase {
 public:
  using StateType = StateType_;
  StateType_ state;
 private:
  ComponentWithStates<StateType_> *pComponent = nullptr;
  ReducerType<StateType_> reducer;
 public:
  StateContainer(ReducerType<StateType_> &reducer) : reducer(reducer) {
  }
 public:
  virtual void dispatch(int actionType) {
    auto newState = reducer(state, actionType);
    if (newState != state) {
      state = newState;
      subscribe();
    }
  };
 public:
  template<class Any>
  void bindComponent(Component<Any, StateType_> &component) {
    pComponent = &component;
  }
  /**
   * Works on change.
   * Is an event listener.
   *
   * For use with the UI library, you have to capture the reference to the root object,
   * and setState in this function.
   *
   * This registers a callback in the event loop.???
   */
  virtual void subscribe() {
    if (pComponent != nullptr) {
      pComponent->setState(state);
    }
  }
};

class Mutation {

};

#endif //REACT_CURSES_STATECONTAINER_HH
