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

extern ChannelMapInfo *info;
extern int in_channels;
extern int ch;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int *input_map = info->input_map;
    int *channel_map = info->channel_map;
    for (ch = 0, i = 0; ch < in_channels && i < in_channels; ch++, i++) {
        int input_val = input_map[ch];
        int map_val = channel_map[i];
        if (input_val >= 0) {
            i--; // Compensate increment to reprocess current 'i'
            continue;
        }
        if (map_val >= 0) {
            ch--; // Compensate increment to reprocess current 'ch'
            continue;
        }
        input_map[ch] = i;
    }
}
