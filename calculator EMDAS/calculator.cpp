// calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// To do in the future:
// - Pre format the inputted string
// - account for P (parenthesis)

#define _CRT_SECURE_NO_WARNINGS
#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

void evaluate_E(char* input, char* output);
void evaluate_MD(char* input, char* output);
void evaluate_AS(char* input, char* output);

int intToChar(int num, char* arr);
int get_LeftNum(char* input, int* optrIndex, char* storeDigits, int* endOfLeft);
int get_RightNum(char* input, int* optrIndex, char* storeDigits, int* endOfRight);
void create_newLeftSide(int* optrIndex, char* output, char* input, char* charsOfInt, int* endOfLeft, int* endOfInt_copy);
void create_newRightSide(int* someIndex, int* endOfLeft, int* endOfInt, char* input, char* output);
void putBackNewStr(char* input, char* output);

int main()
{
	char str[100] = {};
	char str1[100] = {};
	//int leftIndex = 0;
	//int rightIndex = 0;

	

	printf("%d is size of char array\n", sizeof(str));
	scanf("%s", str);
	printf("Address of str: %p\n", str);
	printf("%s is the entire string\n", str);


	evaluate_E(str, str1);
	printf("\nAfter evaluate_E str: ");
	for (int i = 0; str[i] != '\0'; i++)
	{
		printf("%c", str[i]);
	}
	printf("\n");

	evaluate_MD(str, str1);
	printf("\nAfter evaluate_MD str: ");
	for (int i = 0; str[i] != '\0'; i++)
	{
		printf("%c", str[i]);
	}
	printf("\n");

	evaluate_AS(str, str1);
	printf("\nAfter evaluate_AS str: ");
	for (int i = 0; str[i] != '\0'; i++)
	{
		printf("%c", str[i]);
	}
	printf("\n");


	return 0;
}

void evaluate_E(char* input, char* output)
{
	int optrIndex = 0;
	int endOfLeft = 0;
	int endOfRight = 0;

	char storeDigits[11] = {}; //store the digits for each math operation
	int someIndex = 0; //Not needed? needs to be reset to 0 after each use
	int newStrEnd = 0; //reset after each use?

	int leftNum, rightNum = 0;
	int finalResult = 0; //to store the result after performing math operator, need to reset after each use
	//char output[100] = {}; //the new string each time a math operator is performed

	char charsOfInt[10];
	int endOfInt, endOfInt_copy;

	//bool optrExists = false;
	//Loop through the input. If it doesn't encounter a non digit, then it just loops through and does nothing.
	for (int i = 0; input[i] != '\0'; i++)
	{
		printf("INDEX IS %d, CURRRENTLY AT: %c\n", i, input[i]);

		/*
		Decision making - You have to check the whole string before moving onto the next math operator
		*/
		if (input[i] == '^') //---CHANGE FOR EACH MATH OPERATION
		{
			//optrExists = true;
			
			optrIndex = i;//store index of operator
			printf("ADDRESS OF input: %p\n", input);
			printf("optrIndex: %d, ", optrIndex);

			leftNum = get_LeftNum(input, &optrIndex, storeDigits, &endOfLeft);
			//END OF GETTING LEFT NUMBER, BEGIN GETTING RIGHT NUMBER

			rightNum = get_RightNum(input, &optrIndex, storeDigits, &endOfRight);
			//END OF GETTING RIGHT NUM

			finalResult = pow(leftNum, rightNum); //---CHANGE FOR EACH MATH OPERATION
			printf("finalResult from ^ is: %d\n", finalResult); //---CHANGE FOR EACH MATH OPERATION

			//Convert finalResult from int to char
			endOfInt = intToChar(finalResult, charsOfInt); //endOfInt is the last index of the int
			endOfInt_copy = endOfInt;
			printf("endOfInt:%d\nConverted int to char: ", endOfInt);
			for (int i = endOfInt; i >= 0; i--)
			{
				//printf("i is: %d, %c\n", i, charsOfInt[i]);
				printf("%c", charsOfInt[i]);
			}
			printf("\nEND OF intToChar\n");
			//END OF MATH OPERATOR, BEGIN NEW STRING

			printf("After finalResult, endOfLeft is: %d, %c\n", endOfLeft, input[endOfLeft]);
			printf("\nSTARTING create_newLeftSide\n");
			printf("From beginning to optrIndex %d, output:", optrIndex);

			create_newLeftSide(&optrIndex, output, input, charsOfInt, &endOfLeft, &endOfInt_copy);

			//END OF CREATING LEFT SIDE OF NEW STRING
			printf("\n endOfInt: %d\n", endOfInt);
			printf("output 2ndPart: ");
			someIndex = endOfRight;
			printf("someIndex = endOfRight -> [%d], input[%d] = %c ", endOfRight, endOfRight, input[endOfRight]);
			printf("\nSTARTING create_newRightSide\n");

			create_newRightSide(&someIndex, &endOfLeft, &endOfInt, input, output);

			//END OF CREATING RIGHT SIDE OF NEW STRING

			//printf("\nMark the end of output -> newStrEnd + 1: %d", newStrEnd + 1);
			someIndex = 0; //reset after use
			printf("\n");
			
			//Put new string back into original array
			putBackNewStr(input, output);

			//4. No need to point to newly created string
			//Once the output is made, set inputPtr to output to loop through output
			//printf("\nBefore setting input = output, input: %p and output: %p\n", input, output);
			//input = output;
			//printf("input set to output\nADDRESS OF input: %p\n", input);

			optrIndex = 0; //reset
			newStrEnd = 0; //reset
			i = -1; //reset the for loop index counter to 0 to process the string from the beginning
			printf("optrIndex: %d\n", optrIndex);
			printf("Final output:");

			for (int i = 0; input[i] != '\0'; i++)
			{
				printf("%c", input[i]);
			}
			printf("\n");
			printf("END OF PROCESSING AN OPERATOR\n\n\n");
		}//End of if(isdigit...)

	}//End of for loop

	// if(optrExists)
	// 	return true;
	// else
	// 	return false;


}

