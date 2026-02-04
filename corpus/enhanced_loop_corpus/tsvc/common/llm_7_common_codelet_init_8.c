#include <stdio.h>

#include <inttypes.h>

__attribute__((aligned(64))) extern int indx[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp[32000];
    for (int i = 0; i < 32000; i++) {
        temp[i] = (i + 1) % 4 + 1;
    }
    for (int i = 0; i < 32000; i++) {
        indx[i] = temp[i];
    }
}
