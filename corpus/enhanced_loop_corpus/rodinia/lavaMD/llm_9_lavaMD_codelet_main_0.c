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
int bx = dim_cpu.boxes1d_arg;
int total_boxes = bx * bx * bx;
for (nh = 0; nh < total_boxes; nh++) {
    i = nh / (bx * bx);
    int rem = nh % (bx * bx);
    j = rem / bx;
    k = rem % bx;

    box_cpu[nh].x = k;
    box_cpu[nh].y = j;
    box_cpu[nh].z = i;
    box_cpu[nh].number = nh;
    box_cpu[nh].offset = nh * 100;
    box_cpu[nh].nn = 0;

    for (l = -1; l <= 1; l++) {
        for (m = -1; m <= 1; m++) {
            for (n = -1; n <= 1; n++) {
                if (l == 0 && m == 0 && n == 0) continue;
                int ni = i + l;
                int nj = j + m;
                int nk = k + n;
                if (ni >= 0 && nj >= 0 && nk >= 0 && ni < bx && nj < bx && nk < bx) {
                    int nei_idx = box_cpu[nh].nn;
                    box_cpu[nh].nei[nei_idx].x = nk;
                    box_cpu[nh].nei[nei_idx].y = nj;
                    box_cpu[nh].nei[nei_idx].z = ni;
                    long num = ni * bx * bx + nj * bx + nk;
                    box_cpu[nh].nei[nei_idx].number = num;
                    box_cpu[nh].nei[nei_idx].offset = num * 100;
                    box_cpu[nh].nn++;
                }
            }
        }
    }
}
}
