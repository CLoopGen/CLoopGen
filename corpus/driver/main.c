#include<stdio.h>
#include <sys/time.h>

extern void loop();
extern void init_vars();

int main(){

    struct timeval start, end;
    long seconds, useconds;
    init_vars();
    
    gettimeofday(&start, NULL);
    loop();
    gettimeofday(&end, NULL);

    seconds  = end.tv_sec  - start.tv_sec;
    useconds = end.tv_usec - start.tv_usec;
    printf("%ld", seconds * 1000000 + useconds);
    return 0;
}