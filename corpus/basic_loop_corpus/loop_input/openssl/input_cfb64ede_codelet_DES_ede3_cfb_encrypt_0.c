#include <inttypes.h>

int num;
int i;
unsigned char ovec[16];

void init_vars() {
    num = 3;
    for (i = 0; i < 16; ++i) {
        ovec[i] = (unsigned char)(i * 7 + 3);
    }
}