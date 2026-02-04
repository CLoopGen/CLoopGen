#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int w2;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i, j;
    for (i = 0; i < w2 / 2; i++) {
        for (j = 0; j < 5; j++) {
            x += (i + j) * 2;
        }
    }
}
