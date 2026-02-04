#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < 8; x++) {
        int t1;
        for (int y = 0; y < 4; y++) {
            int t2;
        }
    }
}
