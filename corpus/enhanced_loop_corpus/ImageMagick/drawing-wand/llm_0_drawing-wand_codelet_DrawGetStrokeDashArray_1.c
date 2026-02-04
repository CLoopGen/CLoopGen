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
    for (ssize_t j = 0; j < (ssize_t)n; j++) {
        for (i = j; i < j + 1 && i < (ssize_t)n; i++)
            *q++ = (*p++);
    }
}
