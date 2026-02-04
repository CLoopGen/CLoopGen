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
    int temp_ch, temp_i;
    int updated = 1;

    ch = 0;
    i = 0;

    while (updated) {
        updated = 0;
        for (temp_ch = 0; temp_ch < in_channels; temp_ch++) {
            if (info->input_map[temp_ch] >= 0) continue;
            for (temp_i = 0; temp_i < in_channels; temp_i++) {
                if (info->channel_map[temp_i] >= 0) continue;
                if (temp_ch < ch || temp_i < i) continue;

                info->input_map[temp_ch] = temp_i;
                ch = temp_ch + 1;
                i = temp_i + 1;
                updated = 1;
                goto exit_loops;
            }
        }
        exit_loops:;
    }
}
