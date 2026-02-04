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
    uint64_t sum = 0;
    for (; rh_item->next_by_srt_blinded != item; rh_item = rh_item->next_by_srt_blinded) {
        sum += rh_item->seq_num; // Introduces RAW dependency: read seq_num to accumulate sum (not carried across iterations in stored form)
        rh_item->srt.token[0] ^= sum & 0xFF; // Introduces WAR/WAW by modifying token based on computed sum
    }
    // Sum is local, so no loop-carried dependency on sum itself; mutation breaks pure pointer-chasing with data feedback
}
