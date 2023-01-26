#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <cmath>

//this function takes num1 and num2 and evaluates them based on what OP is
//returns result: the double being updated
double solve(std::string OP, double num1, double num2){
    //initialize result
    double result = 0;
    //based on the given operator, we will calculate and update result with the new answer
    if(OP == "+"){
        result = num2 + num1;
    }
    else if(OP == "-"){
        result = num2 - num1;
    }
    else if(OP == "*"){
        result = num2 * num1;
    }
    else if(OP == "/"){
        result = floor(num2 / num1);
    }
    else if(OP == "^"){
        result = std::pow(num2,num1);
    }
    return result;
}

int main(int agrc, char* argv[]){
    //set user input equal to a string
    std::string input = argv[1];
    //initialize stack
    std::stack <double>stack;
    //streams the input string
    std::istringstream stream(input);
    //initialize operator
    std::string OP = "";
    //initialize num1 num2 and double Z
    double num1 = 0;
    double num2 = 0;
    double Z = 0;
        //start solving
        while (stream >> OP){
            //if it is a number push it onto the stack
            if((OP != "+" && OP != "-" && OP != "*" && OP != "/" && OP != "^")){
                stack.push(std::stoi(OP));
            }
            //if its not a number
            else {
                //based on the given operator we will
                //push it onto the stack
                //pop two numbers (operands) from the stack,
                //evaluate the operator on those numbers 
                //and push the result back to the stack
                if(OP == "+"){
                    num1 = stack.top();
                    stack.pop();
                    num2 = stack.top();
                    stack.pop();
                    Z = solve("+",num1,num2);
                    stack.push(Z);
                }
                else if(OP == "-"){
                    num1 = stack.top();
                    stack.pop();
                    num2 = stack.top();
                    stack.pop();
                    Z = solve("-", num1, num2);
                    stack.push(Z);
                }
                else if(OP == "*"){
                    num1 = stack.top();
                    stack.pop();
                    num2 = stack.top();
                    stack.pop();
                    Z = solve("*",num1, num2);
                    stack.push(Z);
                }
                else if(OP == "/"){
                    num1 = stack.top();
                    stack.pop();
                    num2 = stack.top();
                    stack.pop();
                    Z = solve("/",num1, num2);
                    stack.push(Z);
                }
                else if(OP == "^"){
                    num1 = stack.top();
                    stack.pop();
                    num2 = stack.top();
                    stack.pop();
                    Z = solve("^", num1, num2);
                    stack.push(Z);
                }
            }
        }
    //and then pop the number from the stack and return it
    std::cout<<stack.top()<<std::endl;
}