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
    FLACHeaderMarker *markers[256];
    int count = 0;
    FLACHeaderMarker *temp = best_child->next;
    
    // First pass: collect up to 256 nodes
    while (temp && count < 256) {
        markers[count++] = temp;
        temp = temp->next;
    }
    
    // Second pass: batch update with unrolled operations
    for (int i = 0; i < count; i += 4) {
        if (i + 0 < count) markers[i + 0]->offset -= best_child->offset;
        if (i + 1 < count) markers[i + 1]->offset -= best_child->offset;
        if (i + 2 < count) markers[i + 2]->offset -= best_child->offset;
        if (i + 3 < count) markers[i + 3]->offset -= best_child->offset;
    }
}
