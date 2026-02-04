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


extern size_t idx;
extern SRTM_ITEM *item;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    size_t doubled_idx = idx << 1;  // Double the trip count logically
    SRTM_ITEM *current_item = item;
    for (; doubled_idx > 0 && current_item != ((void *)0); --doubled_idx) {
        // Alternate traversal: switch between two linked list pointers every iteration
        if ((doubled_idx & 1) == 0)
            current_item = current_item->next_by_srt_blinded;
        else
            current_item = current_item->next_by_seq_num;
    }
    idx = doubled_idx >> 1;
    item = current_item;
}
