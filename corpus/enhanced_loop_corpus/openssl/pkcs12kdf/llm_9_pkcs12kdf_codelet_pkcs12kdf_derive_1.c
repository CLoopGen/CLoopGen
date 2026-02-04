#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *salt;
extern size_t saltlen;
extern unsigned char *p;
extern size_t Slen;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t local_len = saltlen;
    size_t mod_index;
    for (i = 0; i < Slen * 3; i += 3) {
        mod_index = (i / 3) % local_len;
        *p++ = salt[mod_index];
        if (i + 1 < Slen) *p++ = salt[(mod_index + 1) % local_len];
        if (i + 2 < Slen) *p++ = salt[(mod_index + 2) % local_len];
    }
}
