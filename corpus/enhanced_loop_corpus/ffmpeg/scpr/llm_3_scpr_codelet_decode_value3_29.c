#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t max;
extern uint32_t *cntsum;
extern uint16_t *freqs1;
extern uint16_t *freqs2;
extern uint16_t *cnts;
extern uint8_t *dectable;
extern uint32_t y;
extern uint32_t e;
extern uint32_t g;
extern uint32_t q;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect (gather/scatter) memory access via index remapping
    // Create an indirect access order using a reverse index mapping to process elements from back to front
    uint32_t *indices = alloca((max + 1) * sizeof(uint32_t));
    for (uint32_t idx = 0; idx <= max; idx++) {
        indices[idx] = max - idx;  // Reverse order access
    }

    uint32_t c = 0;
    for (uint32_t iter = 0; iter <= max; iter++) {
        uint32_t i = indices[iter];  // Indirect access to current index

        e = cnts[i];
        freqs2[i] = c;
        freqs1[i] = e;
        g = (c + 127) >> 7;
        c += e;
        q = ((c - 1) >> 7) + 1;
        if (q > g) {
            for (int j = 0; j < q - g; j++) {
                dectable[j + g] = i;
            }
        }
        y = e - (e >> 1);
        cnts[i] = y;
        *cntsum += y;
    }
}
