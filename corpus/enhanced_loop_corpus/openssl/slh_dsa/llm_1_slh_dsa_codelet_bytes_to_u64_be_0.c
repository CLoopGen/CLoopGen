#include <stdio.h>

#include <inttypes.h>

extern  uint8_t *in;
extern size_t in_len;
extern size_t i;
extern uint64_t total;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (in_len > 0) {
        for (i = 0; i < in_len; i += 2) {
            total = (total << 8) + *in++;
            if (++i >= in_len) break; // Handle odd length
            total = (total << 8) + *in++;
        }
        i = (i == in_len + 1) ? in_len - 1 : i; // Adjust index if overshot
    }
}
