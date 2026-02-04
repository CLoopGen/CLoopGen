#include <stdio.h>

#include <inttypes.h>

extern unsigned int group_id;
extern size_t i;
extern  uint16_t *pgroups;
extern size_t num_groups;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t step = 2;
    for (i = 0; i < num_groups; i += step) {
        if (group_id == pgroups[i]) {
            break;
        }
        // Add extra arithmetic to increase computational intensity
        uint16_t temp = pgroups[i] + (pgroups[i] >> 1);
        if (temp == group_id + 1) {
            i++;
            break;
        }
    }
    // Handle potential overshoot due to step size
    if (i >= num_groups && (num_groups % 2) == 0) {
        i = num_groups - 1;
        if (group_id == pgroups[i])
            return;
    }
}
