#include <stdio.h>

#include <inttypes.h>

extern  unsigned char key_table[256];
extern int len;
extern int i;
extern int j;
extern unsigned char *k;
extern unsigned int d;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = len; i < 128; i++) {
        if ((k[j] + d) & 1) {
            d = key_table[(k[j] + d) & 255];
        }
        k[i] = d;
        j++;
    }
}
