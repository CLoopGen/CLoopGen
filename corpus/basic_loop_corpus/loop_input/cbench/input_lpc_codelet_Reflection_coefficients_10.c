#include <stdio.h>
#include <inttypes.h>

typedef short word;

int i;
word ACF[9];
word K[9];

void init_vars() {
    for (int j = 0; j < 9; j++) {
        ACF[j] = (word)(j * 32767 / 8);
        K[j] = 0;
    }
    i = 0;
}