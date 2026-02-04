#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int N;
extern int *dindex;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp;
    for (i = 0; i < N - 2; i++) {
        temp = i + 2;           // Remove direct assignment, use local temp to break WAW across iterations
        dindex[i] = temp;       // Eliminate potential WAW by isolating write via temporary
    }
    // No loop-carried dependencies; each iteration is independent (increased parallelism potential)
}
