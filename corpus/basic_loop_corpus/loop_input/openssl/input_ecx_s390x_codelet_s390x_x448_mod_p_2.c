#include <stdio.h>
#include <inttypes.h>

unsigned char u_red[56];
unsigned int c;
int i;

void init_vars() {
    for (int j = 0; j < 56; j++) {
        u_red[j] = (unsigned char)(j * 5);
    }
    c = 0x12345678U;
    i = 0;
}