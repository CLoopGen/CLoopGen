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
    for (i = (ssize_t)length; i != 0;) {
        switch (i) {
          case 1:
            i--;
            *q++ = 0;
            *q++ = *pixels;
            pixels++;
            break;
          case 2:
            i -= 2;
            *q++ = 1;
            *q++ = *pixels;
            *q++ = pixels[1];
            pixels += 2;
            break;
          case 3: {
            unsigned char p0 = *pixels, p1 = pixels[1], p2 = pixels[2];
            if (p0 == p1 && p1 == p2) {
                i -= 3;
                *q++ = (unsigned char)(256 - 3 + 1);
                *q++ = p0;
                pixels += 3;
            } else {
                i -= 3;
                *q++ = 2;
                *q++ = p0;
                *q++ = p1;
                *q++ = p2;
                pixels += 3;
            }
            break;
          }
          default: {
            unsigned char first = *pixels;
            if (first == *(pixels + 1) && first == *(pixels + 2)) {
                count = 3;
                if (count < i && first == *(pixels + 3)) {
                    count = 4;
                    if (count < i && first == *(pixels + 4)) {
                        count = 5;
                        while ((ssize_t)count < i && first == *(pixels + count) && count < 127)
                            count++;
                    }
                }
                i -= count;
                *q++ = (unsigned char)(256 - count + 1);
                *q++ = first;
                pixels += count;
            } else {
                count = 0;
                goto scan_literal;
            }
            break;
          }
        scan_literal:;
            for (j = 0; j < i - 2 && count < 127; j++) {
                if (*(pixels + count) == *(pixels + count + 1) && 
                    *(pixels + count + 1) == *(pixels + count + 2))
                    break;
                packbits[count + 1] = pixels[count];
                count++;
            }
            i -= count;
            *packbits = (unsigned char)(count - 1);
            for (j = 0; j <= (ssize_t)count; j++)
                *q++ = packbits[j];
            pixels += count;
            break;
        }
    }
}
