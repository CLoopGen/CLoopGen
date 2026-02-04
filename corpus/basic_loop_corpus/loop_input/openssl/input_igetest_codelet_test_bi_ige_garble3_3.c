#include <inttypes.h>
#include <string.h>

unsigned char plaintext[10240];
unsigned char checktext[10240];
unsigned int n;
size_t matches;

void init_vars() {
    // Initialize arrays with predictable pattern to ensure defined behavior
    for (unsigned int i = 0; i < sizeof(plaintext); ++i) {
        plaintext[i] = (unsigned char)(i & 0xFF);
        checktext[i] = (unsigned char)((i + 32) & 0xFF);
    }
    // Initialize scalar variables used in loop
    n = 0;
    matches = 0;
}