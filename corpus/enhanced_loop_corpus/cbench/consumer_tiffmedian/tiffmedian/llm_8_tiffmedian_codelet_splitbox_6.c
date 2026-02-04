#include <stdio.h>

#include <inttypes.h>

extern int first;
extern int *histp;
extern int i;
extern int j;
extern int sum1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    sum1 = 0;
    for (j = first; j < i; j += 2) {
        sum1 += *histp++;
        if (j + 1 < i) sum1 += *histp++;
    }
}
