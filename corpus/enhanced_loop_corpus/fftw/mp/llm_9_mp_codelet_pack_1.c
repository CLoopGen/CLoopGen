#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned short *d;
extern int e;
extern int l;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 1;
    for (i = l - 1; i >= 0; i -= step) {
        e -= step;
        if (d[i] == 0) {
            step = 1; // Reset step on zero
        } else {
            break;
        }
    }
}
