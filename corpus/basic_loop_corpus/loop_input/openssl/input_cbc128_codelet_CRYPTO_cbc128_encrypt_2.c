#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

unsigned char *in;
unsigned char *out;
size_t len;
size_t n;
unsigned char *iv;

void init_vars() {
    len = 512 * 1024; // 512 KB data size for ~0.01 sec runtime estimate

    in = (unsigned char *)malloc(len);
    out = (unsigned char *)malloc(len);
    iv = (unsigned char *)malloc(16);

    if (!in || !out || !iv) {
        // Avoid dereferencing null pointers; ensure basic safety
        len = 0;
        return;
    }

    // Initialize in[] with predictable non-zero pattern
    for (size_t i = 0; i < len; ++i)
        in[i] = (unsigned char)(i & 0xFF);

    // Initialize iv[0..15] as a sample initialization vector
    for (size_t i = 0; i < 16; ++i)
        iv[i] = (unsigned char)((i * 7) & 0xFF);

    // Ensure out is initialized to avoid undefined behavior on partial writes
    memset(out, 0, len);
}