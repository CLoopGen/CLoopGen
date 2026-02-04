#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;

integer *idxq;
integer i__1;
integer i__;
integer nlp1;
integer nlp2;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB to target ~0.01s runtime
    idxq = (integer*)calloc(data_size, sizeof(integer));
    if (!idxq) {
        exit(1);
    }

    nlp1 = 5;
    nlp2 = 1000;
    i__1 = data_size - 1;
}