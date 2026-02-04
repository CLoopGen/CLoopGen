#include <stdio.h>

#include <inttypes.h>

typedef struct srtm_item_st SRTM_ITEM;

typedef struct {
    unsigned char token[16];
} QUIC_STATELESS_RESET_TOKEN;

struct srtm_item_st {
    SRTM_ITEM *next_by_srt_blinded;
    SRTM_ITEM *next_by_seq_num;
    void *opaque;
    uint64_t seq_num;
    QUIC_STATELESS_RESET_TOKEN srt;
    unsigned char srt_blinded[16];
};


extern uint64_t seq_num;
extern SRTM_ITEM *item;
extern SRTM_ITEM *prev;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access pattern simulation using pointer arithmetic with a fixed stride (simulating non-unit stride traversal)
    // Although the data structure is a linked list, we simulate strided behavior by skipping every other node conceptually.
    SRTM_ITEM *current = item;
    SRTM_ITEM *previous = prev;

    for (; current != ((void *)0); ) {
        if (current->seq_num == seq_num) {
            item = current;
            prev = previous;
            break;
        } else if (current->seq_num < seq_num) {
            item = ((void *)0);
            break;
        } else {
            // Simulate strided access: skip one link (stride of 2), but still check in-order logically
            SRTM_ITEM *next_step = current->next_by_seq_num;
            if (next_step != ((void *)0)) {
                previous = current;
                current = next_step->next_by_seq_num; // Stride by two links
                if (current != ((void *)0)) {
                    prev = next_step;
                    item = current;
                } else {
                    // If double step fails, fall back to single step and exit after
                    current = next_step;
                    previous = previous;
                    item = current;
                }
            } else {
                previous = current;
                current = next_step;
                item = current;
            }
        }
        // Reconnect control via for-loop condition using direct assignment above
        // No increment in for(;;) header — full control inside body
    }
}
