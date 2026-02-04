#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ptrdiff_t INT;

INT n;
INT s;
int i;
INT *p;

void init_vars() {
    n = 16777216; // 16M elements to target ~0.01 sec on modern CPU
    s = 42;
    i = 0;
    p = (INT*)aligned_alloc(_Alignof(INT), n * sizeof(INT));
    if (!p) {
        exit(1);
    }
}