#include <stdio.h>

#include <inttypes.h>

extern int num;
extern int i;
extern int rem;
extern unsigned char *ovec;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8 && num >= 0; ++i) {
        unsigned char high = ovec[i + num];
        unsigned char low = ovec[i + num + 1];
        ovec[i] = (rem == 0) ? high : (high << rem | low >> (8 - rem));
    }
}
