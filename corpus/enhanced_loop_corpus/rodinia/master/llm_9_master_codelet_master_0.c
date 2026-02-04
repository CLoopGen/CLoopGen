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
for (i = 0; i < 8; i += 2) {
    if (temp >= nthreads) {
        temp = 0;
    }
    th_count[i/2] = temp;
    temp = temp + 1;
}
}
