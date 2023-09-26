# MEC_project
Group project CSC 212 grade calculator

Joseph Koumjian, Allen Liu, Andrew Ou https://github.com/Jkouj/MEC_project

Grade Calculator Course grade is out of 1000 points + 30 extra credit points 10 labs (50 pts) 5 assignments (500 pts) 1 term project (350 pts) 1 final (100 pts) 1 review project (MEC) (30 pts)

Pseudocode: Grade class public: int total_sum; char final; std::vector grades; private: Function to ask for user input split up each grade category (lab/hw/project/etc) into its own function Everytime we get input, push it back to the vector Function to calculate grade Function to print grade

Ask user for input for all 18 grades Ask for labs first - each out of 5 points If your input is less than 0 or greater than 5, re-ask for input Ask for assignments next - out of 100/each If your input is less than 0 or greater than 100, ask again Ask for term project (350) If conditions - ask again Ask for final (100) If conditions - ask again Ask for MEC(30) If conditions - ask again Sum up all grade points Divide total by 1000 Multiply by 100 If final grade is 94 or greater, final = A If final grade is 90 - 93, final = A- If “ “ “ 87 - 89, final = B+ If “ “ “ 83 - 86, final = B If “ “ “ 80 - 82, final = B- If “ “ “ 77 - 79, final = C+ If “ “ “ 73 - 76, final = C If “ “ “ 70 - 72, final = C- If “ “ “ 67 - 69, final = D+ If “ “ “ 60 - 66, final = D If “ “ “ below 60, final = F Output final letter grade
