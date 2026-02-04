#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct ChannelMapInfo {
    int channel_map[32];
    int do_remap;
    int channel_copy[32];
    int do_copy;
    int channel_zero[32];
    int do_zero;
    int input_map[32];
} ChannelMapInfo;

ChannelMapInfo *info;
int in_channels;
int ch;
int i;

void init_vars() {
    in_channels = 32;
    
    info = (ChannelMapInfo*)calloc(1, sizeof(ChannelMapInfo));
    
    for (int idx = 0; idx < 32; idx++) {
        info->channel_map[idx] = -1;
        info->input_map[idx] = -1;
    }
    
    info->do_remap = 1;
    info->do_copy = 1;
    info->do_zero = 1;
    
    ch = 0;
    i = 0;
}