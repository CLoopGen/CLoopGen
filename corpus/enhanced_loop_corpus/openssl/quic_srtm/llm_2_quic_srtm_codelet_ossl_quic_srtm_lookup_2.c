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
    // Variant 1: Consecutive memory access pattern using array-like traversal
    // Assuming implicit contiguous memory layout of items, we simulate consecutive access
    // by treating the linked structure as if it were part of a larger array.
    // This variant unrolls the traversal logic but maintains the same termination condition.

    SRTM_ITEM *current = item;
    size_t i = 0;

    for (; i < idx && current != ((void *)0); ++i, current = (SRTM_ITEM*)((char*)current + sizeof(SRTM_ITEM))) {
        // Simulate consecutive memory access assuming dense packing
        // Note: This is realistic only if items are actually laid out contiguously in memory
        if (((SRTM_ITEM*)((char*)current + sizeof(SRTM_ITEM)))->next_by_srt_blinded == ((void *)0))
            break;
    }
    item = current;
}
