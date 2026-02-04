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
    if (n > 0) {
        i = 0;
        for (; i < (ssize_t)n; ) {
            *q++ = (*p++);
            i++;
        }
    }
}
