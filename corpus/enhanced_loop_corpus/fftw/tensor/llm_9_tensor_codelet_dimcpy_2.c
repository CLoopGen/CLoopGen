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
    int limit = rnk * 8;
    for (i = 0; i < limit; i += 8) {
        dst[i/8] = src[i/8];
        dst[i/8].n += (dst[i/8].is - dst[i/8].os) * 2;
    }
}
