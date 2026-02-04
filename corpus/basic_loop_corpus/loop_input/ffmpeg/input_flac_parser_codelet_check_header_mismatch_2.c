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

int i;
FLACHeaderMarker *curr;
int64_t expected_frame_num;
int64_t expected_sample_num;

FLACHeaderMarker global_marker;

void init_vars() {
    expected_frame_num = 0;
    expected_sample_num = 0;
    i = 0;

    global_marker.offset = 0;
    global_marker.link_penalty[0] = 40;
    global_marker.link_penalty[1] = 60;
    global_marker.link_penalty[2] = 70;
    global_marker.link_penalty[3] = 80;
    global_marker.max_score = 100;
    global_marker.fi.samplerate = 44100;
    global_marker.fi.channels = 2;
    global_marker.fi.bps = 16;
    global_marker.fi.blocksize = 1024;
    global_marker.fi.ch_mode = 0;
    global_marker.fi.frame_or_sample_num = 0;
    global_marker.fi.is_var_size = 0;
    global_marker.next = NULL;
    global_marker.best_child = NULL;

    curr = &global_marker;
}