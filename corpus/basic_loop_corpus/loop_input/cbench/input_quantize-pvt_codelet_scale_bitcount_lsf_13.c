#include <inttypes.h>

int i;
int max_sfac[4];

void init_vars() {
    for (int j = 0; j < 4; j++) {
        max_sfac[j] = 0;
    }
}