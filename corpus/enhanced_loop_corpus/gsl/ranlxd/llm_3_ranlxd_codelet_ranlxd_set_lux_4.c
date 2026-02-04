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
    // Variant 2: Indirect array access using an index remapping table to simulate irregular memory access patterns
    // This variant introduces a static lookup table to create non-sequential, indirect access to xbit

    static const int index_map[31] = {
        0, 3, 6, 9, 12, 15, 18, 21, 24, 27, 30,
        2, 5, 8, 11, 14, 17, 20, 23, 26, 29,
        1, 4, 7, 10, 13, 16, 19, 22, 25, 28
    };  // Pseudo-random permutation of 0..30

    int ibit_local = ibit;
    int jbit_local = jbit;

    for (k = 0; k < 12; ++k) {
        x = 0;
        for (l = 1; l <= 48; ++l) {
            // Use indirect indexing via lookup table
            int mapped_ibit = index_map[ibit_local % 31];
            int mapped_jbit = index_map[jbit_local % 31];

            y = (double)((xbit[mapped_ibit] + 1) % 2);
            x += x + y;
            xbit[mapped_ibit] = (xbit[mapped_ibit] + xbit[mapped_jbit]) % 2;

            // Update indices normally
            ibit_local++;
            jbit_local++;

            ibit_local %= 31;
            jbit_local %= 31;
        }
        state->xdbl[k] = one_bit * x;
    }

    // Synchronize globals
    ibit = ibit_local;
    jbit = jbit_local;
}
