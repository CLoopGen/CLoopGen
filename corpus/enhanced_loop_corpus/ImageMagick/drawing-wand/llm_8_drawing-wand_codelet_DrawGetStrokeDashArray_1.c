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
    for (i = 0; i < (ssize_t)n; i += 2) {
        if (i + 1 < (ssize_t)n) {
            *q++ = (*p++);
            *q++ = (*p++);
        } else {
            *q++ = (*p++);
        }
    }
}
