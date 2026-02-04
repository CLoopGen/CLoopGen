#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int N;
extern int *bindex;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp;
    for (i = 0; i < N; i++) {
        temp = i;           // Remove direct assignment to memory
        bindex[i] = temp;   // Eliminate potential WAR/WAW by using local temp (no loop-carried dep)
    }
}
