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
    for (i = l - 1; i >= 0; --i)
        for (int j = 0; j < 1; ++j) {
            if (d[i] != 0) {
                --e;
                break;
            }
            --e;
        }
}
