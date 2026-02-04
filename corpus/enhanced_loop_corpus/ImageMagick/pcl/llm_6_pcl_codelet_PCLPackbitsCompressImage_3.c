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
            *q++ = 0;
            *q++ = (*pixels);
            x--;
            break;
        }
      case 2:
        {
            *q++ = 1;
            *q++ = (*pixels);
            *q++ = pixels[1];
            x -= 2;
            break;
        }
      case 3:
        {
            if ((*pixels == *(pixels + 1)) && (*(pixels + 1) == *(pixels + 2))) {
                *q++ = (unsigned char)((256 - 3) + 1);
                *q++ = (*pixels);
            } else {
                *q++ = 2;
                *q++ = (*pixels);
                *q++ = pixels[1];
                *q++ = pixels[2];
            }
            x -= 3;
            break;
        }
      default:
        {
            if ((*pixels == *(pixels + 1)) && (*(pixels + 1) == *(pixels + 2))) {
                count = 3;
                for (j = count; j < x && j < 127; j++) {
                    if (*pixels != *(pixels + j)) break;
                    count++;
                }
                *q++ = (unsigned char)((256 - count) + 1);
                *q++ = (*pixels);
                x -= count;
                pixels += count;
            } else {
                count = 0;
                for (j = 0; j < x - 2 && count < 127; j++) {
                    if (*(pixels + count) == *(pixels + count + 1) && 
                        *(pixels + count + 1) == *(pixels + count + 2)) break;
                    packbits[count + 1] = pixels[count];
                    count++;
                }
                *packbits = (unsigned char)(count - 1);
                for (j = 0; j <= count; j++) {
                    *q++ = packbits[j];
                }
                x -= count;
                pixels += count;
            }
            break;
        }
    }
}
}
