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

FLACHeaderMarker *curr;
FLACHeaderMarker *best_child;

#define NUM_NODES (1 << 20)

static FLACHeaderMarker* nodes;

void init_vars() {
    nodes = calloc(NUM_NODES, sizeof(FLACHeaderMarker));
    if (!nodes) exit(1);

    for (int i = 0; i < NUM_NODES; ++i) {
        nodes[i].offset = (i + 1) * 100;
        nodes[i].link_penalty[0] = i % 4;
        nodes[i].link_penalty[1] = i % 3;
        nodes[i].link_penalty[2] = i % 5;
        nodes[i].link_penalty[3] = i % 7;
        nodes[i].max_score = i * 2;
        nodes[i].fi.samplerate = 44100;
        nodes[i].fi.channels = 2;
        nodes[i].fi.bps = 16;
        nodes[i].fi.blocksize = 1024;
        nodes[i].fi.ch_mode = 0;
        nodes[i].fi.frame_or_sample_num = i;
        nodes[i].fi.is_var_size = (i % 2);
        if (i < NUM_NODES - 1)
            nodes[i].next = &nodes[i + 1];
        else
            nodes[i].next = NULL;
        nodes[i].best_child = NULL;
    }

    best_child = &nodes[0];
    curr = NULL;
}