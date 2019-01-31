#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *getPrimeNumbers(int);
int isPrime(int);
int findHowManyPrimeNumber(int);

int main(void){
	int number;														// The variable keep for calculating the number that divided all numbers from 1 to that number
	printf("Please enter the number(For finding the number that divided 1 to that number) : ");
	scanf("%d",&number);
	
	int primeNumber = findHowManyPrimeNumber(number);			// It keeps the number of prime numbers from 1 to value of number variable;
	printf("There are ... prime numbers from 1 to %d : %d\n",number,primeNumber);
	
	int *primes = (int*) malloc (primeNumber*sizeof(int));			// This array keeps all prime numbers from 1 to the value of number
	primes = getPrimeNumbers(number);	
	
	printf("All prime numbers from 1 to %d : \n\n",number);				// Control informations (For checking trueness of program
	i = 0;
	for(; i<lineNumber; i++){
		printf("%d. prime number : %d\n",i+1,primeNumber[i]);
	}
	
	double result = 1;
	int i=0;
	for( ; i<primeNumber ; i++){
		int exponent = 0;
		while( pow((double)(primes[i]),(double)(exponent)) < number){	// We add 5 2s to result as multipliers, we have to pass over 32 number. So we check which power of a prime we have
			exponent++;
		}
		result *= pow((double)(primes[i]),(double)(exponent-1));	// pow() function defined over double variables, so I change the used matrix value's type
	}
	
	printf("\n\nThe smallest positive number that is evenly divisible by all of the numbers from 1 to %d : %.0f",number,result);
	
	free(primes);
	return 0;
}


int *getPrimeNumbers(int number){									// This function returns prime numbers array from 1 to number 
	int elementNumber = findHowManyPrimeNumber(number);		// Firstly, we calculate the number of primes with findHowManyPrimeNumber() function
	if( elementNumber == 0){
		return NULL;
	}else{
		int *result = (int*) malloc (elementNumber*sizeof(int));
		*(result+0) = 2;
		int i = 1;
		int multiplier = 3;
		while(i<elementNumber){				// multiplier increases 2 for each loop until equals or greater than number
			if(isPrime(multiplier)){				// if multiplier value is prime, it assigns the i. section of array & i updates
				*(result+i) = multiplier;
				i++;
			}
			multiplier += 2;
		}
		return result;
	}
}

int isPrime(int number){					// This function returns 1 if number value is prime, otherwise returns 0
	int i = 3;
	int boolean = 1;			// boolean means number is prime or not ( 1 : prime | 0 : not prime )
	if(number < 2){
		return 0;
	}else{
		while( (boolean == 1) && (i < number)){			
			if( number % i == 0){			// i always smaller than number so, if it is divisible without remainder then it is not a prime number
				boolean = 0;
			}
			i += 2;
		}
		return boolean;
	}
}

int findHowManyPrimeNumber(int limit){			// This funciton returns how many primes from 1 to limit
	int i = 5;
	int number;				// number keeps the number of primes from 1 to limit
	if( limit < 2){
		return 0;
	}else if (limit == 2){
		return 1;
	}else{								// limit is equals to or greater than 3, So we have 2 primes here (2 & 3)
		number = 2;
		while(i < limit){
			if(isPrime(i)){
				number++;
			}
			i += 2; 
		}
		return number;
	}
}
