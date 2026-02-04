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
                x--;
                *q = 0;
                q += 1;
                *q = pixels[0];
                q += 1;
                pixels += 1;
                break;
            }
          case 2:
            {
                x -= 2;
                *q = 1;
                q += 1;
                *q = pixels[0];
                q += 1;
                *q = pixels[1];
                q += 1;
                pixels += 2;
                break;
            }
          case 3:
            {
                x -= 3;
                if ((pixels[0] == pixels[1]) && (pixels[1] == pixels[2])) {
                    *q = (unsigned char)(254);
                    q += 1;
                    *q = pixels[0];
                    q += 1;
                    pixels += 3;
                } else {
                    *q = 2;
                    q += 1;
                    *q = pixels[0];
                    q += 1;
                    *q = pixels[1];
                    q += 1;
                    *q = pixels[2];
                    q += 1;
                    pixels += 3;
                }
                break;
            }
          default:
            {
                if ((pixels[0] == pixels[1]) && (pixels[1] == pixels[2])) {
                    ssize_t c = 3;
                    for (; c < x && c < 127 && pixels[0] == pixels[c]; c++);
                    x -= c;
                    *q = (unsigned char)(256 - c + 1);
                    q += 1;
                    *q = pixels[0];
                    q += 1;
                    pixels += c;
                } else {
                    ssize_t c = 0;
                    for (; c < 127 && (c + 3) <= x; c++) {
                        packbits[c + 1] = pixels[c];
                        if ((pixels[c] == pixels[c+1]) && (pixels[c+1] == pixels[c+2]))
                            break;
                    }
                    if (c == 127 || (c + 3) > x) {
                        x -= c;
                        *packbits = (unsigned char)(c - 1);
                        for (j = 0; j <= c; j++) {
                            *q = packbits[j];
                            q += 1;
                        }
                        pixels += c;
                    } else {
                        x -= c;
                        *packbits = (unsigned char)(c - 1);
                        for (j = 0; j <= c; j++) {
                            *q = packbits[j];
                            q += 1;
                        }
                        pixels += c;
                    }
                }
                break;
            }
        }
    }
}
