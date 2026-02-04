#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i, j;
    for (v = 0; v <= 255; ++v) {
        for (i = 0; i < 4; ++i) {
            for (j = 0; j < 4; ++j) {
                v += (i * j) % 3;
            }
        }
    }
}