void evaluate_MD(char* input, char* output)
{
	int optrIndex = 0;
	int endOfLeft = 0;
	int endOfRight = 0;

	char storeDigits[11] = {}; //store the digits for each math operation
	int someIndex = 0; //Not needed? needs to be reset to 0 after each use
	int newStrEnd = 0; //reset after each use?

	int leftNum, rightNum = 0;
	int finalResult = 0; //to store the result after performing math operator, need to reset after each use
	//char output[100] = {}; //the new string each time a math operator is performed

	char charsOfInt[10];
	int endOfInt, endOfInt_copy;

	//Loop through the input. If it doesn't encounter a non digit, then it just loops through and does nothing.
	for (int i = 0; input[i] != '\0'; i++)
	{
		printf("INDEX IS %d, CURRRENTLY AT: %c\n", i, input[i]);

		/*
		Decision making - You have to check the whole string before moving onto the next math operator
		*/
		if ((input[i] == '*') || (input[i] == '/')) //---CHANGE FOR EACH MATH OPERATION
		{
			optrIndex = i;//store index of operator
			printf("ADDRESS OF input: %p\n", input);
			printf("optrIndex: %d, ", optrIndex);

			leftNum = get_LeftNum(input, &optrIndex, storeDigits, &endOfLeft);
			//END OF GETTING LEFT NUMBER, BEGIN GETTING RIGHT NUMBER

			rightNum = get_RightNum(input, &optrIndex, storeDigits, &endOfRight);
			//END OF GETTING RIGHT NUM

			if(input[i] == '*')
			{
				finalResult = leftNum * rightNum; //---CHANGE FOR EACH MATH OPERATION
				printf("finalResult from * is: %d\n", finalResult); //---CHANGE FOR EACH MATH OPERATION
			}
			else if(input[i] == '/')
			{
				finalResult = leftNum / rightNum; //---CHANGE FOR EACH MATH OPERATION
				printf("finalResult from / is: %d\n", finalResult); //---CHANGE FOR EACH MATH OPERATION
			}
				

			//Convert finalResult from int to char
			endOfInt = intToChar(finalResult, charsOfInt); //endOfInt is the last index of the int
			endOfInt_copy = endOfInt;
			printf("endOfInt:%d\nConverted int to char: ", endOfInt);
			for (int i = endOfInt; i >= 0; i--)
			{
				//printf("i is: %d, %c\n", i, charsOfInt[i]);
				printf("%c", charsOfInt[i]);
			}
			printf("\nEND OF intToChar\n");
			//END OF MATH OPERATOR, BEGIN NEW STRING

			printf("After finalResult, endOfLeft is: %d, %c\n", endOfLeft, input[endOfLeft]);
			printf("\nSTARTING create_newLeftSide\n");
			printf("From beginning to optrIndex %d, output:", optrIndex);

			create_newLeftSide(&optrIndex, output, input, charsOfInt, &endOfLeft, &endOfInt_copy);

			//END OF CREATING LEFT SIDE OF NEW STRING
			printf("\n endOfInt: %d\n", endOfInt);
			printf("output 2ndPart: ");
			someIndex = endOfRight;
			printf("someIndex = endOfRight -> [%d], input[%d] = %c ", endOfRight, endOfRight, input[endOfRight]);
			printf("\nSTARTING create_newRightSide\n");

			create_newRightSide(&someIndex, &endOfLeft, &endOfInt, input, output);

			//END OF CREATING RIGHT SIDE OF NEW STRING

			//printf("\nMark the end of output -> newStrEnd + 1: %d", newStrEnd + 1);
			someIndex = 0; //reset after use
			printf("\n");

			//Put new string back into original array
			putBackNewStr(input, output);

			//4. No need to point to newly created string
			//Once the output is made, set inputPtr to output to loop through output
			//printf("\nBefore setting input = output, input: %p and output: %p\n", input, output);
			//input = output;
			//printf("input set to output\nADDRESS OF input: %p\n", input);

			optrIndex = 0; //reset
			newStrEnd = 0; //reset
			i = -1; //reset the for loop index counter to 0 to process the string from the beginning
			printf("optrIndex: %d\n", optrIndex);
			printf("Final output, printing out input:");

			for (int i = 0; input[i] != '\0'; i++)
			{
				printf("%c", input[i]);
			}
			printf("\n");
			printf("END OF PROCESSING AN OPERATOR\n\n\n");
		}//End of if(isdigit...)

	}//End of for loop


}

