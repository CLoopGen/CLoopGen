#include <stdio.h>

#include <inttypes.h>

extern  unsigned char cov_2char[64];
extern char **salt_p;
extern size_t saltlen;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    unsigned char temp;
    for (j = 0; j < saltlen; j++) {
        temp = (*salt_p)[j] & 63;
        (*salt_p)[j] = cov_2char[temp];
    }
}
