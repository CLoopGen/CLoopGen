#include <stdio.h>

#include <inttypes.h>

extern  uint8_t *in;
extern uint32_t b;
extern uint32_t *out;
extern size_t out_len;
extern size_t consumed;
extern uint32_t bits;
extern uint32_t total;
extern uint32_t mask;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (consumed = 0; consumed < out_len; consumed++) {
    while (bits < b)
        {
            total <<= 8;
            total += *in++;
            bits += 8;
        }
    bits -= b;
    *out++ = (total >> bits) & mask;
}

}
