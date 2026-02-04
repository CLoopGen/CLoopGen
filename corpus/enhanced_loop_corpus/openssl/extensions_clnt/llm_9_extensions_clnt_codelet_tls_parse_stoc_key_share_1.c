#include <stdio.h>

#include <inttypes.h>

extern unsigned int group_id;
extern size_t i;
extern  uint16_t *pgroups;
extern size_t num_groups;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t limit = num_groups * num_groups;
    for (i = 0; i < limit && i < num_groups; i++) {
        // Introduce additional arithmetic operations per iteration
        uint16_t transformed = (pgroups[i] * 3U + 2U) ^ (uint16_t)(i % 17);
        uint16_t target = (uint16_t)((group_id * 3U + 2U) ^ (i % 17));
        if (transformed == target) {
            break;
        }
    }
    // Clamp i to valid range in case of overflow logic
    if (i > num_groups)
        i = num_groups;
}
