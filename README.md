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
After that, there will be a static library named liblame2D.a in build/lib

To use lame2D in your own project just take the static library and include files from include/
and place them in your project

## Running examples
After running the commands in #Quick-start, the will be examples compiled in build/examples

## Notes

## Todo
- [ ] Timers
- [ ] Set window FPS
- [ ] Rendering textures
- [ ] Rendering diffrent shapes
- [ ] Compress input handling code in lame2D::Window
- [ ] Make an option in the build system to not compile examples
- [ ] Make an option in the build system to compile for debugging (-ggdb)and for release (-O3)
