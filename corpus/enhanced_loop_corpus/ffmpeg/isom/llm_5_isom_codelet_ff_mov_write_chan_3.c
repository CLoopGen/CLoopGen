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



void loop(){
    layout_tag = 0;
    for (layouts = mov_channel_layout; layouts->channel_layout; layouts++) {
        if (channel_layout == layouts->channel_layout) {
            layout_tag = layouts->layout_tag;
            return;
        }
    }
}
