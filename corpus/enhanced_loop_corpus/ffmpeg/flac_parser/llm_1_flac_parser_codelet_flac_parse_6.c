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

extern FLACHeaderMarker *curr;
extern FLACHeaderMarker *best_child;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    FLACHeaderMarker *outer_curr = best_child->next;
    while (outer_curr) {
        outer_curr->offset -= best_child->offset;
        FLACHeaderMarker *inner_curr = outer_curr->next;
        if (inner_curr) {
            inner_curr->offset -= best_child->offset;
        }
        outer_curr = outer_curr->next ? outer_curr->next->next : NULL;
    }
}
