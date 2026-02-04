#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int pmax = 4;
int kmax = 8;
int n = 1 << 24; // 16M elements, ~64MB of data
int pred_order = 32;
uint64_t sums[32][256] = {0};
int i;
int k;
int parts = 16;
uint32_t *data = NULL;
uint32_t *res;
uint32_t *res_end;

void init_vars() {
    data = (uint32_t*)calloc(n, sizeof(uint32_t));
    if (!data) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int idx = 0; idx < n; idx++) {
        data[idx] = (uint32_t)(idx * 71 + 13); // Arbitrary non-zero pattern
    }

    // Ensure pmax is at least 1 to avoid division by zero in shifts
    if (pmax < 1) pmax = 1;

    // Initialize res and res_end temporarily to validate bounds
    res = &data[pred_order];
    res_end = &data[n >> pmax];

    // Adjust parts if needed to prevent out-of-bounds access
    size_t segment_size = n >> pmax;
    if (segment_size == 0) segment_size = 1;
    parts = (int)((n - pred_order) / segment_size);
    if (parts > 256) parts = 256;
    if (parts < 1) parts = 1;

    // Zero-initialize sums array
    for (int k_idx = 0; k_idx < 32; k_idx++) {
        for (int i_idx = 0; i_idx < 256; i_idx++) {
            sums[k_idx][i_idx] = 0;
        }
    }
}