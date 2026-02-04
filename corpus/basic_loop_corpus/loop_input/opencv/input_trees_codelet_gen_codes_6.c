#include <stdint.h>
#include <stdlib.h>

uint16_t *bl_count;
uint16_t next_code[16];
unsigned int code;
int bits;

void init_vars() {
    bl_count = (uint16_t*)calloc(16, sizeof(uint16_t));
    if (!bl_count) exit(1);

    for (int i = 0; i < 15; i++) {
        bl_count[i] = (i + 1) * 32768;
    }

    code = 0;
}