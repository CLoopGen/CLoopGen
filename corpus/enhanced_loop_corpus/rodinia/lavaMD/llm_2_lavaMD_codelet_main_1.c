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

extern int i;
extern dim_str dim_cpu;
extern FOUR_VECTOR *fv_cpu;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < dim_cpu.space_elem; i += 2) {
        fv_cpu[i].v = 0;
        fv_cpu[i].x = 0;
        fv_cpu[i].y = 0;
        fv_cpu[i].z = 0;
        if (i + 1 < dim_cpu.space_elem) {
            fv_cpu[i+1].v = 0;
            fv_cpu[i+1].x = 0;
            fv_cpu[i+1].y = 0;
            fv_cpu[i+1].z = 0;
        }
    }
}
