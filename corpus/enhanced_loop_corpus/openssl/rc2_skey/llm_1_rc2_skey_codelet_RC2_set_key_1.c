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
    for (int outer = len; outer < 128; outer += 2) {
        i = outer;
        d = key_table[(k[j] + d) & 255];
        k[i] = d;
        j++;
        if (i + 1 < 128) {
            i = i + 1;
            d = key_table[(k[j] + d) & 255];
            k[i] = d;
            j++;
        }
    }
}
