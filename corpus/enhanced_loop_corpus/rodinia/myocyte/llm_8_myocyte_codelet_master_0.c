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
int start = temp % nthreads;
for (i = 0; i < 4; i++) {
    th_count[i] = (start + i) % nthreads;
}
temp = (temp + 4) % nthreads;
}
