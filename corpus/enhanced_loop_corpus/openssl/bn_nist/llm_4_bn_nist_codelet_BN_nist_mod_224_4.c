#include <stdio.h>

#include <inttypes.h>

extern unsigned long c_d[4];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; ii < (224 + (8 * 8) - 1) / (8 * 8); ii++) {
        if (ii >= 0)
            (c_d)[ii] = 0;
    }
}
