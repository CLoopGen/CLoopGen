#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

typedef unsigned long DWORD;
typedef DWORD UNS_32_BITS;
typedef unsigned char BYTE;

DWORD crc_32_tab[256];
char *buf;
size_t len;
DWORD oldcrc32;

void init_vars() {
    // Initialize CRC-32 lookup table
    for (int i = 0; i < 256; ++i) {
        DWORD c = i;
        for (int j = 0; j < 8; ++j) {
            if (c & 1)
                c = 0xEDB88320L ^ (c >> 1);
            else
                c = c >> 1;
        }
        crc_32_tab[i] = c;
    }

    // Allocate buffer of 64MB to ensure loop runs ~0.01 seconds on modern CPU
    size_t buf_size = 64 * 1024 * 1024;
    buf = (char*)malloc(buf_size);
    if (!buf) {
        exit(1);
    }

    // Fill buffer with non-zero data to avoid edge cases
    memset(buf, 'A', buf_size);

    // Initialize len to full buffer size
    len = buf_size;

    // Initialize oldcrc32 to a known starting value (commonly used in CRC32)
    oldcrc32 = 0xFFFFFFFF;
}