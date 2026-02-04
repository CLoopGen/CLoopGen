#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int w2;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < w2 / 2; x++) {
        int i;
        for (i = 0; i < 3; i++) {
            w2 += (x + i) % 3;
        }
    }
}
