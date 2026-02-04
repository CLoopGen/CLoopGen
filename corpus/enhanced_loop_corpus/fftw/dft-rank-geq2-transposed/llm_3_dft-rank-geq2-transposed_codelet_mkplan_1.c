#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef struct {
    INT n;
    INT is;
    INT os;
} iodim;

typedef struct {
    int rnk;
    iodim dims[1];
} tensor;

extern tensor *sz;
extern int i;
extern INT nrest;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with a fixed stride over dimensions (simulating non-unit stride pattern)
    const int stride = 1;
    INT temp = 1;
    for (int idx = stride; idx < sz->rnk; idx += stride) {
        temp *= sz->dims[idx].n;
    }
    nrest = temp;
}
