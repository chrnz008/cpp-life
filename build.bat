REM @echo off
set cxx=g++

set src=src/src.cpp
set out=game.exe
set libs=-lraylib -lopengl32 -lgdi32 -lwinmm
set cxxflags=-std=c++17 -O2

if "%1"=="run" (
	%out%
) else (
	if "%1"=="clean" (
		del %out%
	) else (
		%cxx% %cxxflags% %src% -o %out% %libs%
	)
)

REM build.bat to make
REM build.bat clean to make clean
REM build.bat run to make run
