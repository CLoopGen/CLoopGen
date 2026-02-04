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
    for (i = 0; i < ni; ++i) {
        right[i] = p[i];
        if (p[i] == 0)
            i += 1; // Skip next element when current is zero
    }
}
