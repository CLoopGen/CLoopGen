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

struct fftw_iodim_do_not_use_me {
    int n;
    int is;
    int os;
};


typedef struct fftw_iodim_do_not_use_me fftw_iodim;

extern bench_tensor *t;
extern fftw_iodim *d;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Eliminate loop-carried dependencies entirely and randomize access order
    // All iterations are now independent (no RAW, WAR, WAW across iterations)
    // Uses reverse traversal and removes any inter-iteration state
    for (i = t->rnk - 1; i >= 0; --i) {
        fftw_iodim temp = {0};
        temp.n = t->dims[i].n;
        temp.is = t->dims[i].is;
        temp.os = t->dims[i].os;
        d[i] = temp;  // Full struct assignment, no shared state between iterations
    }
}
