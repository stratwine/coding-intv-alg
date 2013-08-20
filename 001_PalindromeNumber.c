// Coding Interviews: Questions, Analysis & Solutions
// Harry He

#include <stdio.h>
#include <string.h>

// ==================== Solution 1 ====================
/*
Convert to String
Find the mid of the length
Have two pointers. One at the start, one at the end
(Or instead, for each s[i] check s[length-1-i]
Do this until the mid length is reached.
When mid length is reached, succees.
Else, any mismatch ? false
*/
int IsPalindrome(const char* const string)
{
    int palindrome = 1;
    if(string != NULL)
    {
        int length = strlen(string);
        int half = length >> 1;

        int i;
        for(i = 0; i < half; ++ i)
        {
            if(string[i] != string[length - 1 - i])
            {
                palindrome = 0;
                break;
            }
        }
    }

    return palindrome;
}

/* It returns 1 when number is palindrome, otherwise returns 0. */
#define NUMBER_LENGTH 20
int IsPalindrome_solution1(unsigned int number)
{
    char string[NUMBER_LENGTH];
    sprintf(string, "%d", number);

    return IsPalindrome(string);
}

// ==================== Solution 2 ====================

/*
This approach is without converting the number to String.
copy the orignial number to 'copy'
reverse the original number.
*/

/* It returns 1 when number is palindrome, otherwise returns 0. */
int IsPalindrome_solution2(unsigned int number)
{
    int reversed = 0; // don't have to initialize to 1
    int copy = number;

    while(number != 0)
    {
        reversed = reversed * 10 + number % 10; 
		    //avoids the use of Math.pow
			//at the first iteration, reversed=0*10+number%10
			//just the way we wanted it
        number /= 10;
    }

    return (reversed == copy) ? 1 : 0;
}

// ==================== Test Code ====================

void Test(char* testName, int number, int expected)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    if(IsPalindrome_solution1(number) == expected)
        printf("solution 1 passed; ");
    else
        printf("solution 1 FAILED; ");

    if(IsPalindrome_solution2(number) == expected)
        printf("solution 2 passed.\n");
    else
        printf("solution 2 FAILED.\n");
}

int main(int argc, char* argv[])
{
    Test("Test1", 5, 1);
    Test("Test2", 33, 1);
    Test("Test3", 242, 1);
    Test("Test4", 2332, 1);

    Test("Test5", 0, 1);

    Test("Test6", 32, 0);
    Test("Test7", 233, 0);
    Test("Test8", 2331, 0);
    Test("Test9", 2322, 0);

	return 0;
}
