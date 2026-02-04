#include <stdio.h>

#include <inttypes.h>

extern size_t n;
extern unsigned char tmp[16];
extern  unsigned char *iv2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char local_tmp[16];
    for (n = 0; n < 16; ++n)
        local_tmp[n] = tmp[n] ^ iv2[n];
    for (n = 0; n < 16; ++n)
        tmp[n] = local_tmp[n];
}
