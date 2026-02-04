#include <stdint.h>

typedef short word;

int i;
word ACF[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
word P[9];

void init_vars() {
    for (int j = 0; j < 9; j++) {
        ACF[j] = (word)(j * 10);
        P[j] = 0;
    }
    i = 0;
}