void evaluate_AS(char* input, char* output)
{
	int optrIndex = 0;
	int endOfLeft = 0;
	int endOfRight = 0;

	char storeDigits[11] = {}; //store the digits for each math operation
	int someIndex = 0; //Not needed? needs to be reset to 0 after each use
	int newStrEnd = 0; //reset after each use?

	int leftNum, rightNum = 0;
	int finalResult = 0; //to store the result after performing math operator, need to reset after each use
	//char output[100] = {}; //the new string each time a math operator is performed

	char charsOfInt[10];
	int endOfInt, endOfInt_copy;

	//Loop through the input. If it doesn't encounter a non digit, then it just loops through and does nothing.
	for (int i = 0; input[i] != '\0'; i++)
	{
		printf("INDEX IS %d, CURRRENTLY AT: %c\n", i, input[i]);

		/*
		Decision making - You have to check the whole string before moving onto the next math operator
		*/
		if ((input[i] == '+') || (input[i] == '-')) //---CHANGE FOR EACH MATH OPERATION
		{
			optrIndex = i;//store index of operator
			printf("ADDRESS OF input: %p\n", input);
			printf("optrIndex: %d, ", optrIndex);

			leftNum = get_LeftNum(input, &optrIndex, storeDigits, &endOfLeft);
			//END OF GETTING LEFT NUMBER, BEGIN GETTING RIGHT NUMBER

			rightNum = get_RightNum(input, &optrIndex, storeDigits, &endOfRight);
			//END OF GETTING RIGHT NUM

			if(input[i] == '+')
			{
				finalResult = leftNum + rightNum; //---CHANGE FOR EACH MATH OPERATION
				printf("finalResult from + is: %d\n", finalResult); //---CHANGE FOR EACH MATH OPERATION
			}
			else if(input[i] == '-')
			{
				finalResult = leftNum - rightNum; //---CHANGE FOR EACH MATH OPERATION
				printf("finalResult from - is: %d\n", finalResult); //---CHANGE FOR EACH MATH OPERATION
			}

			//Convert finalResult from int to char
			endOfInt = intToChar(finalResult, charsOfInt); //endOfInt is the last index of the int
			endOfInt_copy = endOfInt;
			printf("endOfInt:%d\nConverted int to char: ", endOfInt);
			for (int i = endOfInt; i >= 0; i--)
			{
				//printf("i is: %d, %c\n", i, charsOfInt[i]);
				printf("%c", charsOfInt[i]);
			}
			printf("\nEND OF intToChar\n");
			//END OF MATH OPERATOR, BEGIN NEW STRING

			printf("After finalResult, endOfLeft is: %d, %c\n", endOfLeft, input[endOfLeft]);
			printf("\nSTARTING create_newLeftSide\n");
			printf("From beginning to optrIndex %d, output:", optrIndex);

			create_newLeftSide(&optrIndex, output, input, charsOfInt, &endOfLeft, &endOfInt_copy);

			//END OF CREATING LEFT SIDE OF NEW STRING
			printf("\n endOfInt: %d\n", endOfInt);
			printf("output 2ndPart: ");
			someIndex = endOfRight;
			printf("someIndex = endOfRight -> [%d], input[%d] = %c ", endOfRight, endOfRight, input[endOfRight]);
			printf("\nSTARTING create_newRightSide\n");

			create_newRightSide(&someIndex, &endOfLeft, &endOfInt, input, output);

			//END OF CREATING RIGHT SIDE OF NEW STRING

			//printf("\nMark the end of output -> newStrEnd + 1: %d", newStrEnd + 1);
			someIndex = 0; //reset after use
			printf("\n");

			//Put new string back into original array
			putBackNewStr(input, output);

			//4. No need to point to newly created string
			//Once the output is made, set inputPtr to output to loop through output
			//printf("\nBefore setting input = output, input: %p and output: %p\n", input, output);
			//input = output;
			//printf("input set to output\nADDRESS OF input: %p\n", input);
			
			optrIndex = 0; //reset
			newStrEnd = 0; //reset
			i = -1; //reset the for loop index counter to 0 to process the string from the beginning
			printf("optrIndex: %d\n", optrIndex);
			printf("Final output:");

			for (int i = 0; input[i] != '\0'; i++)
			{
				printf("%c", input[i]);
			}
			printf("\n");
			printf("END OF PROCESSING AN OPERATOR\n\n\n");
		}//End of if(isdigit...)

	}//End of for loop


}

