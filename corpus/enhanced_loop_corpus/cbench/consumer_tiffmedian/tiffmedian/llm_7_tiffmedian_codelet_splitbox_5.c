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
    int local_sum = 0;
    int j;
    for (j = 0, i = first; i <= last && j < (last - first + 1); ++i, ++j) {
        local_sum += *(histp + j);
        if (local_sum >= sum2) break;
    }
    sum += local_sum;
}
