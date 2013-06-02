#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct sut {
    int hour;
    int min;
    int sec;
}SUT_TIME;

// this function turns UDT to STD seconds
SUT_TIME utc_to_sut(struct timeval time){
    double seconds = time.tv_sec+(time.tv_usec/1000000.0);;
    SUT_TIME cur_sut;

    cur_sut.sec = (int)seconds;
    return cur_sut;
}

int main(){
	struct timeval tim;
	gettimeofday(&tim, NULL);
	
	SUT_TIME response = utc_to_sut(tim);
	
	printf("%d\n", response.sec);
	
	return(0);
}
