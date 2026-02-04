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
    for (curr = best_child->next; curr && curr->max_score >= 0; curr = curr->next)
        if (best_child->offset > 0)
            curr->offset -= best_child->offset;
}
