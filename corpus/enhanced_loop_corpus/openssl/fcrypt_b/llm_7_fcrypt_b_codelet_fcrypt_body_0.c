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
for (j = 0; j < 25; j++) {
    // Variant: Reorder operations to increase instruction-level parallelism
    // and reduce false dependencies by delaying writes until all reads complete.
    // Use temporary accumulators to delay l and r updates — breaking loop-carried dependency early.

    DES_LONG l_new = l, r_new = r;
    DES_LONG t_val, u_val;
    DES_LONG t_vals[16], u_vals[16];
    int idx = 0;

    // Precompute all T and U values without modifying l or r
    // This removes loop-carried WAW and WAR dependencies during computation

    #define COMPUTE_TU(input, sk) \
        t_val = (input) ^ ((input) >> 16L); \
        u_val = t_val & E0; \
        t_val &= E1; \
        { DES_LONG tmp = (u_val << 16); u_val ^= (input) ^ s[sk]; u_val ^= tmp; } \
        { DES_LONG tmp = (t_val << 16); t_val ^= (input) ^ s[(sk)+1]; t_val ^= tmp; } \
        t_val = ({ register unsigned int ret; asm ("rorl %1,%0" : "=r" (ret) : "I" (4), "0" (t_val) : "cc"); ret; }); \
        t_vals[idx] = t_val; u_vals[idx] = u_val; idx++;

    COMPUTE_TU(r, 0)
    COMPUTE_TU(l, 2)
    COMPUTE_TU(r, 4)
    COMPUTE_TU(l, 6)
    COMPUTE_TU(r, 8)
    COMPUTE_TU(l, 10)
    COMPUTE_TU(r, 12)
    COMPUTE_TU(l, 14)
    COMPUTE_TU(r, 16)
    COMPUTE_TU(l, 18)
    COMPUTE_TU(r, 20)
    COMPUTE_TU(l, 22)
    COMPUTE_TU(r, 24)
    COMPUTE_TU(l, 26)
    COMPUTE_TU(r, 28)
    COMPUTE_TU(l, 30)

    idx = 0;

    // Now apply the SP-transformation results using precomputed t and u
    // Interleave l and r updates to allow more out-of-order execution

    #define APPLY_XOR(result_var, u_val, t_val) \
        result_var ^= DES_SPtrans[0][((u_val) >> 2L) & 63] ^ \
                      DES_SPtrans[2][((u_val) >> 10L) & 63] ^ \
                      DES_SPtrans[4][((u_val) >> 18L) & 63] ^ \
                      DES_SPtrans[6][((u_val) >> 26L) & 63] ^ \
                      DES_SPtrans[1][((t_val) >> 2L) & 63] ^ \
                      DES_SPtrans[3][((t_val) >> 10L) & 63] ^ \
                      DES_SPtrans[5][((t_val) >> 18L) & 63] ^ \
                      DES_SPtrans[7][((t_val) >> 26L) & 63];

    APPLY_XOR(l_new, u_vals[idx], t_vals[idx]); idx++;
    APPLY_XOR(r_new, u_vals[idx], t_vals[idx]); idx++;
    APPLY_XOR(l_new, u_vals[idx], t_vals[idx]); idx++;
    APPLY_XOR(r_new, u_vals[idx], t_vals[idx]); idx++;
    APPLY_XOR(l_new, u_vals[idx], t_vals[idx]); idx++;
    APPLY_XOR(r_new, u_vals[idx], t_vals[idx]); idx++;
    APPLY_XOR(l_new, u_vals[idx], t_vals[idx]); idx++;
    APPLY_XOR(r_new, u_vals[idx], t_vals[idx]); idx++;
    APPLY_XOR(l_new, u_vals[idx], t_vals[idx]); idx++;
    APPLY_XOR(r_new, u_vals[idx], t_vals[idx]); idx++;
    APPLY_XOR(l_new, u_vals[idx], t_vals[idx]); idx++;
    APPLY_XOR(r_new, u_vals[idx], t_vals[idx]); idx++;
    APPLY_XOR(l_new, u_vals[idx], t_vals[idx]); idx++;
    APPLY_XOR(r_new, u_vals[idx], t_vals[idx]); idx++;
    APPLY_XOR(l_new, u_vals[idx], t_vals[idx]); idx++;
    APPLY_XOR(r_new, u_vals[idx], t_vals[idx]); idx++;

    // Final assignment after all computations
    l = l_new;
    r = r_new;

    // Swap at end of iteration preserved
    t = l;
    l = r;
    r = t;
}
}
