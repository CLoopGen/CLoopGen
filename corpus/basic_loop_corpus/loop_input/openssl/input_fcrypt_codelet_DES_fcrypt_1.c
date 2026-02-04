#include <inttypes.h>

typedef unsigned char DES_cblock[8];

unsigned int i;
DES_cblock key;

void init_vars() {
    i = 0;
    for (unsigned int j = 0; j < 8; j++) {
        key[j] = 0;
    }
}