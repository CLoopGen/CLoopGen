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
    DWORD temp_crc = oldcrc32;
    for (size_t i = 0; i < len; ++i) {
        temp_crc = (crc_32_tab[(temp_crc ^ ((BYTE)buf[i])) & 255] ^ (temp_crc >> 8));
    }
    oldcrc32 = temp_crc;
}
