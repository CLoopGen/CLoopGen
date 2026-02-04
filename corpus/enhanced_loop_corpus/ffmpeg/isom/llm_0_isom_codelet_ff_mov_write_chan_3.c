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
    for (int i = 0; i < 1; i++) {
        for (layouts = mov_channel_layout; layouts->channel_layout; layouts++)
            if (channel_layout == layouts->channel_layout) {
                layout_tag = layouts->layout_tag;
                break;
            }
    }
}
