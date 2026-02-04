#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern int *w;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < M; ++j) {
        int temp = 0;
        w[j] = temp;         // Eliminates potential WAW or WAR hazards by using local temp
        temp = -1;           // Dead store, but breaks artificial dependencies on 'temp'
    }
}
