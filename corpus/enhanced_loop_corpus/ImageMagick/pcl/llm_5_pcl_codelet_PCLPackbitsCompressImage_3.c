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
        if (x == 1) {
            *q++ = 0;
            *q++ = *pixels;
            x--;
        }
        else if (x == 2) {
            *q++ = 1;
            *q++ = *pixels;
            *q++ = pixels[1];
            x -= 2;
        }
        else if (x == 3) {
            if (*pixels == pixels[1] && pixels[1] == pixels[2]) {
                *q++ = 254;
                *q++ = *pixels;
            } else {
                *q++ = 2;
                *q++ = *pixels;
                *q++ = pixels[1];
                *q++ = pixels[2];
            }
            x -= 3;
        }
        else {
            count = 3;
            if (*pixels == pixels[1] && pixels[1] == pixels[2]) {
                for (j = 3; j < x && j < 127 && *pixels == pixels[j]; j++)
                    count++;
                x -= count;
                *q++ = (unsigned char)(257 - count);
                *q++ = *pixels;
                pixels += count;
            } else {
                count = 0;
                for (j = 0; j < x - 3 && j < 127; j++) {
                    if (pixels[count] == pixels[count+1] && pixels[count+1] == pixels[count+2])
                        break;
                    packbits[count + 1] = pixels[count];
                    count++;
                }
                x -= count;
                packbits[0] = (unsigned char)(count - 1);
                for (j = 0; j <= count; j++)
                    *q++ = packbits[j];
                pixels += count;
            }
        }
    }
}
