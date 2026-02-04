#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct MovChannelLayout {
    int64_t channel_layout;
    uint32_t layout_tag;
} MovChannelLayout;

MovChannelLayout mov_channel_layout[1000000];

int64_t channel_layout;
MovChannelLayout *layouts;
uint32_t layout_tag;

void init_vars() {
    for (int i = 0; i < 999999; i++) {
        mov_channel_layout[i].channel_layout = ((int64_t)rand() << 32) | rand();
        mov_channel_layout[i].layout_tag = rand();
    }
    mov_channel_layout[999999].channel_layout = 0;
    mov_channel_layout[999999].layout_tag = 0;

    channel_layout = mov_channel_layout[500000].channel_layout;

    layouts = NULL;
    layout_tag = 0;
}