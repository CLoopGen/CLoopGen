#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t size;
extern size_t i;
extern unsigned char *q;
extern char c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (i = 0; i < size / 2; i++) {
        for (j = 0; j < 1; j++) {
            c = *q;
            *q-- = *out;
            *out++ = c;
        }
    }
}
