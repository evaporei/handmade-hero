@echo off
if not exist build mkdir build
pushd build
clang ..\src\main.c -lkernel32 -luser32 -lgdi32 -o main.exe
popd