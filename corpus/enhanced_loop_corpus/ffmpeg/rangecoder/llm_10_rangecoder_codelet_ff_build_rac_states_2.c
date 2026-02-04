#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct RangeCoder {
    int low;
    int range;
    int outstanding_count;
    int outstanding_byte;
    uint8_t zero_state[256];
    uint8_t one_state[256];
    uint8_t *bytestream_start;
    uint8_t *bytestream;
    uint8_t *bytestream_end;
    int overread;
} RangeCoder;

extern RangeCoder *c;
extern int factor;
extern int max_p;
extern  int64_t one;
extern int64_t p;
extern int last_p8;
extern int p8;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 256; i += 2) {
        int temp_p8_1, temp_p8_2;
        int64_t temp_p_1 = p;
        int64_t temp_p_2 = p + ((one - p) * factor + one / 2) >> 32;

        temp_p8_1 = (256 * temp_p_1 + one / 2) >> 32;
        if (temp_p8_1 <= last_p8)
            temp_p8_1 = last_p8 + 1;
        if (last_p8 && last_p8 < 256 && temp_p8_1 <= max_p)
            c->one_state[last_p8] = temp_p8_1;

        temp_p8_2 = (256 * temp_p_2 + one / 2) >> 32;
        if (temp_p8_2 <= temp_p8_1)
            temp_p8_2 = temp_p8_1 + 1;
        if (temp_p8_1 && temp_p8_1 < 256 && temp_p8_2 <= max_p)
            c->one_state[temp_p8_1] = temp_p8_2;

        p = temp_p_2 + ((one - temp_p_2) * factor + one / 2) >> 32;
        last_p8 = temp_p8_2;
    }
}
