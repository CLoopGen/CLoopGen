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


extern SRTM_ITEM *item;
extern SRTM_ITEM *rh_item;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; rh_item->next_by_srt_blinded != item && rh_item->seq_num < 1000; rh_item = rh_item->next_by_srt_blinded)
        rh_item = rh_item->next_by_seq_num ? rh_item->next_by_seq_num : rh_item;
}
