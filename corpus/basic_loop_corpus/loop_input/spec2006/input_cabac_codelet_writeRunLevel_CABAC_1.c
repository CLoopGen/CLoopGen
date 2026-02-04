#include <inttypes.h>

int coeff[64];
int pos;

void init_vars() {
    pos = 0;
    for (int i = 0; i < 64; i++) {
        coeff[i] = i; // arbitrary initial values
    }
}