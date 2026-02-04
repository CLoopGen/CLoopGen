#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *m;
extern size_t n;
extern char *b;
extern size_t width;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j = 0;
    for (i = 0; i < n; i++) {
        const unsigned char c = *(m + i);
        const char high_nibble = c >> 4;
        const char low_nibble = c & 15;
        *(b + j) = "0123456789abcdef"[high_nibble];
        *(b + j + 1) = "0123456789abcdef"[low_nibble];
        j += 2;
        if (i % width == width - 1 && i != n - 1) {
            *(b + j) = ' ';
            j++;
        }
    }
}
