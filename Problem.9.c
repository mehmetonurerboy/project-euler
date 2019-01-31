#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int kare(int,int,int);

int main(void){
	int a,b,c;
	int cont = 1000;					// The limit value that question gives us
	int max = 0;						// Maximum value of multiply of a, b and c if a < b < c
	for(a=0; a<(cont/3); a++){				// If all of that value equals, a can be maximum cont/3, so this loop's limit equals to that value
		for(b=a; b<(cont/2); b++){				// If a equals to 0 and b&c are equals, b can be maximum cont/2, so this loop's limit equals to that value
			c = cont - a -b;
			if((c>b) && ((pow(a,2)+pow(b,2)) == pow(c,2))){		// We calculate the c, and check our question's conditon, if it provide then we check is it greater than our max value
				int tmp = a*b*c;
				if(tmp > max){
					max = tmp;
				}
			}
		}
	}
	printf("Max : %d",max);
	return 0;
}

