#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct HuffEntry {
    uint16_t sym;
    uint8_t len;
    uint32_t code;
} HuffEntry;

extern int i;
extern HuffEntry he[256];
extern int last;
extern uint32_t codes[256];
extern uint8_t bits[256];
extern uint8_t syms[256];
extern uint32_t code;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided memory access with stride of 2, processing elements in two passes if needed
    // Simulate strided write pattern; read still follows logical reverse order
    int stride = 2;
    int offset1 = 0, offset2 = 1;  // Two streams for even and odd positions
    for (i = last; i >= 0; i--) {
        int write_idx;
        if ((last - i) % 2 == 0) {
            write_idx = offset1;
            offset1 += stride;
        } else {
            write_idx = offset2;
            offset2 += stride;
        }
        codes[write_idx] = code >> (32 - he[i].len);
        bits[write_idx] = he[i].len;
        syms[write_idx] = he[i].sym;
        code += 2147483648U >> (he[i].len - 1);
    }
}
