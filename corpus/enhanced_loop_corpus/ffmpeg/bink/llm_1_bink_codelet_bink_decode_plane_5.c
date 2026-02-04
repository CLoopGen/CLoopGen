#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int coordmap[64];
extern  int stride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 8; i++) {
        int base = i * 8;
        for (int j = 0; j < 8; j++) {
            int idx = base + j;
            coordmap[idx] = j + i * stride;
        }
    }
}
