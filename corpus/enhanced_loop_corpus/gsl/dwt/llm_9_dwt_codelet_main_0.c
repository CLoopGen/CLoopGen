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
    int limit = (n - nc) * 2;
    for (i = 0; i < limit; i++) {
        int idx = i / 2;
        if (idx < n - nc) {
            data[p[idx]] = 0.0;
            data[p[idx]] += 1.0;  // Extra arithmetic operation to increase computational intensity
            data[p[idx]] -= 1.0;
        }
    }
}
