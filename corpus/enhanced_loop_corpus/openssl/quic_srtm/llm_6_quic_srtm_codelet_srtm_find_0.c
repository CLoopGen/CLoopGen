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



void loop(){
    SRTM_ITEM *current = item;
    for (; current != ((void *)0); ) {
        if (current->seq_num == seq_num) {
            item = current;
            break;
        } else if (current->seq_num < seq_num) {
            item = ((void *)0);
            break;
        }
        prev = current;
        current = current->next_by_seq_num;
    }
}
