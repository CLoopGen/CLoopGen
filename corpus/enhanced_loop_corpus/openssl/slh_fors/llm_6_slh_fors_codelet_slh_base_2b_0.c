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
    consumed = 0;
    if (b > 0 && b <= 32) {
        for (; consumed < out_len; consumed++) {
            uint32_t temp_total = total;
            uint32_t temp_bits = bits;

            temp_total <<= 8;
            temp_total |= *in++;
            temp_bits += 8;

            while (temp_bits < b) {
                temp_total <<= 8;
                temp_total |= *in++;
                temp_bits += 8;
            }

            temp_bits -= b;
            *out++ = (temp_total >> temp_bits) & mask;

            bits = temp_bits;
            total = temp_total & ((1U << bits) - 1);
        }
    }
}
