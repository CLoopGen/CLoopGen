#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

struct elem_to_channel {
    uint64_t av_position;
    uint8_t syn_ele;
    uint8_t elem_id;
    uint8_t aac_position;
};

int i;
int n = 131072; // Size chosen to achieve ~0.01 sec runtime
struct elem_to_channel e2c_vec[64];
int next_n;

void init_vars() {
    // Since e2c_vec is declared as [64] but used up to index `n-1` where n can be 131072,
    // there is a mismatch. We must reconcile this: the extern declaration implies fixed size 64,
    // but loop logic suggests larger array usage.

    // However, the original extern says: "extern struct elem_to_channel e2c_vec[64];"
    // So we cannot change its size. Therefore, we must limit `n` to 64 to prevent out-of-bounds access.

    n = 64; // Constrain n to match declared size of e2c_vec

    // Initialize e2c_vec with descending av_position to trigger swaps
    for (int idx = 0; idx < n; idx++) {
        e2c_vec[idx].av_position = (uint64_t)(n - idx); // Descending order
        e2c_vec[idx].syn_ele = (uint8_t)(idx % 256);
        e2c_vec[idx].elem_id = (uint8_t)((idx + 10) % 256);
        e2c_vec[idx].aac_position = (uint8_t)((idx + 5) % 128);
    }

    // Ensure that the loop condition triggers swaps
    // Initial state has e2c_vec[i-1].av_position > e2c_vec[i].av_position for all i
    // So all adjacent pairs will swap, propagating smaller values forward

    i = 1; // Initial loop index
    next_n = 1; // Initial value
}