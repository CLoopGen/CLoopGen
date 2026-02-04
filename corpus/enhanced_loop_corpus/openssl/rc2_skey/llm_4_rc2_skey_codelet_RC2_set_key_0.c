#include <stdio.h>

#include <inttypes.h>

extern int len;
extern  unsigned char *data;
extern int i;
extern unsigned char *k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len; i++) {
        if (data[i] != 0) {
            k[i] = data[i];
        }
    }
}
