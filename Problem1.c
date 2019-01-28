#include <stdio.h>
#include <stdlib.h>

int findModZeroOneByOne(int,int);
int findModZeroWithMath(int,int);

int main(void){
	int resultWithOneByOne = findModZeroOneByOne(3,1000) + findModZeroOneByOne(5,1000) - findModZeroOneByOne(15,1000);
	int resultWithMath = findModZeroWithMath(3,1000) + findModZeroWithMath(5,1000) - findModZeroWithMath(15,1000);
	printf("Result with one by one calculating : %d\n",resultWithOneByOne);
	printf("Result with math formula : %d\n",resultWithMath);
	
	return 0;
}

int findModZeroOneByOne(int mod, int limit){		// Solution with adding elements one by one		| mod : The number of searching multiplies / limit : The number of limit value
	int sum = 0;			// Sumamry value
	int i = mod;			// i initialized with mod value
	while(i < limit){
		sum += i;
		i += mod;			// i increased as mod
	}
	return sum;
}

int findModZeroWithMath(int mod, int limit){		// Solution with maths formula -> 1+2+3 ..  n = (n+1)*n/2  | mod : The number of searching multiplies / limit : The number of limit value
	int num;
	if( limit % mod == 0){			// We should not count as a divisible number of limit value. So if limit value is exactly divisible to mod, We assign the num as appropriate number minus 1
		num = (limit / mod) - 1;
	}else{
		num = limit / mod;
	}
	return mod * ( (1+num) * num / 2);
}
