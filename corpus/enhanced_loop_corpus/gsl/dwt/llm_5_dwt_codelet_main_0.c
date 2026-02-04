#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int n;
extern int nc;
extern double *data;
extern size_t *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; (i + nc) < n && i < 1000; i++) {
        if (i % 2 == 0) {
            data[p[i]] = 0;
        }
    }
}
