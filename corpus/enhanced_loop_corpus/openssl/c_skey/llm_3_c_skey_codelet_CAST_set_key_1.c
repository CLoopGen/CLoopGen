#include <stdio.h>

#include <inttypes.h>

extern int len;
extern  unsigned char *data;
extern unsigned int x[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse sequential access (process array from end to beginning)
    for (i = len - 1; i >= 0; i--) {
        x[i] = data[i];
    }
}
