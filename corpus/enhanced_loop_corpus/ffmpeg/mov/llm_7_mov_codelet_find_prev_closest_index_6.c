#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct MOVStts {
    unsigned int count;
    int duration;
} MOVStts;

extern MOVStts *ctts_data;
extern int64_t ctts_count;
extern int64_t *_usr_index;
extern int64_t *ctts_index;
extern int64_t *ctts_sample;
extern int64_t index_ctts_count;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
    int64_t local_sample = *ctts_sample;
    int64_t local_index = *ctts_index;
    for (index_ctts_count = 0; index_ctts_count < *index; index_ctts_count++) {
        if (local_index < ctts_count) {
            local_sample++;
            if (ctts_data[local_index].count == local_sample) {
                local_index++;
                local_sample = 0;
            }
        }
    }
    *ctts_sample = local_sample;
    *ctts_index = local_index;
}
