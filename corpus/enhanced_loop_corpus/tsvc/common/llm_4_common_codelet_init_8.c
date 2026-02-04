#include <stdio.h>

#include <inttypes.h>

__attribute__((aligned(64))) extern int indx[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 32000; i++) {
        if ((i + 1) % 4 != 0) {
            indx[i] = (i + 1) % 4 + 1;
        } else {
            indx[i] = 1;
        }
    }
}
