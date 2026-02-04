#include <stdio.h>

#include <inttypes.h>

typedef unsigned int DES_LONG;

extern const DES_LONG DES_SPtrans[8][64];
extern DES_LONG l;
extern DES_LONG r;
extern DES_LONG t;
extern DES_LONG u;
extern DES_LONG *s;
extern int j;
extern DES_LONG E0;
extern DES_LONG E1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive (Linearized) Memory Access Pattern
    // Reorganize the repeated block into a loop over 16 rounds where s[] is accessed consecutively.
    // This improves cache locality and enables better compiler optimization opportunities.

    const int num_rounds = 16;
    const int s_offsets[16] = {0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30}; // Map logical round to s index

    for (j = 0; j < 25; j++) {
        for (int k = 0; k < num_rounds; k++) {
            int idx = s_offsets[k]; // Translate linear iteration to actual s index
            DES_LONG *current_src = &s[idx]; // Enable pointer arithmetic prediction
            DES_LONG tmp;

            if ((k & 1) == 0) {
                // Even k: operate on r
                t = r ^ (r >> 16L);
            } else {
                // Odd k: operate on l
                t = l ^ (l >> 16L);
            }

            u = t & E0;
            t &= E1;
            tmp = (u << 16);
            u ^= (k & 1) ? l : r; // Choose source register based on round
            u ^= current_src[0];
            u ^= tmp;

            tmp = (t << 16);
            t ^= (k & 1) ? l : r;
            t ^= current_src[1];
            t ^= tmp;

            t = ({
                register unsigned int ret;
                asm ("rorl %1,%0" : "=r" (ret) : "I" (4), "0" (t) : "cc");
                ret;
            });

            DES_LONG result = 
                DES_SPtrans[0][(u >> 2L) & 63] ^
                DES_SPtrans[2][(u >> 10L) & 63] ^
                DES_SPtrans[4][(u >> 18L) & 63] ^
                DES_SPtrans[6][(u >> 26L) & 63] ^
                DES_SPtrans[1][(t >> 2L) & 63] ^
                DES_SPtrans[3][(t >> 10L) & 63] ^
                DES_SPtrans[5][(t >> 18L) & 63] ^
                DES_SPtrans[7][(t >> 26L) & 63];

            if (k & 1) {
                r ^= result;
            } else {
                l ^= result;
            }
        }

        // Final swap at end of full Feistel cycle
        t = l;
        l = r;
        r = t;
    }
}
