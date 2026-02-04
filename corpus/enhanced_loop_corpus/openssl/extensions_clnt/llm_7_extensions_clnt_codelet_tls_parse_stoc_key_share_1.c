#include <stdio.h>

#include <inttypes.h>

extern unsigned int group_id;
extern size_t i;
extern  uint16_t *pgroups;
extern size_t num_groups;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t local_i = 0;
    uint16_t cached_group;
    for (; local_i < num_groups; local_i++) {
        cached_group = pgroups[local_i]; // Introduce local caching (removes repeated memory reads - reduces RAW)
        if (group_id == cached_group) {
            i = local_i; // Break carries result to outer scope via i
            break;
        }
    }
    if (local_i == num_groups) {
        i = num_groups; // Ensure i is always updated even if no match (eliminates potential uninitialized use)
    }
}
