#include <stdio.h>
#include <inttypes.h>

int i;
char reg_used_as_output[53];

void init_vars() {
    for (int idx = 0; idx < 53; idx++) {
        reg_used_as_output[idx] = 0;
    }
    i = 0;
}