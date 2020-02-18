int evaluateInput(char* input)
{
	char* inputPtr;

	int optrIndex = 0;
	int endOfLeft = 0; //This is the index of the character starting at the beginning of each operator and including no operator
	int endOfRight = 0;
	int numOfSteps = 0;

	char storeDigits[11] = {}; //store the digits for each math operation
	int someIndex = 0; //needs to be reset to 0 after each use
	int newStrEnd = 0;

	int leftNum, rightNum = 0;
	int finalResult = 0; //to store the result after performing math operator, need to reset after each use
	char newStr[100] = {}; //the new string each time a math operator is performed

	bool Exp_done = 0;

	//inputPtr = input; //inputPtr now points to input[0]

	//Loop through the input. If it doesn't encounter a non digit, then it just loops through and does nothing.
	for (int i = 0; input[i] != '\0'; i++)
	{
		printf("INDEX IS %d, CURRRENTLY AT: %c\n", i, input[i]);
		//Perform the math operator whenever it is encountered following the order of EMDAS with priority
		//from left to right
		/*
		1. If inputPtr[i] is not a digit then begin checking for EMDAS and store the left and right digits of the math operator
		2. Check what math operator the non digit is, then perform the math operation on the left and right number and store the
		result of the math operation
		3. Create the new string that will have the result of the math operation in replace of the just performed on left/right numbers and operator
		4. Point to this new string to be looped on
		*/
		/*To keep track of the number of steps you take as you move from left to right in input. This needs to be reset after it's finished being used
		to go left of the operator. */
		numOfSteps++; 

		//1. 
		if (!(isdigit(input[i])))
		{
			optrIndex = i;//store index of operator
			printf("optrIndex: %d ", optrIndex);

			//Check for EMDAS
			if ((input[i] == '^') && !Exp_done)
			{

			}
			else if ((input[i] == 'x') && Exp_done)
			{

			}


			//Goes back the number of steps taken to reach an operator from the index of the operator
			for (int goLeft = optrIndex; numOfSteps != 0; numOfSteps--) 
			{
				//Get the index of the furthest left digit from the operator. The digit is right after an operator or the very first digit.
				if (numOfSteps == 1)
				{
					endOfLeft = goLeft;
				}
				/*if (!(isdigit((input[goLeft - 1]))))
					endOfLeft = goLeft - 1; //endOfLeft is the index of the operator that it hits
					*/
				goLeft--;
			}
			numOfSteps = 0; //Reset after finishing going left from the operator to be used again

			//Goes from the endOfLeft index until it hits an operator (optrIndex) and stores each digit
			printf("Left #, storeDigits: ");
			for (int goRight = endOfLeft; isdigit(input[goRight]); goRight++)
			{
				storeDigits[someIndex] = input[goRight];
				printf("%c", storeDigits[someIndex]);
				someIndex++;
			}
			storeDigits[someIndex + 1] = '\0'; //to mark the end of the digits, to prevent going past the specified digits
			printf("\n");

			//Convert storeDigits[] into an int
			leftNum = atoi(storeDigits);
			someIndex = 0; //reset someIndex after using
			printf("%d is leftNum\n", leftNum);

			//END OF GETTING LEFT NUMBER, BEGIN GETTING RIGHT NUMBER

			//Stores the digits to the right side of the operator
			printf("Right #, storeDigits: ");
			for (int goRight = optrIndex + 1; isdigit((input[goRight])); goRight++)
			{
				storeDigits[someIndex] = input[goRight];
				printf("%c", storeDigits[someIndex]);
				someIndex++;

				//If 1 index away is not a digit then get the index of that non digit
				if (!(isdigit((input[goRight + 1]))))
					endOfRight = goRight + 1; //the index of the non digit to the right side of the math operator 
			}
			printf("\nstoreDigits after:");
			storeDigits[someIndex] = '\0';
			for (int i = 0; storeDigits[i] != '\0'; i++)
			{
				printf("%c", storeDigits[i]);
			}
			printf("\n");

			//Convert storeDigits[] into int
			rightNum = atoi(storeDigits);
			someIndex = 0;
			printf("%d is rightNum\n", rightNum);

			/*
			//END OF GETTING RIGHT NUMBER, BEGIN DECISION OF MATH OPERATOR
			//2. Check what math operator the non digit is, then perform the math operation on the leftand right numberand store the
			//result of the math operation
			if (input[i] == '^')
			{
				finalResult = pow(leftNum, rightNum);
				printf("finalResult is:%d\n", finalResult);
			}
			else if (input[i] == '/')
			{
				//quotient = div(leftNum, rightNum);
				//finalResult = quotient.quot;
				finalResult = leftNum / rightNum;
				printf("finalResult is:%d\n", finalResult);
			}
			else if (input[i] == '*')
			{
				finalResult = leftNum * rightNum;
				printf("finalResult is:%d\n", finalResult);
			}
			else if (input[i] == '-')
			{
				finalResult = leftNum - rightNum;
				printf("finalResult is:%d\n", finalResult);
			}
			else if (input[i] == '+')
			{
				finalResult = leftNum + rightNum;
				printf("finalResult is:%d\n", finalResult);
			}
			else
				printf("invalid operator, operators ^,/,*,+,- only\n");
			*/
			//END OF MATH OPERATOR, BEGIN NEW STRING
			//3. Create the new string that will have the result of the math operation in replace of the just performed on left/right numbers 
			//and operator

			//The new string is made up of everything except the characters that were used to perform the math
			//operation. It will have two parts: 
			//The first part will contain the start of the old string up to the operator that is to the left of the math operator that was just
			//performed. 
			//The other part of the new string begins from endOfRight until it reaches '\0'
			//The result of the math operation (finalResult) will be in between.

			//First part of new string, begins at the start of the old string and goes all the way to the optrIndex to cover
			//everything from the left side
			printf("After finalResult, endOfLeft is: %d\n", endOfLeft);
			printf("From beginning to optrIndex %d, newStr:", optrIndex);
			for (int i = 0; i < optrIndex; i++)
			{
				newStr[i] = input[i];
				printf("%c", newStr[i]);
			}
			printf("\n");

			//**********************************NEED TO FIX
			//finalResult to be placed right after the left part or to replace what was operated on
			printf("Placing finalResult into newStr[%d]\n", endOfLeft + 1);
			newStr[endOfLeft + 1] = finalResult;
			//reset finalResult to 0 after new string is made
			finalResult = 0;

			//Second part of new string, begins from the characters after endOfRight till it reaches '\0' 
			printf("newStr 2ndPart:");
			someIndex = endOfRight + 1;
			for (int i = endOfLeft + 2; input[someIndex] != '\0'; i++)
			{
				newStr[i] = input[someIndex];
				someIndex++;
				printf("%c", newStr[i]);
				//Get the index of newStr when input is 1 index away from '\0'
				if (input[someIndex + 1] == '\0')
					newStrEnd = i + 1; //1 index after the last character just filled into newStr
			}
			newStr[newStrEnd] = '\0';//Mark the end of the newStr
			someIndex = 0; //reset after use
			printf("\n");

			//4. Point to this new string to be looped on
			//Once the newStr is made, set inputPtr to newStr to loop through newStr
			input = newStr;
			optrIndex = 0; //reset
			i = -1; //reset the for loop index counter to 0 to process the string from the beginning
			printf("optrIndex: %d\n", optrIndex);
			printf("Final newStr:");
			for (int i = 0; newStr[i] != '\0'; i++)
			{
				printf("%c", newStr[i]);
			}
			printf("\n");
			printf("END OF PROCESSING AN OPERATOR: input set to newStr\n");
		}//End of if(isdigit...)
		
	}//End of for loop


}