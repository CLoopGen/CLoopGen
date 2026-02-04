#include <stdio.h>
#include <inttypes.h>
#include <string.h>

unsigned char plaintext[10240];
unsigned char checktext[10240];
unsigned int n;
size_t matches;

void init_vars() {
    // Initialize arrays with sample data to ensure consistent behavior
    for (int i = 0; i < sizeof(plaintext); ++i) {
        plaintext[i] = (unsigned char)(i & 0xFF);
    }
    for (int i = 0; i < sizeof(checktext); ++i) {
        checktext[i] = (unsigned char)((i + 32) & 0xFF);
    }

    // Reset global counters
    n = 0;
    matches = 0;
}