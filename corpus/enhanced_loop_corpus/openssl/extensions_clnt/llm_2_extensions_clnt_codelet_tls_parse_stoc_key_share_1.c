#include <stdio.h>

#include <inttypes.h>

extern unsigned int group_id;
extern size_t i;
extern  uint16_t *pgroups;
extern size_t num_groups;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t stride = 2;
    for (i = 0; i < num_groups; i += stride) {
        if (i + 1 < num_groups) {
            if (group_id == pgroups[i])
                break;
        } else {
            if (group_id == pgroups[i])
                break;
        }
    }
}
