#include <stdio.h>

#include <inttypes.h>

extern int num;
extern int i;
extern int rem;
extern unsigned char *ovec;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char prev = ovec[num] << rem;
    unsigned char curr;
    for (i = 0; i < 8; ++i) {
        curr = ovec[i + num + 1] >> (8 - rem);
        ovec[i] = prev | curr;
        prev = ovec[i + num + 1] << rem;
    }
}
