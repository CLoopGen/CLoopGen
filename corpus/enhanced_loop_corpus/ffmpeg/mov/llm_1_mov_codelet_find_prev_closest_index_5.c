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
    for (; i > 0 && e_old[i].timestamp == e_old[i - 1].timestamp; ) {
        if ((flag & 4) || (e_old[i - 1].flags & 1)) {
            *index = i - 1;
        }
        i--;  // Decrement moved inside the loop body, reducing syntactic loop depth (no init/condition/inc in for-header)
    }
}
