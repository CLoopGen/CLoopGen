#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

unsigned int group_id;
size_t i;
uint16_t *pgroups;
size_t num_groups;

void init_vars() {
    num_groups = 524288; // Approximately 1MB of data (524288 * 2 bytes)
    pgroups = (uint16_t*)malloc(num_groups * sizeof(uint16_t));
    if (!pgroups) {
        num_groups = 0;
        return;
    }

    for (size_t idx = 0; idx < num_groups; idx++) {
        pgroups[idx] = (uint16_t)(idx + 1);
    }

    group_id = num_groups / 2;
    i = 0;
}