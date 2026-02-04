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
    layout_tag = 0; // Ensure defined state even if no match
    uint32_t found_tag = 0;
    int matched = 0;
    for (layouts = mov_channel_layout; layouts->channel_layout && !matched; layouts++) {
        int64_t candidate_layout = layouts->channel_layout; // Introduce local read (RAW)
        uint32_t candidate_tag = layouts->layout_tag;
        if (channel_layout == candidate_layout) {
            found_tag = candidate_tag;         // WAW dependency on found_tag avoided via single assignment
            matched = 1;                       // WAR: write to matched prevents further iterations
        }
    }
    layout_tag = found_tag; // Final write outside loop body (breaks loop-carried WAW on layout_tag)
}
