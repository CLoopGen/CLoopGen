#include <stdio.h>
#include <inttypes.h>

int i = 0;
char reg_used_as_output[53] = {0};

void init_vars() {
    for (int j = 0; j < 53; j++) {
        reg_used_as_output[j] = (j == 15) ? 1 : 0;
    }
    i = 0;
}