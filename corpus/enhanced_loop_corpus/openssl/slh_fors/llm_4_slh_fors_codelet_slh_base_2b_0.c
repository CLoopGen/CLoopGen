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
    if (out_len == 0) return;
    goto check_condition;

    loop_body:
    bits -= b;
    *out++ = (total >> bits) & mask;
    consumed++;

    check_condition:
    if (consumed >= out_len) return;

    // Unrolled control: simulate the while (bits < b) with if-goto chains
    if (bits < b) goto refill_start;
    goto loop_body;

    refill_start:
    total <<= 8;
    total += *in++;
    bits += 8;
    if (bits < b) goto refill_start;

    goto loop_body;
}
