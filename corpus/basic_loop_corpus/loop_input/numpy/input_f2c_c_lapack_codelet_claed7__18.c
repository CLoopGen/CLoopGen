#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;

integer *indxq;
integer i__1;
integer i__;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~64MB to target ~0.01 sec runtime
    indxq = (integer*)aligned_alloc(_Alignof(integer), (data_size + 1) * sizeof(integer));
    if (!indxq) exit(1);
    i__1 = data_size;
}