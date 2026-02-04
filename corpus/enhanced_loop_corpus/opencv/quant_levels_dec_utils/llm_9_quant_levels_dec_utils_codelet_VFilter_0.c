#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int w;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < w && x < 1000; ++x) {
        for (int y = 0; y < 5; ++y) {
            w += (w + y) % 3;
        }
    }
}
