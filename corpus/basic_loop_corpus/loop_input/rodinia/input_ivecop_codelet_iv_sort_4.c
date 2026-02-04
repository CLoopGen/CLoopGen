#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

typedef struct {
    uint32_t size;
    uint32_t max_size;
    uint32_t *pe;
} PERM;

PERM *order;
int *x_ive;
int tmp;
int v;
int i;
int j;
int l;
int r;
int tmp_i;
int stack[60];
int sp;

static int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void init_vars() {
    const int data_size = 1 << 20; // 1 million elements (~4MB for ints)

    x_ive = (int*)malloc(data_size * sizeof(int));
    if (!x_ive) {
        exit(1);
    }

    // Seed random number generator for diverse input
    srand(time(NULL));

    // Initialize with random data to ensure non-trivial sorting behavior
    for (int idx = 0; idx < data_size; ++idx) {
        x_ive[idx] = rand() % data_size;
    }

    // Allocate and initialize order structure
    order = (PERM*)malloc(sizeof(PERM));
    if (!order) {
        exit(1);
    }
    order->size = data_size;
    order->max_size = data_size;
    order->pe = (uint32_t*)malloc(data_size * sizeof(uint32_t));
    if (!order->pe) {
        exit(1);
    }
    for (uint32_t idx = 0; idx < data_size; ++idx) {
        order->pe[idx] = idx;
    }

    // Set initial partition bounds for full array
    l = 0;
    r = data_size - 1;

    // Initialize stack pointer
    sp = 0;

    // Initialize other scalar variables to safe values
    tmp = 0;
    v = 0;
    i = 0;
    j = 0;
    tmp_i = 0;

    // Pre-warm cache by accessing memory
    volatile int sink = x_ive[0] + order->pe[0];
    (void)sink;
}