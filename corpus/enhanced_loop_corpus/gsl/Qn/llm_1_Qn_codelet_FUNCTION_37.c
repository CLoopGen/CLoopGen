#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ni;
extern int *right;
extern int *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (ni > 0) {
        i = 0;
        for (int outer = 0; outer < 1; ++outer)
            for (; i < ni; ++i)
                right[i] = p[i];
    }
}
