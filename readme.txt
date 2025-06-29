1. Install the latest version of MinGW-w64 via MSYS2: https://code.visualstudio.com/docs/cpp/config-mingw
 
Actual SDL version use: https://github.com/libsdl-org/SDL/releases/download/release-2.32.8/SDL2-devel-2.32.8-mingw.zip

To build use this command: g++ -Llib -o game  main.cpp -lSDL2
To run use this command: ./game

To build and run automatically:
powershell: ./run 
bash: ./run.bash  