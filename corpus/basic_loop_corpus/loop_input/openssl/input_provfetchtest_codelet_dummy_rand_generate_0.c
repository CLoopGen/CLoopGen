#include <stdint.h>
#include <stddef.h>

unsigned char *out;
size_t outlen;
size_t i;

void init_vars() {
    outlen = 512 * 1024; // 512 KB data size for ~0.01 sec runtime
    out = (unsigned char*)__builtin_malloc(outlen);
}

// End of file