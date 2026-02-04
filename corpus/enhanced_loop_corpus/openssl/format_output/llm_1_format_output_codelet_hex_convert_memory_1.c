#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *m;
extern size_t n;
extern char *b;
extern size_t width;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (width == 0) return;
    for (i = 0; i < n;) {
        for (size_t chunk = 0; chunk < width && i < n; chunk++, i++) {
            const unsigned char c = *m++;
            *b++ = "0123456789abcdef"[c >> 4];
            *b++ = "0123456789abcdef"[c & 15];
        }
        if (i < n) {
            *b++ = ' ';
        }
    }
}
