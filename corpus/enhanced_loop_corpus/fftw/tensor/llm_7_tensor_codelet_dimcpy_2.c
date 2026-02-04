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
        dst[i].n = src[i].n;
        dst[i].is = src[i].is;
        dst[i].os = src[i].os;
        // Introduce a loop-carried dependency: each iteration depends on the previous write to dst[i-1]
        if (i > 0) {
            dst[i].n += dst[i-1].n;
        }
    }
}
