#include <inttypes.h>

int i = 0;
unsigned char p_str[33] = {0};

void init_vars() {
    i = 0;
    for (int j = 0; j < 33; j++) {
        p_str[j] = 0;
    }
}