#include <iostream>
#include <fstream> 
#include <string> 
#include <vector> 
#include <sstream>
#include <algorithm>
#include <cmath>


void ReadFile(std::string file_name, std::vector<std::vector<double> > * image_data){
    // Opens the file for reading
    std::ifstream file(file_name);

    // Creates a string to hold each line in temporarily
    std::string str;
    
    // Iterates over the file, storing one line at a time into `str`
    while (std::getline(file, str)) {
        // Create a temporary 1D Vector of doubles
       std::vector<double> new_row;

       // Create a stringstream object with our line of integers from the file
       std::istringstream ss(str);

       // Create a double that will hold our extracted value from the string
       double token;

        // While there are still numbers in this string, extract them as doubles
        while(ss >> token){
            // Push these doubles into our temp vector
            new_row.push_back(token);
        }

        // The line is empty, push our completed row into our 2D vector
        image_data->push_back(new_row);
    }
}


void writeFile(std::string outPutFile, std::vector<std::vector<double> > &image_data) {
    std::ofstream output_file(outPutFile);
    for (int i = 0 ; i < image_data.size() ; i++) {
        for (int j = 0 ; j < image_data[0].size() ; j++){
            output_file << image_data[i][j] << " ";
        }
        output_file << "\n";
    }
}


double getMedian(std::vector<std::vector<double> > &image_data){
    double median;
    int xAxis = image_data[0].size();
    int yAxis = image_data.size();
    std::vector<double> sorted_data;

    for (int i = 0 ; i < yAxis ; i++){
        for (int j = 0 ; j < xAxis ; j++){
            sorted_data.push_back(image_data[i][j]);
        }
    }
    std::sort(sorted_data.begin(), sorted_data.end());

    if (sorted_data.size() % 2 == 0){
        //is even
        median = sorted_data[sorted_data.size()/2];

    }
    else {
        median = ((sorted_data[sorted_data.size()/2]) + ((sorted_data[(sorted_data.size()/2)+1])))/2;

    }
    return median;
}


void global(std::vector<std::vector<double> > &image_data,
            std::vector<std::vector<double> > &global_data){
    double T = getMedian(image_data);
    for (int i = 0 ; i < image_data.size() ; i++) {
        for (int j = 0 ; j < image_data[0].size() ; j++){
            if (image_data[i][j] < T){
                global_data[i][j] = 0;
            }
            else{
                global_data[i][j] = 255;
            }
        }
    }
}

double getMean(std::vector<double> &neighbors){
    double sum = 0;
    for (int i = 0 ; i < neighbors.size() ; i++){
        sum = sum + neighbors[i];
    }
    double mean = sum / neighbors.size();

    return mean;
}

void localNeighbor(std::vector<std::vector<double> >  &image_data, int i, int j, int n, 
                   std::vector<double> &neighborhood){
    int height = image_data.size()-1;
    int width = image_data[0].size()-1;
    int offset = n/2;
    for (int p = i-offset ; p <= i+offset ; p++){
        for (int q = j-offset ; q <= j+offset ; q++){
            if (p < 0 || p > height || q < 0 || q > width){
                continue;
            }
            else{
                neighborhood.push_back(image_data[p][q]);
            }
        }
    }
}


double getThresh(std::vector<std::vector<double> > &image_data, std::vector<double> &neighbors, double R){
    double mean = getMean(neighbors);
    double sum = 0;
    for (int i = 0 ; i < neighbors.size() ; i++){
        sum += pow((neighbors[i] - mean),2);
    }
    double SDV = sqrt(sum/neighbors.size());
    double final = mean * (1.0 + 0.2 * ((SDV/R) - 1.0));
    return final;
}


void local(std::vector<std::vector<double> > &image_data,int n,
           std::vector<std::vector<double> > &local_data){
    double localT = 0;
    std::vector<double> sorted_data;
    for (int i = 0 ; i < image_data.size() ; i++){
        for (int j = 0 ; j < image_data[0].size() ; j++){
            sorted_data.push_back(image_data[i][j]);
        }
    }
    std::sort(sorted_data.begin(), sorted_data.end());
    double R = 0.5 * (sorted_data[sorted_data.size() - 1] - sorted_data[0]);


    for (int i = 0 ; i < image_data.size() ; i++){
        for (int j = 0 ; j < image_data[0].size() ; j++){
            std::vector<double> neighbors;
            localNeighbor(image_data, i,j,n, neighbors);
            localT = getThresh(image_data, neighbors, R);
            if (image_data[i][j] < localT){
                local_data[i][j] = 0;
            }
            else{
                local_data[i][j] = 255;
            }
        }
    }
}

int main(int argc, char*argv[]) {
    std::string gloORlo = argv[1]; 
    std::string fileName = argv[2]; 
    std::string newFileName = argv[3]; 
    gloORlo = "local";
    fileName = "3x3.img";
    newFileName = "test.txt";
    std::vector<std::vector<double> > sorted_data;
    std::vector<std::vector<double> > image_data; 
    ReadFile(fileName, &image_data);
    sorted_data = image_data;
    if (gloORlo == "global"){
        global(image_data, sorted_data);
        writeFile(newFileName, sorted_data);
    }
    else if (gloORlo == "local"){
        char *c = argv[4];
        int n = 0;
        sscanf(c, "%d", &n);
        n = 3;
        local(image_data, n, sorted_data);
        writeFile(newFileName, sorted_data);
    }
}