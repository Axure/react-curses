# React Curses

(WIP, with bugs and mis-design)

This is a port (in the manner of ideas) of react.js and redux to C++ with the backend support of ncurses.

## Introduction

The project attempts to simulate the nature of the "flux" architecture, in a totally "static" manner in C++, by heavy use of templates.

## Build

- Make sure you have an `ncurses` installation that can be found by CMake.
- Make sure your compiler supports at least C++14.

```
mkdir build
cmake ..
make
```

The built executable of the very first example is located at `build/examples/GameOfLife/`.

## Discussions

Current only exist in my brain. Coming soon.

## License

GNU/GPL v2