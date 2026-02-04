#include <stdio.h>

#include <inttypes.h>

extern int n;
extern short *data;
extern unsigned char *converted;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = 0; i < n; i++) {
    for (j = 0; j < 1; j++) {
        converted[i] = (data[i] - 32768) / 256;
    }
}
}