int get_LeftNum(char* input, int* optrIndex, char* storeDigits, int* endOfLeft)
{
	int someIndex = 0;
	int leftNum = 0;
	
	printf("\nIN get_LeftNum\n");
	//Goes back the number of steps taken to reach an operator from the index of the operator
	for (int goLeft = *optrIndex - 1; isdigit(input[goLeft]); goLeft--)
	{
		//printf("IN get_LeftNum FOR LOOP\n");
		//printf("goLeft: %d\n", goLeft);
		
		//NEW EDIT
		if (goLeft == 0)
		{
			*endOfLeft = goLeft;
			break;
		}

		if (!(isdigit((input[goLeft - 1]))))
			*endOfLeft = goLeft; //endOfLeft is the index of the digit right before the non digit as you go left
			//*endOfLeft = goLeft - 1; //endOfLeft is the index of the non digit that it hits
		//printf("END get_LeftNum FOR LOOP\n");

	}
	printf("endOfLeft: %d, %c\n", *endOfLeft, input[*endOfLeft]);

	//Goes from the endOfLeft index until it hits an operator (optrIndex) and stores each digit
	printf("Left #, storeDigits: ");
	//for (int goRight = *endOfLeft + 1; isdigit(input[goRight]); goRight++)
	for (int goRight = *endOfLeft; isdigit(input[goRight]); goRight++)
	{
		//NEW EDIT
		//if (goRight == 1)
		if (goRight == 0)
		{
			//printf("\ngoRight: %d\n", goRight);
			//storeDigits[someIndex] = input[goRight - 1];
			storeDigits[someIndex] = input[goRight];
			printf("%c", storeDigits[someIndex]);
			someIndex++;
			continue;
			//printf("\n For input[goRight], input[%d]: %c\n", goRight, input[goRight]);
			/*if (isdigit(input[goRight]))
			{
				printf("\ninput[%d] is a digit\n", goRight);
			}*/
			//printf("\nBEFORE goRight++, goRight: %d", goRight);
			//goRight++;
			//continue;
			//After this goRight = 2 and since input[2] = '+' then for loop ends
		}

		//printf("\nAfter goRight == 1, goRight: %d\n", goRight);

		storeDigits[someIndex] = input[goRight];
		printf("%c", storeDigits[someIndex]);
		someIndex++;
		//printf("\nPASSED someIndex++, someIndex: %d\n", someIndex);
	}
	printf("\nsomeIndex after storing digits: %d", someIndex);
	storeDigits[someIndex] = '\0'; //to mark the end of the digits, to prevent going past the specified digits
	printf("\n");

	/*printf("Actual storeDigits: ");
	for (int i = 0; i < someIndex; i++)
	{
		printf("%c", storeDigits[i]);
	}
	printf("\n");*/

	//Convert storeDigits[] into an int
	leftNum = atoi(storeDigits);
	//someIndex = 0; //reset someIndex after using
	printf("%d is leftNum\n", leftNum);
	
	return leftNum;
}

