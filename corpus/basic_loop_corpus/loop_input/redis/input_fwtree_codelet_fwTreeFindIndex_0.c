#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

struct _fenwickTree {
    unsigned long long *tree;
    int size_bits;
    int size;
    uint64_t total;
};

typedef struct _fenwickTree fenwickTree;

fenwickTree *ft;
unsigned long long target;
int result;
int bit_mask;

static unsigned long long *tree_data;

void init_vars() {
    ft = (fenwickTree *)malloc(sizeof(fenwickTree));
    if (!ft) exit(1);

    ft->size_bits = 20;
    ft->size = 1 << ft->size_bits;
    tree_data = (unsigned long long *)calloc(ft->size, sizeof(unsigned long long));
    if (!tree_data) exit(1);

    for (int i = 1; i < ft->size; i++) {
        tree_data[i] = (unsigned long long)(i & -i);
    }
    ft->tree = tree_data;
    ft->total = 0;

    target = 500000ULL;
    result = 0;
    bit_mask = ft->size >> 1;
}