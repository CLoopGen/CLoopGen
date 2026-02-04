#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct FLACFrameInfo {
    int samplerate;
    int channels;
    int bps;
    int blocksize;
    int ch_mode;
    int64_t frame_or_sample_num;
    int is_var_size;
} FLACFrameInfo;

typedef struct FLACHeaderMarker {
    int offset;
    int link_penalty[4];
    int max_score;
    FLACFrameInfo fi;
    struct FLACHeaderMarker *next;
    struct FLACHeaderMarker *best_child;
} FLACHeaderMarker;

extern int i;
extern FLACHeaderMarker *curr;
extern int64_t expected_frame_num;
extern int64_t expected_sample_num;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int64_t local_frame_num = expected_frame_num;
    int64_t local_sample_num = expected_sample_num;
    int updated = 0;
    for (i = 0; i < 4 && !updated; i++) {
        int penalty = curr->link_penalty[i];
        int block_size = curr->fi.blocksize;
        if (penalty < 50) {
            local_frame_num += 1;
            local_sample_num += block_size;
            updated = 1;
        }
    }
    expected_frame_num = local_frame_num;
    expected_sample_num = local_sample_num;
}
