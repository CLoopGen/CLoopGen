#include <stdint.h>
#include <stdlib.h>

uint8_t *counter;
uint8_t *cur_pos;

static uint8_t data[256 * 1024 * 1024]; // 256 MB of buffer

void init_vars() {
    counter = data + 256 * 1024 * 1024 - 8; // Point counter to make cur_pos start at counter+7 within bounds
    cur_pos = NULL;
}

__attribute__((constructor))
static void constructor() {
    init_vars();
}