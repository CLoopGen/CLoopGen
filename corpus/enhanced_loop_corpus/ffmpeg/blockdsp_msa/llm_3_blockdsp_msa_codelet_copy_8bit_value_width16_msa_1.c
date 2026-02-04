#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern int32_t height;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant using indirect memory access via pointer array (emulating gather pattern)
    uint8_t* base_ptrs[8];

    for (cnt = (height >> 3); cnt--;) {
        // Initialize base pointers for 8 rows starting from current src
        for (int i = 0; i < 8; ++i) {
            base_ptrs[i] = &src[i * src_stride];
        }

        {
            {
                {
                    // Access first four rows at offset 0 (simulating horizontal coherence)
                    volatile uint8_t val1 = *base_ptrs[0];
                    volatile uint8_t val2 = *base_ptrs[1];
                    volatile uint8_t val3 = *base_ptrs[2];
                    volatile uint8_t val4 = *base_ptrs[3];
                }
                ;
                {
                    // Access last four rows with offset +1 (strided column access)
                    volatile uint8_t val5 = *(base_ptrs[4] + 1);
                    volatile uint8_t val6 = *(base_ptrs[5] + 1);
                    volatile uint8_t val7 = *(base_ptrs[6] + 1);
                    volatile uint8_t val8 = *(base_ptrs[7] + 1);
                }
                ;
            }
            ;
            {
                {
                    // Interleaved access: even indices forward, odd backward
                    volatile uint8_t val9  = *base_ptrs[0];
                    volatile uint8_t val10 = *(base_ptrs[7] + 2);
                    volatile uint8_t val11 = *base_ptrs[2];
                    volatile uint8_t val12 = *(base_ptrs[5] + 2);
                }
                ;
                {
                    // Uniform offset access across all 8 rows (coalesced load simulation)
                    for (int j = 0; j < 8; ++j) {
                        volatile uint8_t temp = *(base_ptrs[j] + 4);
                    }
                }
                ;
            }
            ;
        }
        ;
        src += (8 * src_stride);
    }
}
