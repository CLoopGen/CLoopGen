#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct MovChannelLayout {
    int64_t channel_layout;
    uint32_t layout_tag;
} MovChannelLayout;

extern  MovChannelLayout mov_channel_layout[];
extern int64_t channel_layout;
extern  MovChannelLayout *layouts;
extern uint32_t layout_tag;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access (access every second element first, then handle remainder)
    int i;
    int found = 0;

    // First pass: even indices (strided by 2)
    for (i = 0; mov_channel_layout[i].channel_layout != 0; i += 2) {
        if (channel_layout == mov_channel_layout[i].channel_layout) {
            layout_tag = mov_channel_layout[i].layout_tag;
            found = 1;
            break;
        }
    }

    if (!found) {
        // Second pass: odd indices to catch any missed elements
        for (i = 1; mov_channel_layout[i].channel_layout != 0; i += 2) {
            if (channel_layout == mov_channel_layout[i].channel_layout) {
                layout_tag = mov_channel_layout[i].layout_tag;
                break;
            }
        }
    }
}
