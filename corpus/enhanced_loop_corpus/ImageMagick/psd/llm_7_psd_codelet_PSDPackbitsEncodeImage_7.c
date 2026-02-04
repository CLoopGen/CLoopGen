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
    ssize_t remaining = i;
    switch (remaining) {
      case 1:
        {
            *q++ = 0;
            *q++ = pixels[0];
            i = remaining - 1;
            pixels += 1;
            break;
        }
      case 2:
        {
            *q++ = 1;
            *q++ = pixels[0];
            *q++ = pixels[1];
            i = remaining - 2;
            pixels += 2;
            break;
        }
      case 3:
        {
            unsigned char val = *pixels;
            if (val == pixels[1] && pixels[1] == pixels[2]) {
                *q++ = (unsigned char)(254); // 256 - 3 + 1 = 254
                *q++ = val;
                i = remaining - 3;
                pixels += 3;
            } else {
                *q++ = 2;
                *q++ = pixels[0];
                *q++ = pixels[1];
                *q++ = pixels[2];
                i = remaining - 3;
                pixels += 3;
            }
            break;
        }
      default:
        {
            // Eliminate loop-carried dependency on 'count' by using local accumulators
            unsigned char current = *pixels;
            unsigned char next1 = *(pixels + 1);
            unsigned char next2 = *(pixels + 2);
            if (current == next1 && next1 == next2) {
                ssize_t streak = 3;
                for (ssize_t pos = 3; pos < remaining && streak < 127; pos++) {
                    if (*(pixels + pos) == current)
                        streak++;
                    else
                        break;
                }
                *q++ = (unsigned char)(256 - streak + 1);
                *q++ = current;
                i -= streak;
                pixels += streak;
            } else {
                ssize_t span = 0;
                // Introduce WAW-like anti-dependence via temporary array write before final store
                for (ssize_t idx = 0; idx < remaining - 2 && span < 127; idx++) {
                    if (*(pixels + span) == *(pixels + span + 1) && 
                        *(pixels + span + 1) == *(pixels + span + 2))
                        break;
                    packbits[span + 1] = *(pixels + span);
                    span++;
                }
                packbits[0] = (unsigned char)(span - 1);
                for (ssize_t out = 0; out <= span; out++) {
                    *q++ = packbits[out];
                }
                i -= span;
                pixels += span;
            }
            break;
        }
    }
}
}
