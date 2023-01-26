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

void findLowest(std::vector<std::vector<int> > *grid, std::vector<int> *low, int M, int N){
    //std::vector<int> result = {0,0,0};
    int lowPoint = (*grid)[0][0];

    for (int i = 0 ; i < M ; i++){
        for (int j = 0 ; j < N ; j++){
            if ((*grid)[i][j] < lowPoint){
                lowPoint = (*grid)[i][j];
                (*low)[0] = i;
                (*low)[1] = j;
            }
        }
    }
    (*low)[2] = lowPoint;
    //return result;
}

void findHighest(std::vector<std::vector<int> > *grid, std::vector<int> *high, int M, int N){
    //std::vector<int> result = {0,0,0};
    int highPoint = (*grid)[0][0];

    for (int i = 0 ; i < M ; i++){
        for (int j = 0 ; j < N ; j++){
            if ((*grid)[i][j] > highPoint){
                highPoint = (*grid)[i][j];
                (*high)[0] = i;
                (*high)[1] = j;
            }
        }
    }
    (*high)[2] = highPoint;
    //return result;
}

void makeVisited(std::vector<std::vector<bool>> *visited, int M, int N){
    for (int i = 0 ; i < M ; i++){
        std::vector<bool> temp;
        for (int j = 0 ; j < N ; j++){
            temp.push_back(false);
            }
            visited->push_back(temp);
        }
    }

void clearVisited(std::vector<std::vector<bool>> *visited){
    for (int i = 0 ; i < visited->size() ; i++){
        for (int j = 0 ; j < visited[0].size() ; j++){
            (*visited)[i][j] = 0;
        }
    }
}

bool inBounds(int row, int col, std::vector<std::vector<int>> *grid){
    bool result = true;

    if (row < 0 || col < 0 || row > grid->size()-1 || col > grid[0].size()-1){
        result = false;
    }

    return result;
}


bool findPath(int Hv, int Lv, int Lr, int Hr, int Lc, int Hc,
std::vector<std::vector<int>> *grid, std::vector<std::vector<bool>> *visited){
    bool YESNO = false;
    
    if (Lr == Hr && Lc == Hc){
        YESNO = true;
        return true;
    }

    if (YESNO == false){
        visited->at(Lr).at(Lc) = true;
        //(*visited)[Lr][Lc] = true;

        //checks up
        if (inBounds(Lr-1,Lc,grid) == true){
            if(visited->at(Lr-1).at(Lc) == false &&
            grid->at(Lr-1).at(Lc) >= grid->at(Lr).at(Lc)){
                //recursive call
                if (findPath(Hv, Lv, Lr-1, Hr, Lc, Hc, grid, visited)){
                    YESNO = true;
                    return true;
                }
                //clearVisited(visited);
            }
        }

        //checks left
        if (inBounds(Lr,Lc-1,grid) == true){
            if(visited->at(Lr).at(Lc-1) == false &&
            grid->at(Lr).at(Lc-1) >= grid->at(Lr).at(Lc)){
                //recursive call
                if (findPath(Hv, Lv, Lr, Hr, Lc-1, Hc, grid, visited)){
                    YESNO = true;
                    return true;
                }
                //clearVisited(visited);
            }
        }

        //checks down
        if (inBounds(Lr+1,Lc,grid) == true){
            if(visited->at(Lr+1).at(Lc) == false && grid->at(Lr+1).at(Lc) >= grid->at(Lr).at(Lc)){
                //recursive call
                if (findPath(Hv, Lv, Lr+1, Hr, Lc, Hc, grid, visited)){
                    YESNO = true;
                    return true;
                }
                //clearVisited(visited);
            }
        }

        //check right
        if (inBounds(Lr,Lc+1,grid) == true){
            if(visited->at(Lr).at(Lc+1) == false && grid->at(Lr).at(Lc+1) >= grid->at(Lr).at(Lc)){
                //recursive call
                if (findPath(Hv, Lv, Lr, Hr, Lc+1, Hc, grid, visited)){
                    YESNO = true;
                    return true;
                }
                //clearVisited(visited);
            }
        }
        //visited->at(Lr).at(Lc) = false;
    }
    
    return YESNO;
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

    //initialize and create grid vector from readfile function
    std::vector<std::vector<int>> grid;
    ReadFile(fname, &grid);

    //std::cout<<"hi"<<std::endl;
    
    //initialize and create visited vector from makeVisited function
    std::vector<std::vector<bool>> visited;
    makeVisited(&visited, M, N);
    //find lowest coordinates and value
    std::vector<int> low = {0,0,0};
    findLowest(&grid,&low,M,N);
    //find highest coordinates and value
    std::vector<int> high = {0,0,0};
    findHighest(&grid,&high,M,N);


    //declare these variables using values from the previous functions
    int Lr = low[0];
    int Lc = low[1];
    int Lv = low[2];
    int Hr = high[0];
    int Hc = high[1];
    int Hv = high[2];

    //check to see if there is a path
    bool YESNO = findPath(Hv, Lv, Lr, Hr, Lc, Hc, &grid, &visited);


    std::cout<<Lr+1<<" "<<Lc+1<<" "<<Hr+1<<" "<<Hc+1<<" ";

    if (YESNO == true){
        std::cout<<"yes"<<std::endl;
    }
    else {
        std::cout<<"no"<<std::endl;
    }

}