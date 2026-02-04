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
    // Variant 1: Strided memory access pattern
    // Simulate strided traversal by skipping every other element in the hash chain
    struct cse_reg_info *current = *hash_head;
    for (int i = 0; current != ((void *)0); i++, current = current->hash_next) {
        if (i % 2 == 0) {  // Only check on even strides
            if (current->regno == regno) {
                p = current;
                break;
            }
        } else {
            p = ((void *)0);  // Invalidate p if not found on valid stride
        }
        // Advance one more step if possible to create stride of 2
        if (current->hash_next != ((void *)0))
            current = current->hash_next;
    }
}
