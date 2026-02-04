#include <stdio.h>

#include <inttypes.h>

__attribute__((aligned(64))) extern int indx[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int k = 0; k < 32000; k += 8) {
        for (int i = 0; i < 8; i++) {
            if (k + i < 32000) {
                indx[k + i] = ((k + i) + 1) % 4 + 1;
            }
        }
    }
}
