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
for (i = 0; i < ni; ++i) {
    int k = i;
    for (k = i; k <= i; ++k)
        left[k] = q[k];
}
}
