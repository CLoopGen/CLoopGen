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
    const size_t data_size = 128 * 1024 * 1024; // 128 MB
    idxq = (integer*)aligned_alloc(32, data_size * sizeof(integer));
    if (!idxq) {
        exit(1);
    }

    for (size_t i = 0; i < data_size; ++i) {
        idxq[i] = i;
    }

    nlp1 = 100;
    nlp2 = 1000;
    i__1 = data_size - 1;
}