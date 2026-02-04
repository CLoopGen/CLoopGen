#include <stdio.h>

#include <inttypes.h>

extern int i;
extern unsigned char p_str[33];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 0; j < 66; j++) {
        if (j < 33) {
            p_str[j] = 0;
        }
        i = (j < 33) ? j + 1 : i;
    }
}
