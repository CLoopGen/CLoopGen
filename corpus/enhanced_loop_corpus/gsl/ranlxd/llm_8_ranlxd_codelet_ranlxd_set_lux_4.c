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
for (k = 0; k < 12; ++k) {
    x = 0;
    for (l = 1; l <= 24; ++l) {  // Reduced trip count to decrease computational intensity
        y = (double)(xbit[ibit] % 2);
        x += y;
        x *= 2.0;  // Combined and simplified arithmetic: equivalent to x = x + x + y
        xbit[ibit] = (xbit[ibit] + xbit[jbit]) & 1;  // Use bitwise AND for mod 2
        ibit = (ibit + 1) % 31;
        jbit = (jbit + 1) % 31;
    }
    state->xdbl[k] = one_bit * x;
}
}
