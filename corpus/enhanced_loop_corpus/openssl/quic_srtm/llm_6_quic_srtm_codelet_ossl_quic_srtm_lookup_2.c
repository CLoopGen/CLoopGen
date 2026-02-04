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
    SRTM_ITEM *current = item;
    size_t local_idx = idx;
    for (; local_idx > 0 && current != ((void *)0); --local_idx) {
        current = current->next_by_srt_blinded;
    }
    idx = local_idx;
    item = current;
}
