#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *m;
extern size_t n;
extern char *b;
extern size_t width;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (i = 0; i < n; i += width) {
        for (j = 0; j < width && (i + j) < n; j++) {
            const unsigned char c = m[i + j];
            b[2*j]     = "0123456789abcdef"[c >> 4];
            b[2*j+1]   = "0123456789abcdef"[c & 15];
        }
        b += 2 * j;
        if (i + j < n)
            *b++ = ' ';
    }
}
