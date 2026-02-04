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

extern FLACHeaderMarker *child;
extern int i;
extern FLACHeaderMarker *curr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 2 && curr != child && curr != NULL; i++) {
        int sum = 0;
        for (int j = 0; j < curr->fi.blocksize && j < 16; j++) {
            sum += curr->link_penalty[j % 4] * (j + 1);
        }
        curr->max_score = sum;
        if (curr->next != NULL) {
            curr = curr->next;
        }
    }
}