int get_RightNum(char* input, int* optrIndex, char* storeDigits, int* endOfRight)
{
	int someIndex = 0;
	int rightNum = 0;
	
	//Stores the digits to the right side of the operator
	printf("Right #, storeDigits: ");
	for (int goRight = *optrIndex + 1; isdigit((input[goRight])); goRight++)
	{
		storeDigits[someIndex] = input[goRight];
		printf("%c", storeDigits[someIndex]);
		someIndex++;

		//If 1 index away is not a digit then get the index of that non digit
		if (!(isdigit((input[goRight + 1]))))
			*endOfRight = goRight; //the index just before the non digit to the right side of the math operator 
	}
	printf("\nsomeIndex after storing digits: %d\n", someIndex);
	printf("endOfRight: [%d]: %c\n", *endOfRight, input[*endOfRight]);
	storeDigits[someIndex] = '\0';

	/*printf("\nActual storeDigits: ");
	for (int i = 0; storeDigits[i] != '\0'; i++)
	{
		printf("%c", storeDigits[i]);
	}*/
	//printf("\n");

	//Convert storeDigits[] into int
	rightNum = atoi(storeDigits);
	//someIndex = 0;
	printf(" and rightNum is %d\n", rightNum);

	return rightNum;
}

int intToChar(int num, char* arr)
{
	int digit;
	int index = 0;

	//For the number 0
	if (num == 0)
	{
		printf("Num is: %d\n", num);
		arr[0] = 48;
		return index;
	}

	for (int i = num; i > 0; i /= 10)
	{
		printf("i = %d\n", i);
		digit = i % 10;
		printf("digit: %d ", digit);
		arr[index] = digit + 48;
		printf("index is: %d, charsOfInt[%d]: %d\n", index, index, arr[index]);
		index++;

	}
	return index - 1; //-1 to account for the extra +1
}

