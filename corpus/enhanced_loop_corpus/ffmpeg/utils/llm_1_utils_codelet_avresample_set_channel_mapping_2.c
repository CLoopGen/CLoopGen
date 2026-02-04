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



void loop(){
    for (ch = 0; ch < in_channels; ch++) {
        if (info->input_map[ch] >= 0) continue;
        int found = 0;
        for (i = 0; i < in_channels && !found; i++) {
            if (info->channel_map[i] >= 0) continue;
            info->input_map[ch] = i;
            found = 1;
        }
        if (!found) break;
    }
}
