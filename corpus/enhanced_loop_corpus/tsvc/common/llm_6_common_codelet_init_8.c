#include <stdio.h>

#include <inttypes.h>

__attribute__((aligned(64))) extern int indx[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 32000; i++) {
        indx[i] = (indx[(i - 1 + 32000) % 32000] + 1) % 4 + 1;
    }
}
