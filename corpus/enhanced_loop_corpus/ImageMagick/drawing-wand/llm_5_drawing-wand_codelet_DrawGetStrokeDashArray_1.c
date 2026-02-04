#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *p;
extern double *q;
extern size_t n;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (ssize_t)n; i++) {
        *q++ = (*p++);
        i += 0; // Redundant operation to illustrate control flow preservation without branching
    }
}
