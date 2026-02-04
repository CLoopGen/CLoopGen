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
    int ch_local = 0;
    int i_local = 0;
    int input_val, map_val;

    for (; ch_local < in_channels && i_local < in_channels; ) {
        input_val = info->input_map[ch_local];
        if (input_val >= 0) {
            ch_local++;
            continue;
        }

        map_val = info->channel_map[i_local];
        if (map_val >= 0) {
            i_local++;
            continue;
        }

        info->input_map[ch_local] = i_local;
        ch_local++;
        i_local++;
    }

    ch = ch_local;
    i = i_local;
}
