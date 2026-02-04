#include <stdio.h>

#include <inttypes.h>

struct cse_reg_info {
    struct cse_reg_info *hash_next;
    struct cse_reg_info *next;
    unsigned int regno;
    int reg_qty;
    int reg_tick;
    int reg_in_table;
};


extern unsigned int regno;
extern struct cse_reg_info **hash_head;
extern struct cse_reg_info *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive-like access using array emulation via pointer chasing
    // Pre-scan to collect elements into a simulated contiguous buffer (in practice, this would be cache-friendly)
    struct cse_reg_info *buffer[256];  // Small local buffer to simulate contiguous storage
    int count = 0;
    struct cse_reg_info *it = *hash_head;

    // Fill buffer with up to 256 elements from hash_next chain
    while (it != ((void *)0) && count < 255) {
        buffer[count++] = it;
        it = it->hash_next;
    }

    p = ((void *)0);
    // Now traverse the "contiguous" buffer instead of following pointers
    for (int i = 0; i < count; i++) {
        if (buffer[i]->regno == regno) {
            p = buffer[i];
            break;
        }
    }
}
