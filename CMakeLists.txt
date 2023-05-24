cmake_minimum_required(VERSION 3.23)
project(Wet1)

set(CMAKE_CXX_STANDARD 14)



add_executable( BinaryTree.h Node.h main.cpp User.h
        streaming_database.h streaming_database.cpp
        Movie.h User.h Group.h wet1util.h
        Movie.cpp User.cpp Group.cpp)
