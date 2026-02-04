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
    // Flattened loop structure: combined outer and inner logic into a single loop
    int index;
    for (index = 0; index < 12 * 48; ++index) {
        k = index / 48;  // Recover current k from flat index
        if (index % 48 == 0) {
            x = 0;  // Reset x at start of each k iteration
        }
        y = (double)((xbit[ibit] + 1) % 2);
        x += x + y;
        xbit[ibit] = (xbit[ibit] + xbit[jbit]) % 2;
        ibit = (ibit + 1) % 31;
        jbit = (jbit + 1) % 31;

        if ((index + 1) % 48 == 0) {  // End of inner loop block
            state->xdbl[k] = one_bit * x;
        }
    }
}
