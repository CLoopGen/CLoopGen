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
            *q++ = (unsigned char)0;
            *q++ = (*pixels);
            i--;
            break;
        }
      case 2:
        {
            *q++ = (unsigned char)1;
            *q++ = (*pixels);
            *q++ = pixels[1];
            i -= 2;
            break;
        }
      case 3:
        {
            if ((*pixels == *(pixels + 1)) && (*(pixels + 1) == *(pixels + 2))) {
                *q++ = (unsigned char)((256 - 3) + 1);
                *q++ = (*pixels);
            } else {
                *q++ = (unsigned char)2;
                *q++ = (*pixels);
                *q++ = pixels[1];
                *q++ = pixels[2];
            }
            i -= 3;
            break;
        }
      default:
        {
            ssize_t run_length = 3;
            unsigned char first = *pixels;
            unsigned char second = *(pixels + 1);
            unsigned char third = *(pixels + 2);

            if ((first == second) && (second == third)) {
                count = 3;
                for (j = count; j < i && count < 127; j++) {
                    if (*pixels == *(pixels + j))
                        count++;
                    else
                        break;
                }
                *q++ = (unsigned char)((256 - count) + 1);
                *q++ = (*pixels);
                i -= count;
                pixels += count;
            } else {
                count = 0;
                for (j = 0; j < i - 2 && count < 127; j++) {
                    unsigned char a = *(pixels + count);
                    unsigned char b = *(pixels + count + 1);
                    unsigned char c = *(pixels + count + 2);
                    if ((a == b) && (b == c))
                        break;
                    packbits[count + 1] = pixels[count];
                    count++;
                }
                *packbits = (unsigned char)(count - 1);
                for (j = 0; j <= count; j++) {
                    *q++ = packbits[j];
                }
                i -= count;
                pixels += count;
            }
            break;
        }
    }
}
}
