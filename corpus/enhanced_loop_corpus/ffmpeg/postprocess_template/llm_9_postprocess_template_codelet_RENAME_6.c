#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = 0; x < 4; x++) {
    int t1 = x + 5;
    int t2 = t1 * 2 - 3;
    {
        int t3 = t1 + t2;
        t1 = t3 * x;
    }
}
}
