#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    double xdbl[12];
    double carry;
    unsigned int ir;
    unsigned int jr;
    unsigned int ir_old;
    unsigned int pr;
} ranlxd_state_t;

extern  double one_bit;
extern ranlxd_state_t *state;
extern int ibit;
extern int jbit;
extern int k;
extern int l;
extern int xbit[31];
extern double x;
extern double y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by precomputing indices and accessing xbit in a blocked, sequential manner
    // We reorganize the inner loop to process bits in chunks using local index variables to enable better cache locality
    
    int ibit_local = ibit;
    int jbit_local = jbit;
    
    for (k = 0; k < 12; ++k) {
        x = 0;
        for (l = 1; l <= 48; ++l) {
            // Force consecutive logical access by normalizing indices into [0,30] range without modulo in critical step
            int idx_i = ibit_local & 30;  // Stride-like masking to promote predictability
            int idx_j = (jbit_local - 1) % 31;
            if (idx_j < 0) idx_j += 31;

            y = (double)((xbit[idx_i] + 1) % 2);
            x += x + y;

            // Update xbit using strided pattern via fixed offset
            xbit[idx_i] = (xbit[idx_i] + xbit[(idx_j + 16) % 31]) % 2;  // Indirect dependency with fixed stride

            // Increment local pointers
            ibit_local = (ibit_local + 1) % 31;
            jbit_local = (jbit_local + 1) % 31;
        }
        state->xdbl[k] = one_bit * x;
    }

    // Update global state
    ibit = ibit_local;
    jbit = jbit_local;
}
