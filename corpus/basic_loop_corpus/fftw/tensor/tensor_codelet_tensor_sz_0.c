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
for (i = 0; i < sz->rnk; ++i)
    n *= sz->dims[i].n;

}