void create_newLeftSide(int* optrIndex, char* output, char* input, char* charsOfInt, int* endOfLeft, int* endOfInt_copy)
{
	//Create the new string that will have the result of the math operation in replace of the just performed on left/right numbers.
	//First part of new string, begins at the start of the old string and goes all the way to the optrIndex to cover
	//everything from the left side
	int finalResult = 0;
	
	for (int i = 0; i < *optrIndex; i++)
	{
		output[i] = input[i];
		printf("%c", output[i]);
	}
	printf("\n");

	//finalResult to be placed right after the left part or to replace what was operated on
	printf("endOfLeft: %d\n", *endOfLeft);
	printf("Placing finalResult into output[%d]\n", *endOfLeft + 1);
	//for (int i = *endOfLeft + 1; *endOfInt_copy >= 0; i++)
	for (int i = *endOfLeft; *endOfInt_copy >= 0; i++)
	{
		//NEW EDIT
		//if (i == 1)
		if (i == 0)
		{
			printf("\nEntered endOfLeft == 0\n");
			//output[i - 1] = charsOfInt[*endOfInt_copy];
			output[i] = charsOfInt[*endOfInt_copy];
			//printf("output[%d]: %c, charsOfInt[%d]: %c | ", i - 1, output[i - 1], *endOfInt_copy, charsOfInt[*endOfInt_copy]);
			printf("output[%d]: %c, charsOfInt[%d]: %c | ", i, output[i], *endOfInt_copy, charsOfInt[*endOfInt_copy]);
			printf("\ninput: %p and output: %p\n", input, output);
			(*endOfInt_copy)--;
			printf("\nendOfInt_copy = %d\n", *endOfInt_copy);
			continue;
			
		}

		output[i] = charsOfInt[*endOfInt_copy];
		printf("output[%d]: %c, charsOfInt[%d]: %c | ", i, output[i], *endOfInt_copy, charsOfInt[*endOfInt_copy]);
		(*endOfInt_copy)--;
		//printf("\nAfter endOfLeft == 0, endOfInt_copy = %d\n", *endOfInt_copy);
	}
	//printf("\n endOfInt: %d\n", endOfInt);
	//reset finalResult to 0 after new string is made
	//finalResult = 0;
}

//Puts any remaining part of the equation that is to the right side of the #s that were operated on after finalResult
void create_newRightSide(int* someIndex, int* endOfLeft, int* endOfInt, char* input, char* output)
{
	int newStrEnd = 0;
	int endOfRight = *someIndex;
	
	printf("\noutput (%p): ", output);
	for (int i = 0; output[i] != '\0'; i++)
	{
		printf("%c", output[i]);
	}

	printf("\ninput (%p): ", input);
	for (int i = 0; input[i] != '\0'; i++)
	{
		printf("%c", input[i]);
	}
	
	//someIndex = endOfRight
	//i is the index right after the placement of finalResult
	//for (int i = *endOfLeft + 1 + *endOfInt + 1; input[*someIndex] != '\0'; i++)
	for (int i = *endOfLeft + *endOfInt + 1; input[*someIndex] != '\0'; i++) 
	{
		//This seems to be working as intended.
		//Don't need to create a newRightSide for the case of 12+0, the last remaining operator
		if (*endOfLeft == 0 && (input[endOfRight + 1] == '\0'))
		{
			newStrEnd = *endOfInt + 1; //to put null char at the end of the number to be operated on
			printf("\nFor the last remaining operator, newStrEnd: %d\n", newStrEnd);
			break;
		}


		printf("\nBeginning new right side at output[%d]\n", i);
		output[i] = input[*someIndex + 1]; //someIndex + 1
		//someIndex++;
		printf("output[%d] = %c , someIndex = %d , input[%d] = %c ", i, output[i], *someIndex, *someIndex + 1, input[*someIndex + 1]);

		//Get the index of output when input is 1 index away from '\0'
		if (input[*someIndex + 1] == '\0')
		{
			printf("ENTERED newStrEnd ASSIGNMENT");
			newStrEnd = i; //1 index after the last character just filled into output?

		}
		(*someIndex)++;
	}
	printf("\nAssigning null char to output[%d] (newStrEnd)", newStrEnd);
	output[newStrEnd] = '\0';//Mark the end of the output
}

void putBackNewStr(char* input, char* output)
{
	int nullCharIndex;
	
	printf("\nPrinting out putBackNewStr, input[]: ");
	for(int i = 0; output[i] != '\0'; i++)
	{
		input[i] = output[i];
		printf("%c", input[i]);
		if(output[i+1] == '\0')
		{
			nullCharIndex = i+1;
		}
	}
	input[nullCharIndex] = '\0';
	printf("/n");
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file