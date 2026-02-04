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
    if ((i + nc) < n) {
        do {
            data[p[i]] = 0;
            i++;
        } while ((i + nc) < n);
    }
}
