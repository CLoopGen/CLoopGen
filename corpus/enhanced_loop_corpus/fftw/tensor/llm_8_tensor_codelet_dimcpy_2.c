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
    for (i = 0; i < rnk; ++i) {
        dst[i].n = src[i].n * 2 + 1;
        dst[i].is = src[i].is * 3 - 1;
        dst[i].os = src[i].os * 4 + 2;
    }
}
