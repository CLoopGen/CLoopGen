#include <stdio.h>

#include <inttypes.h>

extern  unsigned char cov_2char[64];
extern char **salt_p;
extern size_t saltlen;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (j = saltlen; j-- > 0; ) {
        (*salt_p)[j] = cov_2char[(*salt_p)[j] & 63];
    }
}
