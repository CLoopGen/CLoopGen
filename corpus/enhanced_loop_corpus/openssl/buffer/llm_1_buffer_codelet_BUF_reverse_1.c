#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t size;
extern size_t i;
extern unsigned char *q;
extern char c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (size / 2 > 0) {
        i = 0;
        for (;;) {
            c = *q;
            *q-- = *out;
            *out++ = c;
            i++;
            if (i >= size / 2) break;
        }
    }
}
