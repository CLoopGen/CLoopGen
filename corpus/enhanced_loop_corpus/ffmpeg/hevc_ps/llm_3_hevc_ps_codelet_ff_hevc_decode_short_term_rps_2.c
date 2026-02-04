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

extern ShortTermRPS *rps;
extern int delta_poc;
extern int k;
extern int i;
extern int used;
extern int tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Memory Access Pattern Modification - Indirect Access via Index Array
    // Create an auxiliary index array to reorder access to delta_poc and used arrays.
    // Sorting is now performed indirectly through the index mapping.

    int index[32];
    for (i = 0; i < rps->num_delta_pocs; i++) {
        index[i] = i;
    }

    // Insertion sort on the index array based on delta_poc values
    for (i = 1; i < rps->num_delta_pocs; i++) {
        int current_index = index[i];
        delta_poc = rps->delta_poc[current_index];
        used = rps->used[current_index];

        k = i - 1;
        while (k >= 0 && delta_poc < rps->delta_poc[index[k]]) {
            index[k + 1] = index[k];
            k--;
        }
        index[k + 1] = current_index;
    }

    // Reorder the original arrays based on the sorted index
    int32_t temp_delta[32];
    uint8_t temp_used[32];
    for (i = 0; i < rps->num_delta_pocs; i++) {
        temp_delta[i] = rps->delta_poc[index[i]];
        temp_used[i] = rps->used[index[i]];
    }
    // Copy back
    for (i = 0; i < rps->num_delta_pocs; i++) {
        rps->delta_poc[i] = temp_delta[i];
        rps->used[i] = temp_used[i];
    }
}
