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
    DWORD local_crc = oldcrc32;
    size_t i = 0;
    for (; i + 3 < len; i += 4) {
        local_crc = crc_32_tab[(local_crc ^ buf[i]) & 255] ^ (local_crc >> 8);
        local_crc = crc_32_tab[(local_crc ^ buf[i+1]) & 255] ^ (local_crc >> 8);
        local_crc = crc_32_tab[(local_crc ^ buf[i+2]) & 255] ^ (local_crc >> 8);
        local_crc = crc_32_tab[(local_crc ^ buf[i+3]) & 255] ^ (local_crc >> 8);
    }
    for (; i < len; ++i) {
        local_crc = crc_32_tab[(local_crc ^ buf[i]) & 255] ^ (local_crc >> 8);
    }
    oldcrc32 = local_crc;
}
