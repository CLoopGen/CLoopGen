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
        {
            i--;
            *q++ = (unsigned char)0;
            *q++ = (*pixels);
            break;
        }
      case 2:
        {
            i -= 2;
            *q++ = (unsigned char)1;
            *q++ = (*pixels);
            *q++ = pixels[1];
            break;
        }
      case 3:
        {
            i -= 3;
            if ((*pixels == *(pixels + 1)) && (*(pixels + 1) == *(pixels + 2))) {
                *q++ = (unsigned char)((256 - 3) + 1);
                *q++ = (*pixels);
                break;
            }
            *q++ = (unsigned char)2;
            *q++ = (*pixels);
            *q++ = pixels[1];
            *q++ = pixels[2];
            break;
        }
      default:
        {
            if ((*pixels == *(pixels + 1)) && (*(pixels + 1) == *(pixels + 2))) {
                count = 3;
                for (; (ssize_t)count < i && count < 127; count++) {
                    if (*pixels != *(pixels + count)) {
                        count--;
                        break;
                    }
                }
                i -= count;
                *q++ = (unsigned char)((256 - count) + 1);
                *q++ = (*pixels);
                pixels += count;
                break;
            }
            for (count = 0; count < 127; count++) {
                if ((ssize_t)count >= i - 3) break;
                if (*(pixels + count) == *(pixels + count + 1) && 
                    *(pixels + count + 1) == *(pixels + count + 2)) {
                    break;
                }
                packbits[count + 1] = pixels[count];
            }
            if (count == 0 && i >= 3) count = 1; // Ensure progress
            i -= count;
            *packbits = (unsigned char)(count - 1);
            for (j = 0; j <= (ssize_t)count; j++)
                *q++ = packbits[j];
            pixels += count;
            break;
        }
    }
}
}
