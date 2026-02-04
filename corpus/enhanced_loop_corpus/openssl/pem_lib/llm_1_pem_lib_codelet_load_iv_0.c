#include <stdio.h>

#include <inttypes.h>

extern unsigned char *to;
extern int num;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (num > 0) {
        for (i = 0; i < num; i += 2) {
            to[i] = 0;
            if (i + 1 < num) {
                to[i + 1] = 0;
            }
        }
    }
}
