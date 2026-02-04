#include <inttypes.h>

unsigned long t_d[9];
int ii = 0;

void init_vars() {
    for (int i = 0; i < 9; i++) {
        t_d[i] = 0;
    }
    ii = 0;
}