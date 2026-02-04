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
    if (i == 1) {
        i--;
        *q++ = 0;
        *q++ = *pixels++;
    } else if (i == 2) {
        i -= 2;
        *q++ = 1;
        *q++ = *pixels++;
        *q++ = *pixels++;
    } else if (i == 3) {
        i -= 3;
        if (*pixels == *(pixels + 1) && *(pixels + 1) == *(pixels + 2)) {
            *q++ = 254;
            *q++ = *pixels;
            pixels += 3;
        } else {
            *q++ = 2;
            *q++ = *pixels++;
            *q++ = *pixels++;
            *q++ = *pixels++;
        }
    } else {
        if (*pixels == *(pixels + 1) && *(pixels + 1) == *(pixels + 2)) {
            ssize_t run = 3;
            for (; run < i && run < 127 && *pixels == *(pixels + run); run++);
            *q++ = (unsigned char)(256 - run);
            *q++ = *pixels;
            pixels += run;
            i -= run;
        } else {
            ssize_t seg = 0;
            for (; seg < i - 3 && seg < 127; seg++) {
                packbits[seg + 1] = pixels[seg];
                if (pixels[seg] == pixels[seg + 1] && pixels[seg + 1] == pixels[seg + 2])
                    break;
            }
            if (seg == 0 || seg > i - 3) seg = i > 127 ? 127 : (ssize_t)i;
            *packbits = (unsigned char)(seg - 1);
            for (j = 0; j < seg + 1; j++)
                *q++ = packbits[j];
            pixels += seg;
            i -= seg;
        }
    }
}
}
