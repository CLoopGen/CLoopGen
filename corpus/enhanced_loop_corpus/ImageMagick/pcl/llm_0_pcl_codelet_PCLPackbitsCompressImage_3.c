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
                *q++ = 0;
                *q++ = (*pixels);
                break;
            }
          case 2:
            {
                x -= 2;
                *q++ = 1;
                *q++ = (*pixels);
                *q++ = pixels[1];
                break;
            }
          case 3:
            {
                x -= 3;
                if ((*pixels == *(pixels + 1)) && (*(pixels + 1) == *(pixels + 2))) {
                    *q++ = (unsigned char)((256 - 3) + 1);
                    *q++ = (*pixels);
                    break;
                }
                *q++ = 2;
                *q++ = (*pixels);
                *q++ = pixels[1];
                *q++ = pixels[2];
                break;
            }
          default:
            {
                if ((*pixels == *(pixels + 1)) && (*(pixels + 1) == *(pixels + 2))) {
                    for (count = 3; count < 127 && (ssize_t)count < x && *pixels == *(pixels + count); count++) { }
                    x -= count;
                    *q++ = (unsigned char)((256 - count) + 1);
                    *q++ = (*pixels);
                    pixels += count;
                    break;
                }
                for (count = 0; (ssize_t)count < x - 3 && count < 127; count++) {
                    packbits[count + 1] = pixels[count];
                    if (*(pixels + count) == *(pixels + count + 1) && 
                        *(pixels + count + 1) == *(pixels + count + 2)) {
                        break;
                    }
                }
                x -= count;
                *packbits = (unsigned char)(count - 1);
                for (j = 0; j <= (ssize_t)count; j++)
                    *q++ = packbits[j];
                pixels += count;
                break;
            }
        }
    }
}
