@echo off
setlocal enabledelayedexpansion
set files=

for /r src %%i in (*.cpp) do (
    set files=!files! "%%i"
)

g++ -Wl,--stack,1000000000 -O3 main.cpp %files% -o sort.exe