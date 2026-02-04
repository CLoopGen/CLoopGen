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

#define DATA_SIZE 50000

SRTM_ITEM items[DATA_SIZE];
SRTM_ITEM *item;
SRTM_ITEM *rh_item;

void init_vars() {
    for (int i = 0; i < DATA_SIZE; i++) {
        items[i].next_by_srt_blinded = &items[(i + 1) % DATA_SIZE];
        items[i].next_by_seq_num = NULL;
        items[i].opaque = NULL;
        items[i].seq_num = i;
        for (int j = 0; j < 16; j++) {
            items[i].srt.token[j] = (unsigned char)(i ^ j);
            items[i].srt_blinded[j] = (unsigned char)(i + j);
        }
    }

    item = &items[DATA_SIZE - 1];
    rh_item = &items[0];
}