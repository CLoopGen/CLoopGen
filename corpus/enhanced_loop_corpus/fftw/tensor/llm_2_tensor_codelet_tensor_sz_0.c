#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    int n;
    int is;
    int os;
} bench_iodim;

typedef struct {
    int rnk;
    bench_iodim *dims;
} bench_tensor;

extern  bench_tensor *sz;
extern int i;
extern size_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by reversing the loop order to access dims from last to first
    for (i = sz->rnk - 1; i >= 0; --i)
        n *= sz->dims[i].n;
}
