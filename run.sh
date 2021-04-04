#!/bin/bash
name=$(echo $1 | cut -f 1 -d . | cut -f 2 -d /)
clear
clang "src/$name.c" -o "build/$name" && "build/$name"
