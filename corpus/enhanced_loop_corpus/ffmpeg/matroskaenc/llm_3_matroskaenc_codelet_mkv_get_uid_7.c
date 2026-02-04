#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct mkv_track {
    int write_dts;
    int has_cue;
    uint64_t uid;
    unsigned int track_num;
    int track_num_size;
    int sample_rate;
    int64_t sample_rate_offset;
    int64_t last_timestamp;
    int64_t duration;
    int64_t duration_offset;
    int64_t codecpriv_offset;
    int64_t ts_offset;
} mkv_track;

extern  mkv_track *tracks;
extern int i;
extern uint64_t uid;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward access with manual pointer arithmetic instead of array indexing
    mkv_track *current = tracks;
    mkv_track *end = tracks + i;
    for (k = 0; current < end; k++, current++) {
        if (current->uid == uid)
            break;
    }
}
