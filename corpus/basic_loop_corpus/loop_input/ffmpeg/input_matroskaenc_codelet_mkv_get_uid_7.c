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

mkv_track *tracks;
int i;
uint64_t uid;
int k;

void init_vars() {
    i = 2000000;
    tracks = (mkv_track*)calloc(i, sizeof(mkv_track));
    if (!tracks) {
        exit(1);
    }

    for (int j = 0; j < i; j++) {
        tracks[j].uid = j + 1000;
    }

    uid = i + 1000 - 1;
    k = 0;
}