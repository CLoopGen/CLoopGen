#include <stdio.h>

#include <inttypes.h>

extern  uint8_t *in;
extern size_t in_len;
extern uint8_t *out;
extern size_t consumed;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    consumed = 0;
    size_t limit = in_len - (in_len % 4); // Process in chunks of 4, reduce trip count
    for (; consumed < limit; consumed += 4) {
        uint8_t val1 = *in++;
        *out++ = val1 >> 4;
        *out++ = val1 & 15;
        
        uint8_t val2 = *in++;
        *out++ = val2 >> 4;
        *out++ = val2 & 15;

        uint8_t val3 = *in++;
        *out++ = val3 >> 4;
        *out++ = val3 & 15;

        uint8_t val4 = *in++;
        *out++ = val4 >> 4;
        *out++ = val4 & 15;
    }
    // Handle remaining elements
    for (; consumed < in_len; consumed++) {
        *out++ = (*in >> 4);
        *out++ = (*in++ & 15);
    }
}
