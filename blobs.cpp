#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
 
void ReadFile(std::string file_name, std::vector<std::vector<int> > * grid){
    // Opens the file for reading
    std::ifstream file(file_name);
 
    // Creates a string to hold each line in temporarily
    std::string str;
   
    // Iterates over the file, storing one line at a time into `str`
    while (std::getline(file, str)) {
        // Create a temporary 1D Vector of doubles
       std::vector<int> new_row;
  
       // Create a stringstream object with our line of integers from the file
       std::istringstream ss(str);
  
       // Create a double that will hold our extracted value from the string
       int token;
  
        // While there are still numbers in this string, extract them as doubles
        while(ss >> token){
            // Push these doubles into our temp vector
            new_row.push_back(token);
        }
  
        // The line is empty, push our completed row into our 2D vector
        grid->push_back(new_row);
    }
 }
 
            //rows  //columns //Xcord//Ycord//CONNtype  //gridVector
int recurse(int M, int N, int Y, int X, int CONN, std::vector<std::vector<int> > &grid){
    int count = 0;
    
    // std::cout<<X<<","<<Y<<std::endl;
    // for (int i = 0 ; i < M ; i++){
    //     for(int j = 0 ; j < N ; j++){
    //         std::cout<<grid[i][j];
    //     }
    //     std::cout<<std::endl;
    // }
 
     //make sure the current coordinate is in the bounds of the grid
    if (X < 0 || Y < 0 || X > N-1 || Y > M-1){
        return 0;
    }
 
 
    //make sure the current coordinate is valid; != 0
    if (grid[X][Y] == 0){
        return 0;
    }
 
  
    //if the CONN value is 4, we check accordingly:
    if (CONN == 4){
        //set the current cell to 0 so it doesnt get checked again
        grid[X][Y] = 0;
  
        count = 1 +
                //check north
                recurse(M,N, Y, X-1, CONN, grid) +
             
                //check south
                recurse(M,N, Y, X+1, CONN, grid) +
  
                //check east
                recurse(M,N, Y+1, X, CONN, grid) +
               
                //check west
                recurse(M,N, Y-1, X, CONN, grid);
    }
  
    if (CONN == 8){
        //set the current cell to 0 so it doesnt get checked again
        grid[X][Y] = 0;
        count = 1 +
                //check north
                recurse(M,N, Y, X-1, CONN, grid) +
  
                //check northeast
                recurse(M,N, Y+1, X-1, CONN, grid) +
  
                //check east
                recurse(M,N, Y+1, X, CONN, grid) +
  
                //check southeast
                recurse(M,N, Y+1, X+1, CONN, grid) +
  
                //check south
                recurse(M,N, Y, X+1, CONN, grid) +
  
                //check southwest
                recurse(M,N, Y-1, X+1, CONN, grid) +
               
                //check west
                recurse(M,N, Y-1, X, CONN, grid) +
               
                //check northwest
                recurse(M,N, Y-1, X-1, CONN, grid);
    }
    return count;
 }
 
int blobs (int M, int N, int CONN, std::vector<std::vector<int> > &grid){
    //initialize a counter that is returned with the final answer
    int count = 0;

    //for loop that runs through every row (i) and column (j) in the grid
    //rows i
    for (int i = 0 ; i < M ; i++){
         //columns j
        for (int j = 0 ; j < N ; j++){
            //if the current coordinate = 1
            if (grid[j][i] == 1){
                //add one to count
                count++;
  
                //start recursively checking the space around it
                recurse(M,N,i,j, CONN, grid);
            }
        }
    }
    return count;
 }
  
int main (int argc, char*argv[]){
    
    //argv1 is the input file name
    std::string fname = argv[1];
   
    //argv2 is M the number of rows in the grid
    std::string rows = argv[2];
    int M = std::stoi(rows);
  
    //argv3 is N the number of columns in the grid
    //std::string columns = argv[3];
    int N = std::stoi(argv[3]);
  
    //argv 4 is CONN the connection type, can be 4 or 8
    std::string conn = argv[4];
    int CONN = std::stoi(conn);
 
     std::vector<std::vector<int> > grid;
    //read input file and write it to the grid vector
    ReadFile(fname, &grid);
 
    //call the function to recursively count through the grid
    //rows//columns//Xcord//Ycord//CONNtype//gridVector
    int final = blobs(M,N,CONN, grid);
    std::cout<<final<<std::endl;
}
