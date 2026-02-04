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
    int found = 0;
    for (k = 0; k < i && !found; k++) {
        if (tracks[k].uid == uid) {
            found = 1;
            k--; // Introduce a WAW dependency on k: write after write in same iteration
        }
    }
    if (found) {
        k++; // Compensate for the extra decrement to maintain original semantics (k points to matching index)
    }
}
