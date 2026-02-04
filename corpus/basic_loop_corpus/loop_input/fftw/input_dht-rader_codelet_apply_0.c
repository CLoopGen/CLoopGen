#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ptrdiff_t INT;
typedef double R;

INT n = 131072;          
INT npad = 262144;        
INT k;

R *buf;

void init_vars() {
    buf = (R*)aligned_alloc(32, npad * sizeof(R));
    if (!buf) {
        exit(1);
    }
}