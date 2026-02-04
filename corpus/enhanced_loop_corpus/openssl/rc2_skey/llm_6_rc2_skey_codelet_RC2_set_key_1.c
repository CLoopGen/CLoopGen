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
    unsigned int temp_d = d;
    for (i = len; i < 128; i++) {
        temp_d = key_table[(k[i - len + j] + temp_d) & 255];
        k[i] = temp_d;
    }
    d = temp_d;
}
