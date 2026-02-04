#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int w;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (w > 0) {
        for (x = 0; x < w; ++x) {
            for (int z = 0; z < 2; ++z) {
                for (int k = 0; k < 1; ++k) {
                }
            }
        }
    }
}
