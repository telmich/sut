#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct sut {
    int hour;
    int min;
    int sec;
}SUT_TIME;

// this function turns UDT to STD seconds
SUT_TIME seconds_to_sut(int milli){
	SUT_TIME cur_sut;

    cur_sut.sec = (int)milli;
    return cur_sut;
}

// convert a timeval and time to milliseconds of today
int seconds_of_day(struct timeval sec, struct tm tim){
    long int milli_since_epoch = (sec.tv_sec * 1000)+(sec.tv_usec/100);
    long int sec_strt_tdy = 1000 * (sec.tv_sec - 
    	(tim.tm_sec) - 
    	(tim.tm_min * 60) - 
    	(tim.tm_hour * 3600));
    int tdy_mlsec = (int)(milli_since_epoch - sec_strt_tdy);
    printf("time in millisec: %ld\n", milli_since_epoch);
    return tdy_mlsec;
}

int main(){
	struct timeval *timeval_struct;
	time_t rawtime;
	struct tm * tm_struct;
	gettimeofday(timeval_struct, NULL);
	time(&rawtime);
	tm_struct = gmtime(&rawtime);


	int milli = seconds_of_day(*timeval_struct, *tm_struct);
	//SUT_TIME response = utc_to_sut(milli);
	
	printf("%d\n", milli);
	
	return(0);
}
