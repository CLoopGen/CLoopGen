#include <inttypes.h>

typedef const char *OPENSSL_CSTRING;

static char large_buffer[1024 * 128]; // 128KB buffer
static const char *a_storage[4];

OPENSSL_CSTRING *a = (OPENSSL_CSTRING*)a_storage;
char *aa;

void init_vars() {
    // Initialize the buffer with '0' except the last character to avoid infinite loop
    for (int i = 0; i < sizeof(large_buffer) - 1; i++) {
        large_buffer[i] = '0';
    }
    large_buffer[sizeof(large_buffer) - 1] = '1'; // terminate condition

    // Point a[3] to the large buffer
    a_storage[3] = large_buffer;
}