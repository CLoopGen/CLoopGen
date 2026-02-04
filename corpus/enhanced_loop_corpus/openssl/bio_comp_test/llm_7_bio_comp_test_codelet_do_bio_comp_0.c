#include <stdio.h>

#include <inttypes.h>

extern unsigned char *original;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char temp = 0;
    for (i = 0; i < 32 * 1024; i++) {
        temp += i & 1;          // Introduces loop-carried RAW dependency
        original[i] = temp;     // Value depends on prior iteration's result
    }
}
