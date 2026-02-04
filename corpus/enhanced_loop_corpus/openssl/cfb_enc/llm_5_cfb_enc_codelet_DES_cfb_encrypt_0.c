#include <stdio.h>

#include <inttypes.h>

extern int num;
extern int i;
extern int rem;
extern unsigned char *ovec;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; ++i) {
        if (i % 2 == 0) {
            ovec[i] = ovec[i + num] << rem;
        } else {
            ovec[i] = ovec[i + num + 1] >> (8 - rem);
        }
    }
}
