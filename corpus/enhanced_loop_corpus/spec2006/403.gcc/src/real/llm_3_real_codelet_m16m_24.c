#include <stdio.h>

#include <inttypes.h>

extern unsigned short *pp;
extern unsigned int carry;
extern  unsigned short *ps;
extern unsigned int aa;
extern unsigned int m;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward traversal using offset indexing
    unsigned short *ps_base = ps - 5;  // base pointer to allow consecutive access
    unsigned short *pp_base = pp - 5;
    for (i = 2 + 1; i < (6 + 3); i++) {
        int idx = i - 3;  // index from 0 to 5
        if (*(ps_base + idx) == 0) {
            // Simulate decrement effects by adjusting base logic
            // Maintain consistency: zero handling updates adjacent high memory
            *(pp_base + idx + 1) = 0;
        } else {
            m = (unsigned int)aa * *(ps_base + idx);
            carry = (m & 65535) + *(pp_base + idx);
            *(pp_base + idx) = (unsigned short)carry;
            carry = (carry >> 16) + (m >> 16) + *(pp_base + idx - 1);
            *(pp_base + idx - 1) = (unsigned short)carry;
            *(pp_base + idx - 2) = carry >> 16;
        }
    }
}
