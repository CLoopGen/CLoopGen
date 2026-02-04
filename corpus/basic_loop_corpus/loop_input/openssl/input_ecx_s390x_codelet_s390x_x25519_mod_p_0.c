#include <inttypes.h>

unsigned char u_red[32];
unsigned int c;
int i;

void init_vars() {
    c = 0x12345678U; 
    for (int j = 0; j < 32; j++) {
        u_red[j] = (unsigned char)(j * 7 + 3);
    }
}