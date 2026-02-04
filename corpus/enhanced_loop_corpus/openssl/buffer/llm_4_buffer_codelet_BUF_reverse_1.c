#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t size;
extern size_t i;
extern unsigned char *q;
extern char c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < size / 2; i++) {
        if (i % 2 == 0) {
            c = *q;
            *q-- = *out;
            *out++ = c;
        } else {
            *q-- = *out;
            *out++ = *q + 1;
        }
    }
}
