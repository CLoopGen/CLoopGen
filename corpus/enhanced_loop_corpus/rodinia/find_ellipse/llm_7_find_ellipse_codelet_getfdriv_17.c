#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int N;
extern int *dindex;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N - 2; i++) {
        int temp = i + 2;
        dindex[i] = temp;         // Eliminate potential WAW by isolating computation
        dindex[N - 3 - i] = temp; // Introduce WAR-like pattern, non-sequential access
    }
}
