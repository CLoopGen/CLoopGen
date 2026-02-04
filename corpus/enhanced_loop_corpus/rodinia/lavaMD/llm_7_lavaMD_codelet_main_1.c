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
    FOUR_VECTOR *vec = fv_cpu;
    long n = dim_cpu.space_elem;
    float val = 0;
    for (i = 0; i < n; i++) {
        vec[i].v = val;
        vec[i].x = vec[i].v; // RAW dependency: x depends on v
        vec[i].y = vec[i].x; // RAW dependency: y depends on x
        vec[i].z = vec[i].y; // RAW dependency: z depends on y
        val = vec[i].z;       // Loop-carried dependency: val used in next iteration
    }
}
