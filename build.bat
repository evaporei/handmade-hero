@echo off
if not exist build mkdir build
pushd build
clang ..\src\main.c -o main.exe -lkernel32 -luser32 -lgdi32
popd