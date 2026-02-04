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
    size_t local_idx = idx;
    SRTM_ITEM *current_item = item;
    for (; local_idx > 0 && current_item != ((void *)0); --local_idx) {
        // Increase computational intensity: simulate processing by accessing multiple fields
        volatile uint64_t seq = current_item->seq_num;
        volatile unsigned char temp = current_item->srt_blinded[0] + current_item->srt_blinded[15];
        volatile void *opq = current_item->opaque;
        (void)seq; (void)temp; (void)opq; // Prevent compiler optimization
        current_item = current_item->next_by_srt_blinded;
    }
    idx = local_idx;
    item = current_item;
}
