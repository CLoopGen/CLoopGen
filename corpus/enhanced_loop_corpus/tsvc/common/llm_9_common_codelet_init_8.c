#include <stdio.h>

#include <inttypes.h>

__attribute__((aligned(64))) extern int indx[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 32000; i += 4) {
        indx[i] = (i + 1) % 4 + 1;
        if (i + 1 < 32000) indx[i + 1] = (i + 2) % 4 + 1;
        if (i + 2 < 32000) indx[i + 2] = (i + 3) % 4 + 1;
        if (i + 3 < 32000) indx[i + 3] = (i + 4) % 4 + 1;
    }
}
