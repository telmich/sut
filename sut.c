#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	time_t seconds;
	seconds = time (NULL);
	
	printf("Hello World! %ld\n", seconds);
	
	return(0);
}
