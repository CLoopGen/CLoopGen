#include <stdio.h>

#include <inttypes.h>

extern unsigned char *to;
extern int num;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < num; i++) {
        if (!(i & 1)) {
            to[i] = 0;
        } else {
            to[i] = 0;
        }
    }
}
