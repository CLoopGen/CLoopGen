#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int order = 16;
int i;
int k;
int32_t lpc32[16] = {
    -524800, 987654, -123456, 654321,
    -98765, 135790, -24680, 876543,
    -111111, 222222, -333333, 444444,
    -555555, 666666, -777777, 888888
};

void init_vars() {
    order = 16;
    for (int idx = 0; idx < 16; idx++) {
        lpc32[idx] = ((idx + 1) * 12345) * ((idx & 1) ? -1 : 1);
    }
}