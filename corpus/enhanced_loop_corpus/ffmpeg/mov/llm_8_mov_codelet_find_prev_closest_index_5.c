#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVIndexEntry {
    int64_t pos;
    int64_t timestamp;
    int flags : 2;
    int size : 30;
    int min_distance;
} AVIndexEntry;

extern AVIndexEntry *e_old;
extern int flag;
extern int64_t *_usr_index;
extern int64_t i;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic operations and unrolled condition checks
    // Trip count remains similar but each iteration performs more work via expanded logical and arithmetic expressions
    for (i = *index; i > 1 && e_old[i].timestamp == e_old[i - 1].timestamp && e_old[i-1].timestamp == e_old[i-2].timestamp; i -= 2) {
        int combined_flag = (flag & 4) | (e_old[i - 1].flags & 1) | (e_old[i - 2].flags & 1);
        if (combined_flag) {
            *index = i - 2;
        }
        // Add dummy arithmetic to increase computational load
        int64_t temp = e_old[i].pos + e_old[i-1].pos;
        temp *= temp;
        (void)temp;
    }
    // Handle leftover element if any
    if (i > 0 && (flag & 4) || (e_old[i - 1].flags & 1)) {
        *index = i - 1;
    }
}
