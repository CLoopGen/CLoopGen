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
    int64_t local_index = *index;
    int64_t prev_timestamp, curr_timestamp;
    for (i = local_index; i > 0; i--) {
        curr_timestamp = e_old[i].timestamp;
        prev_timestamp = e_old[i - 1].timestamp;
        if (curr_timestamp != prev_timestamp) break;
        if ((flag & 4) || (e_old[i - 1].flags & 1)) {
            local_index = i - 1;
        }
    }
    *index = local_index;
}
