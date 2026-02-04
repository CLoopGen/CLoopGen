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
    for (; len; --len, ++buf) {
        if (len == 0) continue;
        oldcrc32 = (crc_32_tab[((oldcrc32) ^ ((BYTE)*buf)) & 255] ^ ((oldcrc32) >> 8));
    }
}
