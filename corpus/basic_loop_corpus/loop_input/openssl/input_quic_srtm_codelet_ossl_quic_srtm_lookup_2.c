#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

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

#define DATA_SIZE 524288  // ~512KB of data, target ~0.01s runtime

static SRTM_ITEM items[DATA_SIZE];
size_t idx;
SRTM_ITEM *item;

void init_vars() {
    // Initialize all items in a linked list via next_by_srt_blinded
    for (size_t i = 0; i < DATA_SIZE; ++i) {
        items[i].next_by_srt_blinded = (i == DATA_SIZE - 1) ? NULL : &items[i + 1];
        items[i].next_by_seq_num = NULL;
        items[i].opaque = NULL;
        items[i].seq_num = i;
        memset(items[i].srt.token, (int)(i * 7), 16);
        memset(items[i].srt_blinded, (int)(i * 13), 16);
    }

    // Set up initial state for the loop
    idx = DATA_SIZE / 2;  // Let loop traverse half the list
    item = &items[0];
}