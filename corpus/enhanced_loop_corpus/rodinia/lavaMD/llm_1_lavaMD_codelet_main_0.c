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
                int ni = i + l;
                if (ni < 0 || ni >= dim_cpu.boxes1d_arg) continue;
                for (m = -1; m < 2; m++) {
                    int nj = j + m;
                    if (nj < 0 || nj >= dim_cpu.boxes1d_arg) continue;
                    for (n = -1; n < 2; n++) {
                        int nk = k + n;
                        if (nk < 0 || nk >= dim_cpu.boxes1d_arg) continue;
                        if (l == 0 && m == 0 && n == 0) continue;
                        int idx = box_cpu[nh].nn;
                        box_cpu[nh].nei[idx].x = nk;
                        box_cpu[nh].nei[idx].y = nj;
                        box_cpu[nh].nei[idx].z = ni;
                        box_cpu[nh].nei[idx].number = ni * dim_cpu.boxes1d_arg * dim_cpu.boxes1d_arg + nj * dim_cpu.boxes1d_arg + nk;
                        box_cpu[nh].nei[idx].offset = box_cpu[nh].nei[idx].number * 100;
                        box_cpu[nh].nn++;
                    }
                }
            }
            nh++;
        }
    }
}
}
