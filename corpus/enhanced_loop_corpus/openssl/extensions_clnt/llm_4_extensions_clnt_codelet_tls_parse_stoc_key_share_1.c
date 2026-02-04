#include <stdio.h>

#include <inttypes.h>

extern unsigned int group_id;
extern size_t i;
extern  uint16_t *pgroups;
extern size_t num_groups;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < num_groups && group_id != pgroups[i]; i++) {
        // Empty body: condition moved into loop continuation
    }
}
