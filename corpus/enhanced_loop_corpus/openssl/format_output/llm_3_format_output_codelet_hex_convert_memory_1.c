#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *m;
extern size_t n;
extern char *b;
extern size_t width;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t idx_m = 0;
    size_t idx_b = 0;
    for (i = 0; i < n; i++) {
        const unsigned char c = m[idx_m++]; // Strided access via explicit index (consecutive here, but enables pattern changes)
        b[idx_b++] = "0123456789abcdef"[(c >> 4) & 15];
        b[idx_b++] = "0123456789abcdef"[c & 15];
        if ((i + 1) % width == 0 && i != n - 1) { // Align spacing after every full group
            b[idx_b++] = ' ';
        }
    }
}
