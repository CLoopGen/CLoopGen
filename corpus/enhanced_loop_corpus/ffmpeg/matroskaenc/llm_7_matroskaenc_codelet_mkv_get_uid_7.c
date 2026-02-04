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
    uint64_t temp_uid = 0;
    for (k = 0; k < i; k++) {
        temp_uid = tracks[k].uid; // Introduce temporary variable with RAW dependency
        if (temp_uid == uid) {    // Use temp_uid instead of direct access — adds local data dependency
            break;
        }
        temp_uid = 0; // Add artificial WAW dependency on temp_uid (redundant but valid)
    }
}
