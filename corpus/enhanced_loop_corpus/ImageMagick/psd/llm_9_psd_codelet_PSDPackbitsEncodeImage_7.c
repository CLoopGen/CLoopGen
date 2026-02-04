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
for (i = (ssize_t)length; i >= 4;) {
    count = 0;
    if (*pixels == *(pixels + 1) && *(pixels + 1) == *(pixels + 2)) {
        for (j = 3; j <= 127 && (i - j) > 0 && *pixels == *(pixels + j); j++)
            count++;
        count += 3;
        *q++ = (unsigned char)(256 - count);
        *q++ = *pixels;
        pixels += count;
        i -= count;
    } else {
        for (j = 0; j < 127 && (i - j) >= 4; j++) {
            packbits[j + 1] = pixels[j];
            if (*(pixels + j) == *(pixels + j + 1) && *(pixels + j + 1) == *(pixels + j + 2))
                break;
        }
        count = j;
        *packbits = (unsigned char)count;
        for (ssize_t k = 0; k <= count; k++)
            *q++ = packbits[k];
        pixels += count;
        i -= count;
    }
}
while (i > 0) {
    switch (i) {
        case 1:
            *q++ = 0; *q++ = *pixels++;
            i--;
            break;
        case 2:
            *q++ = 1; *q++ = *pixels++; *q++ = *pixels++;
            i -= 2;
            break;
        case 3:
            if (*pixels == *(pixels + 1) && *(pixels + 1) == *(pixels + 2)) {
                *q++ = 254; *q++ = *pixels;
                i -= 3;
                pixels += 3;
            } else {
                *q++ = 2; *q++ = *pixels++; *q++ = *pixels++; *q++ = *pixels++;
                i -= 3;
            }
            break;
    }
}
}
