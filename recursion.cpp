#include <string>
#include <iostream>

// NAME: product
// INPUT: two unsigned integers
// OUTPUT: the product of the two unsigned integer
// DESCRIPTION: Returns the product of two non-negative integers, m and n, using only repeated addition.
int product(unsigned int m, unsigned int n)
{
    if (m == 1){ //if m is equal to 1, we have reached the last iteration
        return n;
    }
    else{
        int a = product(m-1, n); //call product with parameters m-1 and n
        return a + n; //return the sum of a and n
    }
}

// NAME: digitCount
// INPUT: an integer num, an integer digit
// OUTPUT: An integer corresponding to the number of occurences of digit
// DESCRIPTION: Returns the number of occurrences of digit in the decimal representation of num.
int digitCount(int num, int digit)
{
    if (num == 0 && digit == 0){ //base case
        return 1;
    }
    if (num >= 1000000000){ //since an int can only be as large as 2 billion, we make our top base case go up to 1 billion
        if (num / 1000000000 == digit){ //if the first digit in the integer is not equal to the digit
            int a = digitCount(num - (digit * 1000000000), digit); //lower the size of the number by exactly the value of the first digit in the integer
            return a+1; //increment a
        }
        else{
            
            int q = digitCount(num%1000000000, digit); //return the remainder of the num and 1 billion, as this will give us exactly the integer without the first digit
            return q;
        }
    }
    if (num >= 100000000){ //if the number has a value in the 100 millions
        if (num / 100000000 == digit){ //if the number divided by 100 million is the digit
            int a = digitCount(num - (digit * 100000000), digit); //lower the size of the number by exactly the value of the first digit in the integer
            return a+1; //increment a
        }
        else{
            
            int q = digitCount(num%100000000, digit); //return the remainder of the num and 100 million , as this will give us exactly the integer without the first digit
            return q;
        }
    }
    if (num >= 10000000){ //if the number has a value in the 10 millions
        if (num / 10000000 == digit){ //if the first digit in the integer is not equal to the digit
            int a = digitCount(num - (digit * 10000000), digit); //lower the size of the number by exactly the value of the first digit in the integer
            return a+1; //increment a
        }
        else{
            
            int q = digitCount(num%10000000, digit); //return the remainder of the num and 10 million , as this will give us exactly the integer without the first digit
            return q;
        }
    }
    if (num >= 1000000){ //if the number has a value in the 1 millions
        if (num / 1000000 == digit){ //if the first digit in the integer is not equal to the digit
            int a = digitCount(num - (digit * 1000000), digit); //lower the size of the number by exactly the value of the first digit in the integer
            return a+1; //increment a
        }
        else{
            
            int q = digitCount(num%1000000, digit); //return the remainder of the num and 1 million , as this will give us exactly the integer without the first digit
            return q;
        }
    }
    if (num >= 100000){ //if the number has a value in the 100 thousands
        if (num / 100000 == digit){ //if the first digit in the integer is not equal to the digit
            int a = digitCount(num - (digit * 100000), digit); //lower the size of the number by exactly the value of the first digit in the integer
            return a+1; //increment a
        }
        else{
            
            int q = digitCount(num%100000, digit); //return the remainder of the num and 100 thousand, as this will give us exactly the integer without the first digit
            return q;
        }
    }
    if (num >= 10000){ //if the number has a value in the 10 thousands
        if (num / 10000 == digit){ //if the first digit in the integer is not equal to the digit
            int a = digitCount(num - (digit * 10000), digit); //lower the size of the number by exactly the value of the first digit in the integer
            return a+1; //increment a
        }
        else{
            
            int q = digitCount(num%10000, digit); //return the remainder of the num and 10 thousand, as this will give us exactly the integer without the first digit
            return q;
        }
    }
    if (num >= 1000){ //if the number has a value in the 1 thousands
        if (num / 1000 == digit){ //if the first digit in the integer is not equal to the digit
            int a = digitCount(num - (digit * 1000), digit); //lower the size of the number by exactly the value of the first digit in the integer
            return a+1; //increment a
        }
        else{
            int q = digitCount(num % 1000, digit); //return the remainder of the num and 1 thousand, as this will give us exactly the integer without the first digit
            return q;
        }
    }
    if (num >= 100){ //if the number has a value in the 100's
           if (num / 100 == digit){ //if the first digit in the integer is not equal to the digit
               int a = digitCount(num - (digit * 100), digit); //lower the size of the number by exactly the value of the first digit in the integer
               return a+1; //increment a
           }
           else{
               int q = digitCount(num % 100, digit); //return the remainder of the num and 100, as this will give us exactly the integer without the first digit
               return q;
           }
       }
    if (num >= 10){ //if the number has a value in the 10's
           if (num / 10 == digit){ //if the first digit in the integer is not equal to the digit
               int a = digitCount(num - (digit * 10), digit); //lower the size of the number by exactly the value of the first digit in the integer
               return a+1; //increment a
           }
           else{
               int q = digitCount(num%10, digit); //return the remainder of the num and 10, as this will give us exactly the integer without the first digit
               return q;
           }
       }
    if (num >= digit){ //if num is greater than digit and/or it is in the ones value
        if (num == digit){ //if num is equal to digit
            int a = digitCount(num - (digit * 10), digit); //this checks in case the integer could be exactly 10x what we need
            return a+1; //increment a
        }
        else{
            int q = digitCount(num% 1, digit); //return the remainder of the num and 1, as this will give us exactly the integer without the first digit
            return q; //return q
        }
    }
    
    
    return 0; //there were no occurences of digit
}

