#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

struct elem_to_channel {
    uint64_t av_position;
    uint8_t syn_ele;
    uint8_t elem_id;
    uint8_t aac_position;
};

int i;
int n = 131072; // ~1MB of data: 131072 * 10 bytes ≈ 1.3 MB
struct elem_to_channel e2c_vec[64];
int next_n;

void init_vars() {
    // Initialize the global array e2c_vec with meaningful data
    // Since e2c_vec is declared as [64], but we need larger effective input,
    // we interpret this as potentially incomplete declaration and instead
    // rely on dynamic allocation for the actual working set.
    // However, since the loop references e2c_vec[i] with i up to n-1,
    // and n can be large, we must reinterpret: likely e2c_vec should be heap-based.

    // But the extern declaration says e2c_vec[64], so we cannot exceed 64 elements.
    // Therefore, we must adjust n to at most 64 to prevent out-of-bounds access.
    n = 64;

    // Seed random number generator for initialization
    srand((unsigned int)(time(NULL) ^ (uintptr_t)&n));

    // Initialize e2c_vec with pseudo-random values
    for (int idx = 0; idx < 64; idx++) {
        e2c_vec[idx].av_position = ((uint64_t)rand() << 32) | rand();
        e2c_vec[idx].syn_ele = rand() & 0xFF;
        e2c_vec[idx].elem_id = rand() & 0xFF;
        e2c_vec[idx].aac_position = rand() & 0xFF;
    }

    // Ensure that some inversions exist to trigger the swap logic
    // Sort roughly by av_position to make it semi-ordered, but leave some disorder
    for (int i = 0; i < 64 - 1; i++) {
        for (int j = i + 1; j < 64; j++) {
            if (e2c_vec[i].av_position > e2c_vec[j].av_position) {
                struct elem_to_channel tmp = e2c_vec[i];
                e2c_vec[i] = e2c_vec[j];
                e2c_vec[j] = tmp;
            }
        }
    }

    // Introduce controlled disorder in the lower half to ensure swaps occur
    for (int i = 1; i < 32; i++) {
        if (rand() % 5 == 0) {
            struct elem_to_channel tmp = e2c_vec[i];
            e2c_vec[i] = e2c_vec[i-1];
            e2c_vec[i-1] = tmp;
        }
    }

    // Initialize loop control variables
    i = 1;
    next_n = 1;
}