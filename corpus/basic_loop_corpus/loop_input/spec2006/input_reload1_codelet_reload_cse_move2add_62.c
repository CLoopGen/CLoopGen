#include <inttypes.h>

int reg_set_luid[53];
int i;

void init_vars() {
    for (int j = 0; j < 53; j++) {
        reg_set_luid[j] = 0;
    }
    i = 0;
}