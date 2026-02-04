#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ni;
extern int *left;
extern int *q;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < ni; i += 2) {
        if (i + 1 < ni) {
            left[i] = q[i];
            left[i + 1] = q[i + 1];
        } else {
            left[i] = q[i];
        }
    }
}
