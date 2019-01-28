#include <stdio.h>
#include <stdlib.h>

int main(void){
	long long int number;			// The number that we will find the largest prime factor
	
	printf("Enter the number that you want to know largest prime factor : ");
	scanf("%lld",&number);
	
	int maxPrimeFactor = 2;				// The variable that keeps largest prime factor | We assign 2 as a first value because 2 is the smallest prime factor
	while( number % 2 == 0 ){
		number /= 2;
	}
	
	int primeFactor = 3;
	
	while( number > 1){
		while( number % (long long int)primeFactor == 0){
			maxPrimeFactor = primeFactor;
			number /= (long long int)primeFactor;
		}
		primeFactor += 2;
	}
	
	printf("Largest prime factor of entered number is : %d\n",maxPrimeFactor);
	return 0;
}
