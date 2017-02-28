# connect4 by Piotr Beling, beling@math.uni.lodz.pl
cmake_minimum_required (VERSION 2.6)
project(Connect4)
add_executable(connect4 main.cpp board.h board.cpp utils.h utils.cpp players.h players.cpp)
