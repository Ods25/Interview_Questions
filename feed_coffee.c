#include <stdio.h>
#include <math.h>

//so the question was "How many bits are set in 0xfeedc0ffee?"
int setBits(long long n) //converts any integer decimal number to binary, then counts set bits
{
	int array[64], setbitscounter=0, remainder, i = 1, step = 1;// remainder for finding the binary number in reverse, i for moving remainder to final position, step for recording each step.
	while(n!=0) // while the number is not equal to 0
	{
		remainder = n%2; // create remainder as n mod 2, finding the remainder. 
		printf("Step %d: %lld/2, Remainder = %d, Quotient = %lld\n", step++, n, remainder, n/2);
		n /= 2; //for next loop, divide n by 2
		array[step-2] = remainder; //set array element minus remainder 2, so first loop is 0
		if(remainder==1)
			++setbitscounter; //if the remainder is equal to 1, that is an activated bit
	}
	 //so if the quotient is now 0, we are at the end of the loop
	printf("\n\nInput in Binary: "); 
	for(int j=step-2; -1<j; --j)  // we set j equal to the max element of the loop
	{
		printf("%d",array[j]); // now we print each element of the loop going backwards as to print the binary number forwards
		if(j%4==0) // for readability purposes, we'll put a delimeter after every four elements
			printf(".");

	}
	return setbitscounter;
}

int main()
{
	
	long long n;
	printf("\n Enter a hex number: "); // example: 'feedc0ffee'
	scanf("%llx", &n); // the x here could be changed to a d or n to do the same thing with decimal numbers.
	printf("\n\n%lld in dec\n %llx in hex\n %d total set bits\n", n, n, setBits(n));
	
	return 0;
}
