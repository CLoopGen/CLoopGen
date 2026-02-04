#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct dim_str {
    int cur_arg;
    int arch_arg;
    int boxes1d_arg;
    long number_boxes;
    long box_mem;
    long space_elem;
    long space_mem;
    long space_mem2;
} dim_str;

typedef struct {
    float v;
    float x;
    float y;
    float z;
} FOUR_VECTOR;

int i;
dim_str dim_cpu;
FOUR_VECTOR *fv_cpu;

void init_vars() {
    // Set space_elem to achieve approximately 0.01 seconds runtime
    // Each iteration writes 4 floats (16 bytes). Modern CPUs can handle
    // roughly 1-2 GB/s for memset-like operations, so aim for ~10-20 MB
    // to get ~0.01 sec. Using 4M elements = 16 MB data.
    dim_cpu.space_elem = 4 * 1024 * 1024; // 4 million elements
    
    dim_cpu.number_boxes = 0;
    dim_cpu.box_mem = 0;
    dim_cpu.space_mem = 0;
    dim_cpu.space_mem2 = 0;
    dim_cpu.cur_arg = 0;
    dim_cpu.arch_arg = 0;
    dim_cpu.boxes1d_arg = 0;

    fv_cpu = (FOUR_VECTOR*)calloc(dim_cpu.space_elem, sizeof(FOUR_VECTOR));
    if (!fv_cpu) {
        // In a real scenario we might handle this, but since we're just initializing
        // and the requirement is to be self-contained without main, we proceed
        // with minimal error handling
        dim_cpu.space_elem = 0;
    }
}