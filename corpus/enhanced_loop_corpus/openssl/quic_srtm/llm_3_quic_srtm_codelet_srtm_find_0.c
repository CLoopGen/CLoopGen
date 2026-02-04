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



void loop() {
    // Variant 2: Indirect access via an array-like lookup using a dynamically built table (indirect addressing)
    // We pre-scan the list to build an array of pointers (simulating indirect indexing), then search that array
    #define MAX_ITEMS 1024
    SRTM_ITEM *item_array[MAX_ITEMS];
    int count = 0;
    SRTM_ITEM *temp = item;

    // Build indirect access table (array of pointers)
    while (temp != ((void *)0) && count < MAX_ITEMS - 1) {
        item_array[count++] = temp;
        temp = temp->next_by_seq_num;
    }

    // Reset result
    item = ((void *)0);

    // Traverse the array using indirect indexed access (i.e., accessing list elements via array index)
    for (int i = 0; i < count; i++) {
        SRTM_ITEM *current = item_array[i]; // Indirect access through array
        if (current->seq_num == seq_num) {
            item = current;
            prev = (i > 0) ? item_array[i - 1] : ((void *)0);
            break;
        } else if (current->seq_num < seq_num) {
            item = ((void *)0);
            break;
        }
        // Track predecessor for consistency with original logic
        if (i + 1 < count && item_array[i + 1] != ((void *)0)) {
            prev = current;
        }
    }
}
