#! /bin/sh

cmake -DCMAKE_BUILD_TYPE=Debug -S . -B out/build

cd out/build

make

gdb LeetCode
