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
    MovChannelLayout *temp = mov_channel_layout;
    layout_tag = 0; // Initialize to avoid undefined behavior if no match
    for (int i = 0; temp[i].channel_layout != 0; ++i) {
        int64_t current_layout = temp[i].channel_layout;
        if (channel_layout == current_layout) {
            layout_tag = temp[i].layout_tag;
            break;
        }
    }
}
