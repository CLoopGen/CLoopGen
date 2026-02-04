#include <string.h>

unsigned char plaintext[10240];
unsigned char checktext[10240];
unsigned int n;
size_t matches;

void init_vars() {
    for (int i = 0; i < 10240; ++i) {
        plaintext[i] = (unsigned char)(i & 0xFF);
        checktext[i] = (unsigned char)((i + 32) & 0xFF);
    }
    n = 0;
    matches = 0;
}