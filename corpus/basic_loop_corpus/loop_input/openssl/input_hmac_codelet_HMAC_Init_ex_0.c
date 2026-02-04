#include <stdio.h>
#include <inttypes.h>

int i;
unsigned char pad[144];
unsigned char keytmp[144];

void init_vars() {
    for (int j = 0; j < 144; j++) {
        keytmp[j] = (unsigned char)(j * j + 31);
    }
}