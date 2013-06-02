#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct sut {
    int hour;
    int min;
    int sec;
}SUT_TIME;

// turn milliseconds passed today into a SUT object
void utc_to_sut(int milli, SUT_TIME* cur_sut){
    cur_sut->hour = (int)floor(milli / 10000000.0);
    cur_sut->min  = ((int)floor(milli / 100000.0)) % 100;
    cur_sut->sec  = ((int)floor(milli / 1000.0)) % 100;
    return;
}

/*
Description: convert a timeval and time to milliseconds of today
Inputs: 
-   timeval is used to extract milliseconds
-   tim is used to get the number of hours, minutes and 
    seconds that have passed today
*/
int seconds_of_day(struct timeval *sec, struct tm *tim){
    long int milli_since_epoch = (sec->tv_sec * 1000)+(sec->tv_usec/1000);
    long int sec_strt_tdy = 1000 * (sec->tv_sec - 
    	(tim->tm_sec) - 
    	(tim->tm_min * 60) - 
    	(tim->tm_hour * 3600));
    int tdy_mlsec = (int)(milli_since_epoch - sec_strt_tdy);
    return tdy_mlsec;
}

int main(){
    // variable to access usec (nanoseconds)
	struct timeval timeval_struct;
    // time to pull the gmttime from
	time_t rawtime;
    // time to assign gmtime's tm stuct too
	struct tm *tm_struct;

    // extracts the timeval_struct data
	gettimeofday(&timeval_struct, NULL);
    // extracts the utctime for hours minutes and seconds
	time(&rawtime);
	tm_struct = gmtime(&rawtime);

    // this call gets the number of milliseconds passed today
    int milli = seconds_of_day(&timeval_struct, tm_struct);
	SUT_TIME sut;
    utc_to_sut(milli, &sut);
	
    // print out the current standard universal time
	printf("%4d-%02d-%02d %d:%02d:%02d SUT\n", 
        tm_struct->tm_year+1900,
        tm_struct->tm_mon+1,
        tm_struct->tm_mday,
        sut.hour, 
        sut.min, 
        sut.sec);
	
	return(0);
}
