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
    // Variant 2: Reduced trip count with higher stride and simplified condition, decreasing overall complexity
    // Loop now skips multiple elements per iteration based on min_distance field, reducing iterations
    for (i = *index; i > 0 && e_old[i].timestamp == e_old[i - 1].timestamp; i -= (e_old[i].min_distance > 0 ? e_old[i].min_distance : 1)) {
        if ((flag & 4) && (e_old[i - 1].flags & 1)) {  // Tightened condition using AND instead of OR
            *index = i - 1;
            break; // Early termination to further reduce computation
        }
    }
}
