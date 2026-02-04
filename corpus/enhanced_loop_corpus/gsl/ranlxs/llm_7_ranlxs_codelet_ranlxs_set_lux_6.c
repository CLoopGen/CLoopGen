#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    double xdbl[12];
    double ydbl[12];
    double carry;
    float xflt[24];
    unsigned int ir;
    unsigned int jr;
    unsigned int is;
    unsigned int is_old;
    unsigned int pr;
} ranlxs_state_t;

extern  double one_bit;
extern ranlxs_state_t *state;
extern int ibit;
extern int jbit;
extern int k;
extern int m;
extern int xbit[31];
extern double x;
extern double y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double accumulators[12] = {0};
    for (k = 0; k < 12; ++k) {
        for (m = 1; m <= 48; ++m) {
            y = (double)xbit[ibit];
            accumulators[k] += accumulators[k] + y;
            xbit[ibit] = (xbit[ibit] + xbit[jbit]) % 2;
            ibit = (ibit + 1) % 31;
            jbit = (jbit + 1) % 31;
        }
    }
    for (k = 0; k < 12; ++k) {
        state->xdbl[k] = one_bit * accumulators[k];
    }
}
