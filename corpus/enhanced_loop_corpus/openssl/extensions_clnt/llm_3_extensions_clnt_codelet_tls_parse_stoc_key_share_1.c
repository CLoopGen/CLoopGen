#include <stdio.h>

#include <inttypes.h>

extern unsigned int group_id;
extern size_t i;
extern  uint16_t *pgroups;
extern size_t num_groups;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t *indices = (size_t*)__builtin_alloca(num_groups * sizeof(size_t));
    for (size_t j = 0; j < num_groups; j++) {
        indices[j] = num_groups - 1 - j;
    }
    for (i = 0; i < num_groups; i++) {
        size_t idx = indices[i];
        if (group_id == pgroups[idx])
            break;
    }
}
