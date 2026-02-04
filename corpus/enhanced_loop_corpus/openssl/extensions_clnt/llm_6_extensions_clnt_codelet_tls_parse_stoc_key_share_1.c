#include <stdio.h>

#include <inttypes.h>

extern unsigned int group_id;
extern size_t i;
extern  uint16_t *pgroups;
extern size_t num_groups;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp_index = 0;
    for (i = 0; i < num_groups; i++) {
        temp_index = i; // Introduce WAW dependency on temp_index (though last write dominates)
        if (group_id == pgroups[i]) {
            temp_index = i; // Reinforce WAW: same variable written conditionally
            break;
        }
    }
    i = temp_index; // Data dependency: final value of i depends on temp_index, creating a RAW hazard
}
