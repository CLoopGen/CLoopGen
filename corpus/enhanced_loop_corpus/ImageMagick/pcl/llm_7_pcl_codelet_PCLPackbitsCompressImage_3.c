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
for (x = (ssize_t)length; x != 0;) {
    switch (x) {
      case 1:
        {
            unsigned char val = *pixels;
            x--;
            *q = 0; q++;
            *q = val; q++;
            break;
        }
      case 2:
        {
            unsigned char val0 = *pixels;
            unsigned char val1 = pixels[1];
            x -= 2;
            *q = 1; q++;
            *q = val0; q++;
            *q = val1; q++;
            break;
        }
      case 3:
        {
            unsigned char a = *pixels, b = pixels[1], c = pixels[2];
            x -= 3;
            if ((a == b) && (b == c)) {
                *q = (unsigned char)(254); q++;
                *q = a; q++;
            } else {
                *q = 2; q++;
                *q = a; q++;
                *q = b; q++;
                *q = c; q++;
            }
            break;
        }
      default:
        {
            unsigned char first = *pixels;
            if (first == *(pixels + 1) && *(pixels + 1) == *(pixels + 2)) {
                count = 3;
                for (j = 3; (j < 127) && (count < x); j++) {
                    if (first != *(pixels + j)) break;
                    count++;
                }
                *q = (unsigned char)(256 - count + 1); q++;
                *q = first; q++;
                x -= count;
                pixels += count;
            } else {
                count = 0;
                for (j = 0; (j < x - 2) && (count < 127); j++) {
                    unsigned char p0 = *(pixels + count);
                    unsigned char p1 = *(pixels + count + 1);
                    unsigned char p2 = *(pixels + count + 2);
                    if (p0 == p1 && p1 == p2) break;
                    packbits[count + 1] = p0;
                    count++;
                }
                packbits[0] = (unsigned char)(count - 1);
                for (j = 0; j <= count; j++) {
                    *q = packbits[j]; q++;
                }
                x -= count;
                pixels += count;
            }
            break;
        }
    }
}
}
