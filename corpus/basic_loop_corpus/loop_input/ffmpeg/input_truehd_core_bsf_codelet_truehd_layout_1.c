#include <stdint.h>

uint64_t thd_layout[13];
int chanmap;
int i;
uint64_t layout;

void init_vars() {
    for (int idx = 0; idx < 13; idx++) {
        thd_layout[idx] = (uint64_t)(idx + 1) * 0x1122334455667788ULL;
    }
    chanmap = 0x1FFF;
    i = 0;
    layout = 0;
}