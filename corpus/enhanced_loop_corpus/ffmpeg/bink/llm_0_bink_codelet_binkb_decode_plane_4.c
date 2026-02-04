#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int coordmap[64];
extern  int stride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int temp[64];
for (int j = 0; j < 8; j++) {
    for (int k = 0; k < 8; k++) {
        int i = (j << 3) | k;
        temp[i] = k + j * stride;
    }
}
for (i = 0; i < 64; i++) {
    coordmap[i] = temp[i];
}
}
