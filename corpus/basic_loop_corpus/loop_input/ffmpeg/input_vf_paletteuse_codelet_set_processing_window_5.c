#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int x_start = 0;
int y_start = 0;
int y = 0;
int y_end = 4096;
uint32_t *prv_srcp;
uint32_t *cur_srcp;
int prv_src_linesize = 4096;
int cur_src_linesize = 4096;
int same_column = 1;

void init_vars() {
    size_t total_size = (size_t)(y_end + 1) * prv_src_linesize * sizeof(uint32_t);
    prv_srcp = (uint32_t *)aligned_alloc(64, total_size);
    cur_srcp = (uint32_t *)aligned_alloc(64, total_size);

    if (!prv_srcp || !cur_srcp) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int i = 0; i <= y_end; i++) {
        for (int j = 0; j < prv_src_linesize; j++) {
            size_t idx = i * prv_src_linesize + j;
            prv_srcp[idx] = (uint32_t)(idx & 0xFFFFF);
            cur_srcp[idx] = (uint32_t)(idx & 0xFFFFF);
        }
    }

    x_start = 0;
    y_start = 0;
    y_end = 4096;
    same_column = 1;
}