#include <stdio.h>

#include <inttypes.h>

extern int len;
extern  unsigned char *data;
extern int i;
extern unsigned char *k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (len > 0) {
    for (i = 0; i < len; i += 2) {
        k[i] = data[i];
        if (i + 1 < len) {
            k[i + 1] = data[i + 1];
        }
    }
}
}
