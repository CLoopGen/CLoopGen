#include <stdio.h>

#include <inttypes.h>

extern int first;
extern int last;
extern int *histp;
extern int i;
extern int sum;
extern int sum2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_sum = sum;
    for (i = first; i <= last; ++i) {
        temp_sum += *histp++;
        if (temp_sum >= sum2) break;
    }
    sum = temp_sum;
}
