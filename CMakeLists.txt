cmake_minimum_required(VERSION 3.27)
project(pea_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(pea_2 main.cpp
        Queue.h
        Stack.h
        PriorityQueue.h
        TSP.cpp
        TSP.h
        TSPSolver.cpp
        TSPSolver.h
        ConfigLoader.cpp
        ConfigLoader.h
        Tester.cpp
        Tester.h)
