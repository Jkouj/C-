#include "maze.h"
#include <fstream>
#include <vector>
#include <string>

Maze::Maze(int rows, int columns, int seed, std::string file_name) {
    this->rows = rows;
    this->columns = columns;
    this->seed = seed;
    this->file_name = file_name;
    
    makeMaze();
    //completeMaze();
    writeFile();

}

void Maze::makeMaze(){
    
    for (int i = 0 ; i < this->rows ; i++){
        for (int j = 0 ; j < this->columns ; j++){
            this->maze[i][j] = 15;
            this->visited[i][j] = false;
        }
    }

    this->maze[0][0] = 7;
    this->maze[rows - 1][columns - 1] = 11;


}
/*
void Maze::completeMaze(){
    
    create empty dynamic array `A`
    
    mark cell [0,0] as visited
    insert cell [0,0] at the end of `A`
    while `A` is not empty
        `current` <- remove last element from `A`
        `neighbors` <- `current`'s neighbors not visited yet
        if `neighbors` is not empty
            insert `current` at the end of `A`
            `neigh` <- pick a random neighbor from `neighbors`
            remove the wall between `current` and `neigh`
            mark `neigh` as visited
            insert `neigh` at the end of `A`
        endif
    endwhile

}
*/

void Maze::writeFile(){
    std::ofstream output_file(this->file_name);
    for (int i = 0 ; i < this->rows ; i++){
        for (int j = 0 ; j < this->columns ; j++){
            output_file << this->maze[i][j] << " ";
        }
        output_file << "\n";
    }


}