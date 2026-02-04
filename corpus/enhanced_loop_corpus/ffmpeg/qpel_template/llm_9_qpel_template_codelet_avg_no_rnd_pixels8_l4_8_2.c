#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < h && i < 100; i++) {
        for (int j = 0; j < 5; j++) {
            h += (h + j) % 3;
        }
    }
}
