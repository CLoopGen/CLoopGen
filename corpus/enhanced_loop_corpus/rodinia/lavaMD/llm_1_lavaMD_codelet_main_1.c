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
    for (int outer = 0; outer < dim_cpu.space_mem2; outer += 1) {
        for (int inner = 0; inner < dim_cpu.box_mem; inner += 1) {
            long idx = outer * dim_cpu.box_mem + inner;
            if (idx < dim_cpu.space_elem) {
                fv_cpu[idx].v = 0;
                fv_cpu[idx].x = 0;
                fv_cpu[idx].y = 0;
                fv_cpu[idx].z = 0;
            }
        }
    }
}
