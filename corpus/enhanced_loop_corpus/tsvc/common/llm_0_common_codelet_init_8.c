#include <stdio.h>

#include <inttypes.h>

__attribute__((aligned(64))) extern int indx[32000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 8000; j++) {
        for (int i = 0; i < 4; i++) {
            int idx = j * 4 + i;
            indx[idx] = (idx + 1) % 4 + 1;
        }
    }
}
