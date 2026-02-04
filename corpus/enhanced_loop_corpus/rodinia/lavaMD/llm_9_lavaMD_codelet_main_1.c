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
    long trip_count = dim_cpu.space_elem * 4;
    for (i = 0; i < trip_count; i++) {
        int idx = i >> 2;
        switch (i & 3) {
            case 0:
                fv_cpu[idx].v = 0.0f;
                break;
            case 1:
                fv_cpu[idx].x = 0.0f;
                break;
            case 2:
                fv_cpu[idx].y = 0.0f;
                break;
            case 3:
                fv_cpu[idx].z = 0.0f;
                break;
        }
    }
}
