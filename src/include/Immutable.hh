//
// Created by zhenghu on 16-9-10.
//

#ifndef REACT_CURSES_IMMUTABLE_HH
#define REACT_CURSES_IMMUTABLE_HH
#include <memory>

template <class ValueT>
class Immutable {
 private:
  std::shared_ptr<ValueT> valueT;
 public:

  Immutable(ValueT value) {
    this->valueT = std::make_shared<ValueT>(value);
  }

  bool operator=(Immutable &immutable) const & {
    this->valueT;
    return (&immutable) == this;
  }
};

#endif //REACT_CURSES_IMMUTABLE_HH
