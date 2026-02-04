#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const uint8_t ff_reverse[256];
extern  uint8_t *buf;
extern int buf_size;
extern uint32_t *o;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t val1 = 0, val2 = 0;
    const uint8_t *local_buf = buf;
    int local_size = buf_size;

    for (; local_size > 6; local_size -= 7, local_buf += 7) {
        val1 = ((unsigned int)ff_reverse[local_buf[2]] << 24);
        val1 |= (ff_reverse[local_buf[1]] << 16);
        val1 |= (ff_reverse[local_buf[0]] << 8);
        *o++ = val1;

        val2 = ((unsigned int)ff_reverse[local_buf[6] & 240] << 28);
        val2 |= (ff_reverse[local_buf[5]] << 20);
        val2 |= (ff_reverse[local_buf[4]] << 12);
        val2 |= (ff_reverse[local_buf[3] & 15] << 4);
        *o++ = val2;
    }

    buf += (buf_size - local_size);
    buf_size = local_size;
}
