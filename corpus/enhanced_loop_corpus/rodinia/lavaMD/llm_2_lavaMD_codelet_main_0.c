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

typedef struct nei_str {
    int x;
    int y;
    int z;
    int number;
    long offset;
} nei_str;

typedef struct box_str {
    int x;
    int y;
    int z;
    int number;
    long offset;
    int nn;
    nei_str nei[26];
} box_str;

extern int i;
extern int j;
extern int k;
extern int l;
extern int m;
extern int n;
extern dim_str dim_cpu;
extern box_str *box_cpu;
extern int nh;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < dim_cpu.boxes1d_arg; i++) {
    for (j = 0; j < dim_cpu.boxes1d_arg; j++) {
        for (k = 0; k < dim_cpu.boxes1d_arg; k++) {
            int idx = i * dim_cpu.boxes1d_arg * dim_cpu.boxes1d_arg + j * dim_cpu.boxes1d_arg + k;
            box_cpu[nh].x = k;
            box_cpu[nh].y = j;
            box_cpu[nh].z = i;
            box_cpu[nh].number = idx;
            box_cpu[nh].offset = idx * 100;
            box_cpu[nh].nn = 0;
            for (l = -1; l < 2; l++) {
                for (m = -1; m < 2; m++) {
                    for (n = -1; n < 2; n++) {
                        int ni = i + l, nj = j + m, nk = k + n;
                        if ((ni >= 0 && nj >= 0 && nk >= 0) && 
                            (ni < dim_cpu.boxes1d_arg && nj < dim_cpu.boxes1d_arg && nk < dim_cpu.boxes1d_arg) && 
                            !(l == 0 && m == 0 && n == 0)) {
                            int nei_idx = ni * dim_cpu.boxes1d_arg * dim_cpu.boxes1d_arg + nj * dim_cpu.boxes1d_arg + nk;
                            nei_str* neighbor = &box_cpu[nh].nei[box_cpu[nh].nn];
                            neighbor->x = nk;
                            neighbor->y = nj;
                            neighbor->z = ni;
                            neighbor->number = nei_idx;
                            neighbor->offset = nei_idx * 100;
                            box_cpu[nh].nn++;
                        }
                    }
                }
            }
            nh = nh + 1;
        }
    }
}
}
