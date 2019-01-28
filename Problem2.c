#include <stdio.h>
#include <stdlib.h>



int main(void){
	int fibonacciSum = 2;
	int valueBeforeOneCycle = 2;			// The variables (valueBeforeOneCycle & valueBeforeTwoCycle) are for calculated that fibonacci number 
	int valueBeforeTwoCycle = 1;			// Because fibonacci numbers are the sum of previous 2 fibonacci number
											// And first fibonacci numbers are 1 & 1 but in this question it accepts 1 & 2
	int limit;								// Limit is the top value that fibonacci number equals
	
	
	printf("Enter the limit value that we calculate the sum of even fibonacci number below that: \n");
	scanf("%d",&limit);
	
	int calculatedFibonacciNum = valueBeforeOneCycle + valueBeforeTwoCycle;			// ibonacci numbers are the sum of previous 2 fibonacci number
	
	while(calculatedFibonacciNum < limit){				// New fibonacci number have to calculate until value passes the limit value.
		if(calculatedFibonacciNum % 2 == 0){				// If fibonacci number is even, then it can be added to the sum.
			fibonacciSum += calculatedFibonacciNum;
		}
		valueBeforeTwoCycle = valueBeforeOneCycle;				// The variable that one cycle before fibonacci number will be the variable that two cycle before for next fibonacci number
		valueBeforeOneCycle = calculatedFibonacciNum;			// Also calculated value will be once cycle before fibonacci number
		calculatedFibonacciNum = valueBeforeOneCycle + valueBeforeTwoCycle;
	}
	
	printf("The sumamry of even fibonacci numbers that below %d is : %d\n",limit,fibonacciSum);
	return 0;
}
