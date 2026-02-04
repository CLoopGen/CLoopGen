#include <stdio.h>

#include <inttypes.h>

extern int n;
extern short *data;
extern unsigned char *converted;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp;
    for (i = 0; i < n; i++) {
        temp = data[i] - 32768;
        converted[i] = temp / 256;
    }
}
