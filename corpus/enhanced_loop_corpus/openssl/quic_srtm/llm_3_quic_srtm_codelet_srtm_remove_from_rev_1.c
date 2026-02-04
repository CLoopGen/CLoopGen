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



void loop() {
    // Variant 2: Indirect access via an array-like index using a pointer array built on-the-fly
    // Simulates indirect indexing into a dynamically collected list of nodes
    SRTM_ITEM *path[256];  // Assume max path length
    int count = 0;
    SRTM_ITEM *temp = rh_item;

    // Traverse and record pointers (indirect access preparation)
    while (temp != item && temp->next_by_srt_blinded != item && count < 255) {
        path[count++] = temp;
        temp = temp->next_by_srt_blinded;
    }
    path[count] = temp;

    // Now traverse indirectly using indices with pointer lookups
    for (int i = 0; i < count && path[i]->next_by_srt_blinded != item; i++) {
        temp = path[i];
    }
    rh_item = temp;
}
