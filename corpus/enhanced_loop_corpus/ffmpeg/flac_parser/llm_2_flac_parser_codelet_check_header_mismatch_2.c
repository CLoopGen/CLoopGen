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
    // Variant 1: Consecutive memory access pattern using array indexing with pointer arithmetic
    FLACHeaderMarker *temp = curr;
    int penalties[4];
    for (int j = 0; j < 4; j++) {
        penalties[j] = temp->link_penalty[j];
    }
    for (i = 0; i < 4; ++i) {
        if (penalties[i] < 50) {
            expected_frame_num++;
            expected_sample_num += temp->fi.blocksize;
            break;
        }
    }
}
