cmake_minimum_required(VERSION 3.22)
project(dataStructureInC C)

set(CMAKE_C_STANDARD 11)

add_executable(dataStructureInC main.c libs/SequenceList.h libs/ElementType.h libs/SequenceList.c libs/ElementType.c libs/LinkedList.h libs/LinkedList.c)
