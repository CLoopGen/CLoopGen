#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    int min;
    int max;
    int thr_num;
    void *data;
} spawn_data;

int loopmax = 131072; // ~128K elements, ensures loop runs ~0.01s
int nthr = 8;
void *data;
int block_size;
int i;
spawn_data *sdata;

void init_vars() {
    block_size = (loopmax + nthr - 1) / nthr; // Ensure full coverage
    data = aligned_alloc(32, loopmax * sizeof(int));
    if (!data) exit(1);

    sdata = calloc(nthr, sizeof(spawn_data));
    if (!sdata) exit(1);
}