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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with forward traversal using pointer arithmetic
    int limit = rps->num_negative_pics >> 1;
    int32_t *delta_ptr = rps->delta_poc;
    uint8_t *used_ptr = rps->used;
    for (i = 0; i < limit; i++) {
        delta_poc = delta_ptr[i];
        used = used_ptr[i];
        delta_ptr[i] = delta_ptr[k];
        used_ptr[i] = used_ptr[k];
        delta_ptr[k] = delta_poc;
        used_ptr[k] = used;
        k--;
    }
}
