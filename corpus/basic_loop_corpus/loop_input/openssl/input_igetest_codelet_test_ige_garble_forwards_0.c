#include <stdio.h>
#include <inttypes.h>

unsigned char plaintext[10240];
unsigned char checktext[10240];
unsigned int n;
size_t matches;

void init_vars() {
    for (n = 0; n < sizeof(checktext); ++n) {
        plaintext[n] = (unsigned char)(n & 0xFF);
        checktext[n] = (unsigned char)((n + 32) & 0xFF);
    }
    n = 0;
    matches = 0;
}