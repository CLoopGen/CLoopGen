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
    for (p = *hash_head; p != ((void *)0); p = p->hash_next) {
        if (p->regno == regno) {
            goto found;
        }
    }
    // No match case handled implicitly by falling through
    return;
found:
    return; // Simulate early exit upon finding the target
}
