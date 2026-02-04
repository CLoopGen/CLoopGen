#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float alpha;
extern void *X;
extern  int incX;
extern int i;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N; i += 2) {
        int limit = (i + 1 < N) ? 2 : 1;
        for (int j = 0; j < limit; j++) {
            (((float *)X)[2 * (ix)]) *= alpha;
            (((float *)X)[2 * (ix) + 1]) *= alpha;
            ix += incX;
        }
    }
}
