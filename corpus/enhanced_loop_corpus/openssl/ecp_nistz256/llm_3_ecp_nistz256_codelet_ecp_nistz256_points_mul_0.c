#include <stdio.h>

#include <inttypes.h>

extern int i;
extern unsigned char p_str[33];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 2;
    int i_backup = i;
    for (i = 0; i < 33; i += stride) {
        p_str[i] = 0;
        if (i + 1 < 33) {
            p_str[i + 1] = 0;
        }
    }
    i = i_backup;
}
