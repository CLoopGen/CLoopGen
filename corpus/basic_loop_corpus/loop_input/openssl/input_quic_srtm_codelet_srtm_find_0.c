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

SRTM_ITEM *item = NULL;
SRTM_ITEM *prev = NULL;
uint64_t seq_num = 0;

#define DATA_SIZE (1024 * 512)  // ~512KB of data

static SRTM_ITEM items[DATA_SIZE];

void init_vars() {
    for (int i = 0; i < DATA_SIZE; i++) {
        items[i].next_by_srt_blinded = NULL;
        items[i].opaque = NULL;
        items[i].seq_num = DATA_SIZE - i;  // descending order
        memset(items[i].srt.token, i & 0xFF, 16);
        memset(items[i].srt_blinded, (i + 1) & 0xFF, 16);
    }

    // Link by seq_num in descending order
    for (int i = 0; i < DATA_SIZE - 1; i++) {
        items[i].next_by_seq_num = &items[i + 1];
    }
    items[DATA_SIZE - 1].next_by_seq_num = NULL;

    // Set global state: search for a middle value that will require traversal
    item = &items[0];
    prev = NULL;
    seq_num = DATA_SIZE / 2;  // Ensures about half the list is traversed
}