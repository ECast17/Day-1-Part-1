#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const string numberAsStrings[10] = { "zero", "one","two","three", "four",
"five", "six", "seven", "eight", "nine" };
// This is a constant array of strings that contains the names of the numbers from zero to nine

int parseLine(string& toParse) // This is a function definition that takes a reference to a string as a parameter and returns an integer
{
	unsigned int nums[2] = { NULL, NULL };
	// This is a local array of unsigned integers that stores the two numbers to be parsed, initialized to NULL

	for (char& c : toParse) // This is a range-based for loop that iterates over each character in the string toParse
	{
		if (c >= 'a' && c <= 'z') // This is a conditional expression that converts any lowercase letter to uppercase by adding 32 to its ASCII value
		{
			c = c + 32;
		}
		else
		{
			c = c;
		}
	}

	for (int i = 0; i <= toParse.length(); i++) // This is a traditional for loop that iterates over each index in the string toParse
	{
		if (toParse[i] >= '0' && toParse[i] <= '9') // This is an if statement that checks if the current character is a digit
		{
			(nums[0] == NULL ? nums[0] = toParse[i] - 48 : nums[1] = toParse[i] - 48);
			// This is a ternary operator that assigns the digit to the first or second element of the nums array,
			//  depending on whether the first element is NULL or not. The digit is converted from a char to an int by subtracting 48 from its ASCII value
		}
		for (int j = 0; j < 10; j++) // This is another for loop that iterates over each element in the numberAsStrings array
		{
			if (toParse.substr(i, numberAsStrings[j].length()) == numberAsStrings[j]) // This is another if statement that checks if the current substring of toParse matches the current element of numberAsStrings
			{
				if (nums[0] == NULL)
				{
					nums[0] = toParse[i] - 48;
				} 
				else 
				{ 
					nums[1] = toParse[i] - 48;
				}
				// This is another ternary operator that assigns the index of the matching element to the first or second element of the nums array,
				//  depending on whether the first element is NULL or not
				// - 48 to get the char of the number 
			}
		}
	}
	if (nums[1] == NULL) 
	{ 
		return (nums[0] * 10) + nums[0]; 
	}
	else 
	{ 
		return (nums[0] * 10) + nums[1]; 
	}
	// This is a return statement that returns the sum of the two numbers in the nums array, multiplied by 10 and added together. If the second element is NULL, it means there was only one number, so the first element is used twice
}

int main()
{
	int outputSum = 0; // This is a local variable that stores the sum of all the numbers in the file, initialized to zero

	ifstream fs; // This is an object of the ifstream class that represents a file input stream

	fs.open("C:\\Users\\EricC\\OneDrive\\Advent Coding\\Day 1 text file.txt");

	string line; // This is another local variable that stores the current line of the file

	if (fs.is_open())
	{
		while (getline(fs, line)) // This is a while loop that reads each line of the file and stores it in the line variable
		{
			outputSum += parseLine(line);
			// This is an assignment statement that adds the result of calling the parseLine function with 
			// the line variable to the outputSum variable
		}
	}
	cout << outputSum; // This is an output statement that prints the outputSum variable to the standard output stream

	fs.close();
}