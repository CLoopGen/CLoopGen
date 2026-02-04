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
            box_cpu[nh].x = k;
            box_cpu[nh].y = j;
            box_cpu[nh].z = i;
            box_cpu[nh].number = nh;
            box_cpu[nh].offset = nh * 100;
            box_cpu[nh].nn = 0;
            for (l = -1; l < 2; l++) {
                if ((i + l) >= 0 && (i + l) < dim_cpu.boxes1d_arg) {
                    for (m = -1; m < 2; m++) {
                        if ((j + m) >= 0 && (j + m) < dim_cpu.boxes1d_arg) {
                            for (n = -1; n < 2; n++) {
                                if ((k + n) >= 0 && (k + n) < dim_cpu.boxes1d_arg) {
                                    if (!(l == 0 && m == 0 && n == 0)) {
                                        box_cpu[nh].nei[box_cpu[nh].nn].x = (k + n);
                                        box_cpu[nh].nei[box_cpu[nh].nn].y = (j + m);
                                        box_cpu[nh].nei[box_cpu[nh].nn].z = (i + l);
                                        box_cpu[nh].nei[box_cpu[nh].nn].number = (box_cpu[nh].nei[box_cpu[nh].nn].z * dim_cpu.boxes1d_arg * dim_cpu.boxes1d_arg) + (box_cpu[nh].nei[box_cpu[nh].nn].y * dim_cpu.boxes1d_arg) + box_cpu[nh].nei[box_cpu[nh].nn].x;
                                        box_cpu[nh].nei[box_cpu[nh].nn].offset = box_cpu[nh].nei[box_cpu[nh].nn].number * 100;
                                        box_cpu[nh].nn = box_cpu[nh].nn + 1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            nh = nh + 1;
        }
    }
}
}
