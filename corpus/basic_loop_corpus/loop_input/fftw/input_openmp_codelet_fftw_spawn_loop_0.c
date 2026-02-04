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

int loopmax;
int nthr;
void *data;
int block_size;
int i;
spawn_data *sdata;

void init_vars() {
    // Set data size to 64MB for approximately 0.01 sec runtime on modern CPU
    size_t data_size = 64 * 1024 * 1024;
    data = malloc(data_size);
    
    nthr = 8;  // Assume 8 threads
    block_size = (data_size + nthr - 1) / nthr;  // Ensure full coverage
    loopmax = data_size;  // Match data size to avoid out-of-bounds
    
    sdata = malloc(nthr * sizeof(spawn_data));
}