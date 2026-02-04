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
for (i = 0; i < 2; i++) {
    int k;
    for (k = 0; k < 2; k++) {
        int idx = i * 2 + k;
        if (temp >= nthreads) {
            temp = 0;
        }
        th_count[idx] = temp;
        temp = temp + 1;
    }
}
}