// NAME: terribleTriplets
// INPUT: a string n
// OUTPUT: A string with 333 or the original string
// DESCRIPTION: str contains a single pair of square brackets, return a new string made of only the square brackets and whatever those square brackets contain
std::string terribleTriplets(std::string n)
{
    if (n.size() <= 1){ //if we've reached the end, then that means that there was no match
        return n.substr(0,1);
    }
    if (n.substr(0,1) == n.substr(1,1)){ //if this element and the immediate is a duplicate letter
        std::string b = terribleTriplets(n.substr(1,n.size()-1)); //call terribleTriplets with the next element in the string
        return
            n.substr(0,1) + "333" + b; //return this duplicate letter with 333 in the middle and b
    }
    std::string k = n.substr(0,1); //k is equal to this immediate char
    return k + terribleTriplets(n.substr(1, n.size()-1)); //go to the next char in the string
   
}



// NAME: hipToBeSquare
// INPUT: a string str
// OUTPUT: A string with square brackets or an empty string
// DESCRIPTION: Return true if the total of any combination of elements in the array a equals the value of the target.
std::string hipToBeSquare(std::string str)
{
    if (str.substr(str.size()-1,1) != "]"){ //if the last char in the string is not a ]
        return hipToBeSquare(str.substr(0,str.size() -1 )); //ignore this char and iterate
    }
    if (str.substr(0,1) != "["){ //if the immediate char in the string is not a [
        return hipToBeSquare(str.substr(1, str.size()-1)); //ignore this char and iterate
    }
    
    if (str.substr(0,1) == "["){ //if the immeiate element is a [
        return str.substr(0,str.size()); //add in this char
    }
    
    else{
        return "";
    
   
    }
    
}


// NAME: summerSolstice
// INPUT: a const array of integers, an integer size, an integer target
// OUTPUT: true if there exists a combination of elements that sum up to target, false otherwise
// DESCRIPTION: Return true if the total of any combination of elements in the array a equals the value of the target.
bool summerSolstice(const int a[], int size, int target)
{
    bool bool1 = false; //initialize 3 local booleans to false
    bool bool2 = false;
    bool bool3 = false;
    if (a[0] == target){ //if the immediate element is the target
        return true;
    }
    
    if (size <= 1 && target!=0){ //if the size is <=1 and the target is not 0
        return false;
    }
    
    bool1 = summerSolstice(a+1, size - 1, target); //search every element in the array
    bool2 = summerSolstice(a+1, size/2, target - a[0]); //search the first half of the array
    bool3 = summerSolstice(a+size/2, size - size/2, target - a[0]); //search the latter half of the array
    if (target == 0){ //empty set
        return true;
    }
    if (bool1 + bool2 + bool3 >=1) //if any of the three booleans returned true
        return true;
    else
        return false;
}


// NAME: isThisTheEnd
// INPUT: an array of strings, integer nRows, nCols, sr, sc, er, ec
// OUTPUT: true if there exists a solveable pathway to er, ec, false otherwise
// DESCRIPTION: Return true if there is a path from (sr,sc) to (er,ec) through the maze; return false otherwise
bool isThisTheEnd(std::string maze[], int nRows, int nCols, int sr, int sc, int er, int ec){
    if (sr == er && sc == ec){ //if the starting row and starting column is equal to the ending row and ending column
        return true;
    }
    if (maze[sr][sc] != '.'){ //if the starting row is not unvisited, or traversable
        return false;
    }
    maze[sr][sc] = '#'; //set the current location as seen
    
    if (isThisTheEnd(maze, nRows, nCols, sr-1, sc, er, ec)){ //search the maze with row - 1
        return true;
    }
    if (isThisTheEnd(maze, nRows, nCols, sr+1, sc, er, ec)){ //search the maze with row + 1
        return true;
    }
    if (isThisTheEnd(maze, nRows, nCols, sr, sc-1, er, ec)){ //search the maze with column - 1
        return true;
    }
    if (isThisTheEnd(maze, nRows, nCols, sr, sc+1, er ,ec)){ //search the maze with column + 1
        return true;
    }
    return false; //if none of the above returns true, then the path does not exist
}

