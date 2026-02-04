#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    int n;
    int is;
    int os;
} bench_iodim;

extern bench_iodim *dst;
extern  bench_iodim *src;
extern int rnk;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (rnk > 0) {
        i = 0;
        for (; i < rnk; ++i)
            dst[i] = src[i];
    }
}
