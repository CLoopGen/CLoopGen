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

int i;
int j;
int k;
int l;
int m;
int n;
dim_str dim_cpu;
box_str *box_cpu;
int nh;

void init_vars() {
    dim_cpu.boxes1d_arg = 50;
    dim_cpu.number_boxes = (long)dim_cpu.boxes1d_arg * dim_cpu.boxes1d_arg * dim_cpu.boxes1d_arg;
    dim_cpu.box_mem = dim_cpu.number_boxes * sizeof(box_str);
    dim_cpu.space_elem = 0;
    dim_cpu.space_mem = 0;
    dim_cpu.space_mem2 = 0;
    dim_cpu.cur_arg = 0;
    dim_cpu.arch_arg = 0;

    box_cpu = (box_str*)calloc(dim_cpu.number_boxes, sizeof(box_str));
    if (!box_cpu) {
        exit(1);
    }

    nh = 0;
}