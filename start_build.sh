#!/bin/bash
if [ -d ./build ]; then 
  cd build
else
  mkdir build
  cd build
  cmake ..
fi

# build 
cmake --build .
