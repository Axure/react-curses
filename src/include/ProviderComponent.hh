//
// Created by zhenghu on 16-9-10.
//

#ifndef REACT_CURSES_PROVIDERCOMPONENT_HH
#define REACT_CURSES_PROVIDERCOMPONENT_HH

#include "Component.hh"

#include "StateContainer.hh"

#include <type_traits>

template<class StateContainerType>
class ProviderStates {
 public:
  ProviderStates(StateContainerType &stateContainer): stateContainer(stateContainer) {
    static_assert(std::is_base_of<StateContainerBase, StateContainerType>::value,
                  "The type must be a state container!");
  }
  StateContainerType stateContainer;
};

template<class StateContainerType, class ChildType>
class ProviderComponent: public Component<Nothing, typename StateContainerType::StateType> {
 public:
//  ProviderComponent(StateContainerType &stateContainer):
//      Component<Nothing, typename StateContainerType::StateType>
//          (std::forward<ProviderStates<StateContainerType>&&>(ProviderStates<StateContainerType>(stateContainer))) {
//  }
 public:
  void render() {
    ::printw("[ProviderComponent]: Rendering provider! %d\n", this->states.dummy);
    ChildType child(this->states);
    child.render();
    ::refresh();
  }
};


#endif //REACT_CURSES_PROVIDERCOMPONENT_HH
