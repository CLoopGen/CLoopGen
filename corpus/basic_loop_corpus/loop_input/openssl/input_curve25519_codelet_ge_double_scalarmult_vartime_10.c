#include <inttypes.h>

signed char aslide[256];
signed char bslide[256];
int i;

void init_vars() {
    for (int idx = 0; idx < 256; ++idx) {
        aslide[idx] = 0;
        bslide[idx] = 0;
    }
    // Set one element near the beginning to ensure loop breaks quickly but still traverses some elements
    // This avoids worst-case performance while ensuring the loop logic executes meaningfully
    aslide[128] = 1;
}