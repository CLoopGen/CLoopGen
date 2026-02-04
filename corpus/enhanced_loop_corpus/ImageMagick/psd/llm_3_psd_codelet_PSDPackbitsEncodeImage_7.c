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
    ssize_t index = 0;
    unsigned char *pixel_base = pixels;
    unsigned char *q_base = q;
    
    for (i = (ssize_t)length; i > 0; ) {
        switch (i) {
            case 1:
                {
                    q_base[index++] = 0;
                    q_base[index++] = pixel_base[length - i];
                    i--;
                    break;
                }
            case 2:
                {
                    q_base[index++] = 1;
                    q_base[index++] = pixel_base[length - i];
                    q_base[index++] = pixel_base[length - i + 1];
                    i -= 2;
                    break;
                }
            case 3:
                {
                    ssize_t pos = length - i;
                    if ((pixel_base[pos] == pixel_base[pos + 1]) && 
                        (pixel_base[pos + 1] == pixel_base[pos + 2])) {
                        q_base[index++] = (unsigned char)(256 - 3 + 1);
                        q_base[index++] = pixel_base[pos];
                        i -= 3;
                    } else {
                        q_base[index++] = 2;
                        q_base[index++] = pixel_base[pos];
                        q_base[index++] = pixel_base[pos + 1];
                        q_base[index++] = pixel_base[pos + 2];
                        i -= 3;
                    }
                    break;
                }
            default:
                {
                    ssize_t pos = length - i;
                    if ((pixel_base[pos] == pixel_base[pos + 1]) && 
                        (pixel_base[pos + 1] == pixel_base[pos + 2])) {
                        for (count = 3; count < 127 && (ssize_t)count < i; count++) {
                            if (pixel_base[pos + count] != pixel_base[pos]) break;
                        }
                        q_base[index++] = (unsigned char)(256 - count + 1);
                        q_base[index++] = pixel_base[pos];
                        i -= count;
                    } else {
                        for (count = 0; count < 127 && (ssize_t)(count + 3) <= i; count++) {
                            packbits[count + 1] = pixel_base[pos + count];
                            ssize_t next = pos + count;
                            if ((ssize_t)count >= i - 3 ||
                                (pixel_base[next + 1] == pixel_base[next + 2] && 
                                 pixel_base[next + 2] == pixel_base[next + 3])) {
                                break;
                            }
                        }
                        if (count == 0) count = 1;
                        packbits[0] = (unsigned char)(count - 1);
                        for (j = 0; j <= (ssize_t)count; j++) {
                            q_base[index++] = packbits[j];
                        }
                        i -= count;
                    }
                    break;
                }
        }
    }
    q = q_base + index;
    pixels = pixel_base + (length - i);
}
