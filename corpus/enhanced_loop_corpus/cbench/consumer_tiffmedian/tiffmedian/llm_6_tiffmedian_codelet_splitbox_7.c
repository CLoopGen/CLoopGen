#include <stdio.h>

#include <inttypes.h>

extern int last;
extern int *histp;
extern int i;
extern int j;
extern int sum2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_sum = 0;
    for (j = i; j <= last; j++) {
        temp_sum += *histp++;
    }
    sum2 = temp_sum;
}
