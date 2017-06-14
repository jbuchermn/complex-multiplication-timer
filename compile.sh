#!/bin/bash
g++ main.cpp -lstdc++        -o main_O0
g++ main.cpp -lstdc++ -O1    -o main_O1
g++ main.cpp -lstdc++ -O2    -o main_O2
g++ main.cpp -lstdc++ -O3    -o main_O3
g++ main.cpp -lstdc++ -Ofast -o main_Ofast
