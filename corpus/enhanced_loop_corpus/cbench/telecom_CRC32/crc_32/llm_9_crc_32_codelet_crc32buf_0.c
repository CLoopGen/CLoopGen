#include <stdio.h>

#include <inttypes.h>

typedef unsigned long DWORD;

typedef DWORD UNS_32_BITS;

typedef unsigned char BYTE;

extern UNS_32_BITS crc_32_tab[];
extern char *buf;
extern size_t len;
extern DWORD oldcrc32;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t unroll_factor = 4;
    size_t remainder = len % unroll_factor;
    size_t main_loop_len = len - remainder;

    for (; main_loop_len; main_loop_len -= unroll_factor, buf += unroll_factor) {
        oldcrc32 = crc_32_tab[(oldcrc32 ^ buf[0]) & 255] ^ (oldcrc32 >> 8);
        oldcrc32 = crc_32_tab[(oldcrc32 ^ buf[1]) & 255] ^ (oldcrc32 >> 8);
        oldcrc32 = crc_32_tab[(oldcrc32 ^ buf[2]) & 255] ^ (oldcrc32 >> 8);
        oldcrc32 = crc_32_tab[(oldcrc32 ^ buf[3]) & 255] ^ (oldcrc32 >> 8);
    }

    // Handle remaining elements
    for (; remainder; --remainder, ++buf) {
        oldcrc32 = crc_32_tab[(oldcrc32 ^ (*buf)) & 255] ^ (oldcrc32 >> 8);
    }
}
