#include <stdio.h>

#include <inttypes.h>

extern int *byte_abs;
extern int *diff;
extern int i;
extern int sad;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 64; i += 4) {
        sad += byte_abs[diff[i]];
        if (i + 1 < 64) sad += byte_abs[diff[i + 1]];
        if (i + 2 < 64) sad += byte_abs[diff[i + 2]];
        if (i + 3 < 64) sad += byte_abs[diff[i + 3]];
    }
}
