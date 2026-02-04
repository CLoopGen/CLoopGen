#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern  unsigned char *pixels;
extern int count;
extern ssize_t i;
extern ssize_t j;
extern unsigned char *q;
extern unsigned char *packbits;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = (ssize_t)length; i > 0;) {
        if (i >= 3 && *pixels == *(pixels + 1) && *(pixels + 1) == *(pixels + 2)) {
            count = 3;
            for (j = 3; j < i && count < 127; j++) {
                if (*pixels != *(pixels + j))
                    break;
                count++;
            }
            i -= count;
            *q++ = (unsigned char)(256 - count + 1);
            *q++ = *pixels;
            pixels += count;
        } else {
            count = 0;
            if (i >= 1) {
                packbits[1] = *pixels;
                count++;
            }
            if (i >= 2) {
                packbits[2] = pixels[1];
                count++;
            }
            if (i >= 3 && !(*pixels == *(pixels + 1) && *(pixels + 1) == *(pixels + 2))) {
                packbits[3] = pixels[2];
                count++;
            }
            for (j = 3; j < i && count < 127; j++) {
                unsigned char a = *(pixels + j), b = *(pixels + j + 1), c = *(pixels + j + 2);
                if (j + 2 < i && a == b && b == c)
                    break;
                if (count + 1 >= 128) break;
                packbits[count + 1] = a;
                count++;
            }
            i -= count;
            *packbits = (unsigned char)(count - 1);
            for (j = 0; j <= count; j++)
                *q++ = packbits[j];
            pixels += count;
        }
    }
}
