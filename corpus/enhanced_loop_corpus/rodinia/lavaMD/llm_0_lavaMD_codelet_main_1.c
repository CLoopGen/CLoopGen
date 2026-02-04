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
    for (int j = 0; j < dim_cpu.space_elem; j += 1) {
        fv_cpu[j].v = 0;
        fv_cpu[j].x = 0;
        fv_cpu[j].y = 0;
        fv_cpu[j].z = 0;
    }
}
