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
            int idx = nh;
            box_cpu[idx].x = k;
            box_cpu[idx].y = j;
            box_cpu[idx].z = i;
            box_cpu[idx].number = idx;
            box_cpu[idx].offset = idx * 100;
            box_cpu[idx].nn = 0;
            for (l = -1; l < 2; l++) {
                for (m = -1; m < 2; m++) {
                    for (n = -1; n < 2; n++) {
                        if ((((i + l) >= 0 && (j + m) >= 0 && (k + n) >= 0) == 1 && ((i + l) < dim_cpu.boxes1d_arg && (j + m) < dim_cpu.boxes1d_arg && (k + n) < dim_cpu.boxes1d_arg) == 1) && (l == 0 && m == 0 && n == 0) == 0) {
                            int nx = k + n;
                            int ny = j + m;
                            int nz = i + l;
                            int nnum = nz * dim_cpu.boxes1d_arg * dim_cpu.boxes1d_arg + ny * dim_cpu.boxes1d_arg + nx;
                            box_cpu[idx].nei[box_cpu[idx].nn].x = nx;
                            box_cpu[idx].nei[box_cpu[idx].nn].y = ny;
                            box_cpu[idx].nei[box_cpu[idx].nn].z = nz;
                            box_cpu[idx].nei[box_cpu[idx].nn].number = nnum;
                            box_cpu[idx].nei[box_cpu[idx].nn].offset = nnum * 100;
                            box_cpu[idx].nn = box_cpu[idx].nn + 1;
                        }
                    }
                }
            }
            nh = nh + 1;
        }
    }
}
}
