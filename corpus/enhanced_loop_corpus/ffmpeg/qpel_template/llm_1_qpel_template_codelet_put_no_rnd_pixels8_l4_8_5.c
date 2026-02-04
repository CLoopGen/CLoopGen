#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (h > 0) {
        for (i = 0; i < h; i++) {
            for (int k = 0; k < 1; k++) {
            }
        }
    }
}
