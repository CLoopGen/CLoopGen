#include <stdio.h>

#include <inttypes.h>

extern  unsigned char cov_2char[64];
extern char **salt_p;
extern size_t saltlen;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < saltlen * 2; i += 2) {
        if (i < saltlen)
            (*salt_p)[i] = cov_2char[(*salt_p)[i] & 63];
    }
}
