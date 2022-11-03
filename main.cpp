#include <iostream>
#include <vector>
#include <string>
#include "maze.h"

int main (int argc, char*argv[]){
    std::cout<< "hello";
    std::string Seed = argv[1];
    int seed = std::stoi(Seed);
    std::srand(seed);
    //argv1 is the seed which is a string turned into an int

    char *c = argv[2];
    int N = 0; //initializes N, becomes character c / 2nd arg
    sscanf(c,"%d",&N);
    //argv2 is rows N

    char *C = argv[3];
    int M = 0; //initializes M, becomes character C / 3rd arg
    sscanf(C,"%d",&M);
    //argv3 is columns M

    std::string file_name = argv[4];
    //argv4 is the name of the output file

    seed = 0;
    N = 4;
    M = 4;
    file_name = "mazeOut.txt";

    Maze newMaze = Maze(seed, N, M, file_name);

}


/*
int main (){
    int seed = 0;
    int N = 4;
    int M = 4;
    std::string file_name = "mazeOut.txt";

    Maze newMaze = Maze(seed, N, M, file_name);
}
*/