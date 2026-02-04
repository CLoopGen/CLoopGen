#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int nthreads;
extern int th_count[4];
extern int temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int depth1 = 0; depth1 < 2; depth1++) {
    for (i = 0; i < 4; i++) {
        if (temp >= nthreads) {
            temp = 0;
        }
        th_count[i] = temp;
        temp = temp + 1;
    }
}
}
