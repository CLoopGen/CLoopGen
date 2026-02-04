#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern  unsigned char *pixels;
extern int count;
extern ssize_t x;
extern unsigned char *q;
extern ssize_t j;
extern unsigned char packbits[128];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = (ssize_t)length; x > 0;) {
        if (x >= 3 && (*pixels == *(pixels + 1)) && (*(pixels + 1) == *(pixels + 2))) {
            count = 3;
            for (j = 3; j < 128 && j < x; j++) {
                if (*pixels != *(pixels + j)) break;
                count++;
            }
            *q++ = (unsigned char)(257 - count);
            *q++ = *pixels;
            pixels += count;
            x -= count;
        } else if (x == 1) {
            *q++ = 0;
            *q++ = *pixels;
            pixels++;
            x--;
        } else if (x == 2) {
            *q++ = 1;
            *q++ = *pixels;
            *q++ = pixels[1];
            pixels += 2;
            x -= 2;
        } else {
            count = 0;
            for (j = 0; j < 127 && (x - count) >= 3; j++) {
                ssize_t idx = count;
                if (*(pixels + idx) == *(pixels + idx + 1) && 
                    *(pixels + idx + 1) == *(pixels + idx + 2)) break;
                packbits[count + 1] = pixels[count];
                count++;
            }
            *packbits = (unsigned char)count;
            for (j = 0; j <= count; j++) {
                *q++ = packbits[j];
            }
            pixels += count;
            x -= count;
        }
    }
}
