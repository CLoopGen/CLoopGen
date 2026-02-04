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
    int temp_n, temp_is, temp_os;
    for (i = 0; i < rnk; ++i) {
        temp_n = src[i].n;
        temp_is = src[i].is;
        temp_os = src[i].os;
        dst[i].n = temp_n;
        dst[i].is = temp_is;
        dst[i].os = temp_os;
    }
}
