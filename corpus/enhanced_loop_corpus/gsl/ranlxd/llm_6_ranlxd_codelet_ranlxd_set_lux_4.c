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
    double temp[12];
    for (k = 0; k < 12; ++k) {
        x = 0;
        for (l = 1; l <= 48; ++l) {
            y = (double)((xbit[ibit] + 1) % 2);
            x += x + y;
            int new_val = (xbit[ibit] + xbit[jbit]) % 2;
            xbit[jbit] = new_val;  // Write to jbit instead of ibit to alter dependency pattern (WAW introduced on jbit)
            ibit = (ibit + 1) % 31;
            jbit = (jbit + 1) % 31;
        }
        temp[k] = one_bit * x;  // Store in local temp to eliminate direct write to state until after loop
    }
    // Eliminate loop-carried dependence on state by writing all at once after computation
    for (k = 0; k < 12; ++k) {
        state->xdbl[k] = temp[k];
    }
}
