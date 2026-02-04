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



void loop() {
    for (i = (ssize_t)length; i != 0;) {
        switch (i) {
            case 1:
                {
                    i--;
                    *q = 0;
                    q += 1;
                    *q = pixels[0];
                    q += 1;
                    pixels += 1;
                    break;
                }
            case 2:
                {
                    i -= 2;
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
                    i -= 3;
                    if ((pixels[0] == pixels[1]) && (pixels[1] == pixels[2])) {
                        *q = (unsigned char)(256 - 3 + 1);
                        q += 1;
                        *q = pixels[0];
                        q += 1;
                        pixels += 3;
                        break;
                    }
                    *q = 2;
                    q += 1;
                    *q = pixels[0];
                    q += 1;
                    *q = pixels[1];
                    q += 1;
                    *q = pixels[2];
                    q += 1;
                    pixels += 3;
                    break;
                }
            default:
                {
                    if ((pixels[0] == pixels[1]) && (pixels[1] == pixels[2])) {
                        for (count = 3; count < 127 && (ssize_t)count < i; count++) {
                            if (pixels[count] != pixels[0]) break;
                        }
                        i -= count;
                        *q = (unsigned char)(256 - count + 1);
                        q += 1;
                        *q = pixels[0];
                        q += 1;
                        pixels += count;
                        break;
                    }
                    for (count = 0; count < 127 && (ssize_t)(count + 3) <= i; count++) {
                        packbits[count + 1] = pixels[count];
                        if (count + 3 >= i || 
                            (pixels[count + 1] == pixels[count + 2] && pixels[count + 2] == pixels[count + 3])) break;
                    }
                    if (count == 0) count = 1;
                    i -= count;
                    *packbits = (unsigned char)(count - 1);
                    for (j = 0; j <= (ssize_t)count; j++) {
                        *q++ = packbits[j];
                    }
                    pixels += count;
                    break;
                }
        }
    }
}
