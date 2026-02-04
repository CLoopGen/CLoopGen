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

FLACHeaderMarker *child;
int i;
FLACHeaderMarker *curr;

#define LIST_SIZE 100000

static FLACHeaderMarker markers[LIST_SIZE];

void init_vars() {
    for (int idx = 0; idx < LIST_SIZE; idx++) {
        markers[idx].offset = idx;
        for (int j = 0; j < 4; j++) {
            markers[idx].link_penalty[j] = rand() % 100;
        }
        markers[idx].max_score = rand() % 1000;
        markers[idx].fi.samplerate = 44100;
        markers[idx].fi.channels = 2;
        markers[idx].fi.bps = 16;
        markers[idx].fi.blocksize = 1024;
        markers[idx].fi.ch_mode = 0;
        markers[idx].fi.frame_or_sample_num = idx;
        markers[idx].fi.is_var_size = 0;
        markers[idx].best_child = NULL;
        if (idx == LIST_SIZE - 1) {
            markers[idx].next = NULL;
        } else {
            markers[idx].next = &markers[idx + 1];
        }
    }

    child = &markers[50];
    curr = &markers[0];
}