#pragma once
#include <iostream>
#include <vector>
#include <string>

class Maze {

private:
    int rows; //height
    int columns; //width
    int seed; //seed
    std::string file_name; //file name
    // int N = 8; //wall at top
    // int E = 2; //wall at right
    // int S = 4; //wall at bottom
    // int W = 1; //wall at left

    std::vector<std::vector<int> > maze;
    std::vector<std::vector<bool> > visited;
    //std::vector<std::pair<int,int> > A;

public:
    Maze(int seed, int rows, int columns, std::string file_name);

    void makeMaze();
    //void completeMaze();
    void writeFile();
};
