#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

short runlength;
unsigned char *q;
unsigned char *mark;

unsigned char *mark_base;
unsigned char *q_base;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime estimate

    mark_base = (unsigned char *)aligned_alloc(32, data_size);
    q_base = (unsigned char *)aligned_alloc(32, data_size);

    if (!mark_base || !q_base) {
        exit(1);
    }

    for (size_t i = 0; i < data_size; i++) {
        mark_base[i] = (unsigned char)(i & 0xFF);
    }

    runlength = (short)(data_size / 4); 
    mark = mark_base;
    q = q_base;
}