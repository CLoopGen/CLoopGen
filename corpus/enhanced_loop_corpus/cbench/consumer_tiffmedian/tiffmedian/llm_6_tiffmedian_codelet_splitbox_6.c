#include <stdio.h>

#include <inttypes.h>

extern int first;
extern int *histp;
extern int i;
extern int j;
extern int sum1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_sum = 0;
    for (j = first; j < i; j++) {
        temp_sum += *histp;
        histp++;
    }
    sum1 = temp_sum;
}
