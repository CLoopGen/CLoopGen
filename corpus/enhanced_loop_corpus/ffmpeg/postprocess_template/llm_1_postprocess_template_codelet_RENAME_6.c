#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < 8; x += 2) {
        int t1;
        int t2;
        if (x + 1 < 8) {
            int t3;
            int t4;
        }
    }
}
