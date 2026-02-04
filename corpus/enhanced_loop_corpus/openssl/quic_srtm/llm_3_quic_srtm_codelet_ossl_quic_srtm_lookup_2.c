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
    // Variant 2: Strided memory access pattern
    // Instead of traversing every node, we skip nodes based on a stride derived from seq_num
    // This creates non-unit stride access, simulating irregular or data-dependent traversal

    size_t remaining = idx;
    SRTM_ITEM *current = item;

    for (; remaining > 0 && current != ((void *)0); remaining--) {
        // Use sequence number to determine next jump offset (simulated strided access)
        uint64_t stride = (current->seq_num % 3) + 1;  // Stride of 1, 2, or 3
        SRTM_ITEM *next = current;

        // Jump forward by 'stride' links in the list
        for (uint64_t s = 0; s < stride; ++s) {
            if (next == ((void *)0)) break;
            next = next->next_by_srt_blinded;
        }

        current = next;
    }

    item = current;
}
