# lame2D
 - Game library for 2D games, based on SDL2

## Prerequisites
 - SDL2 installed system wide
 - GNU Make

## Quick start
```bash
  git clone https://github.com/prodbysky/lame2D
  cd lame2D
  mkdir build
  cd build
  cmake ..
  make -j6
```
After that, there will be a static library named liblame2D.a in build/lib,
and some examples of this library in build/examples

To use lame2D in your own project just take the static library and include files from include/
and place them in your project

## Notes
 - Currently window startup takes 1sec which seems like way too much
