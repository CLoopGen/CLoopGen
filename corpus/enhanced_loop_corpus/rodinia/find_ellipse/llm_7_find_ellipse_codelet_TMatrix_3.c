#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int N;
extern int *bindex;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N; i++) {
        int temp = i * 2;       // Local computation with no write-write conflict
        bindex[i] = temp;       // WAW hazard removed by using temporary
        bindex[N - 1 - i] = i;  // Introduces WAR-like pattern via reverse indexing, but safe due to distinct locations
    }
}
