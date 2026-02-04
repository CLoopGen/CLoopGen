#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int N;
extern int *cindex;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N - 1; i++) {
        int temp = i + 1;
        cindex[N - 2 - i] = temp; // Reverse store order: introduces WAR/WAW if executed out of order, breaks natural loop-carried dependence
    }
}
