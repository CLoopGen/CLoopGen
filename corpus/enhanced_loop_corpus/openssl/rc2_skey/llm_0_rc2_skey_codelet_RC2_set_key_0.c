#include <stdio.h>

#include <inttypes.h>

extern int len;
extern  unsigned char *data;
extern int i;
extern unsigned char *k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = 0; i < len; i++) {
    for (j = 0; j < 1; j++) {
        k[i] = data[i];
    }
}
}
