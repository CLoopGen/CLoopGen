#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct ShortTermRPS {
    unsigned int num_negative_pics;
    int num_delta_pocs;
    int rps_idx_num_delta_pocs;
    int32_t delta_poc[32];
    uint8_t used[32];
} ShortTermRPS;

ShortTermRPS *rps;
int delta_poc;
int k;
int i;
int used;
int tmp;

void init_vars() {
    // Allocate and initialize the ShortTermRPS structure
    rps = (ShortTermRPS*)malloc(sizeof(ShortTermRPS));
    if (!rps) {
        return;
    }

    // Set parameters to ensure loop runs with valid bounds
    rps->num_negative_pics = 0;
    rps->num_delta_pocs = 32;  // Full size of delta_poc array
    rps->rps_idx_num_delta_pocs = 0;

    // Initialize delta_poc and used arrays with descending order to maximize sorting work
    for (int idx = 0; idx < 32; idx++) {
        rps->delta_poc[idx] = 31 - idx;  // Descending: 31, 30, ..., 0
        rps->used[idx] = (uint8_t)(31 - idx);
    }
}