#include <stdio.h>

#include <inttypes.h>

extern int n;
extern short *data;
extern unsigned char *converted;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < n; i += 2) {
        if (i + 1 < n) {
            converted[i] = (data[i] - 32768) / 256;
            converted[i+1] = (data[i+1] - 32768) / 256;
        } else {
            converted[i] = (data[i] - 32768) / 256;
        }
    }
}
