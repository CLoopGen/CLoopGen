#include <stdio.h>

#include <inttypes.h>

__attribute__((aligned(64))) extern int indx[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 16000; i++) {
        indx[i * 2] = (i + 1) % 4 + 1;
        indx[i * 2 + 1] = (i + 2) % 4 + 1;
    }
}
