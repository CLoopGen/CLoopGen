#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int deltas[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 2; j++) {
            deltas[i * 2 + j] = (i + j) * 3 + 5;
        }
    }
}
