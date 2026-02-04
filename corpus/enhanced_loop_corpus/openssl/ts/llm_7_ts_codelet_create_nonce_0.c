#include <stdio.h>

#include <inttypes.h>

extern unsigned char buf[20];
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char prev = 1;
    for (i = 0; i < len; ++i) {
        if (!buf[i] && prev) {
            prev = buf[i];
        } else {
            break;
        }
    }
}
