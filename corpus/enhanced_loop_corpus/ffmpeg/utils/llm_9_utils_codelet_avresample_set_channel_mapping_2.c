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
    int stride = 2;
    for (ch = 0, i = 0; ch + stride <= in_channels && i + stride <= in_channels; ch += stride, i += stride) {
        for (int s = 0; s < stride; s++) {
            int ch_idx = ch + s;
            int i_idx = i + s;
            if (ch_idx < in_channels && info->input_map[ch_idx] < 0 &&
                i_idx < in_channels && info->channel_map[i_idx] < 0) {
                info->input_map[ch_idx] = i_idx;
            }
        }
    }
    // Handle remaining elements with unit increment
    for (; ch < in_channels && i < in_channels; ch++, i++) {
        if (info->input_map[ch] < 0 && info->channel_map[i] < 0) {
            info->input_map[ch] = i;
        }
    }
}
