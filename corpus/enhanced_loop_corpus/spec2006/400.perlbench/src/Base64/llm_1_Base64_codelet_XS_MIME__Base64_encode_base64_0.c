#include <stdio.h>

#include <inttypes.h>

typedef size_t STRLEN;

extern char basis_64[];
extern char *str;
extern ssize_t len;
extern char *eol;
extern STRLEN eollen;
extern char *r;
extern unsigned char c1;
extern unsigned char c2;
extern unsigned char c3;
extern int chunk;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (chunk = 0; len > 0;) {
        for (int i = 0; i < 3 && len > 0; i++, len--) {
            if (i == 0) {
                c1 = *str++;
            } else if (i == 1) {
                c2 = *str++;
            } else if (i == 2) {
                c3 = *str++;
            }
        }
        if (chunk == (76 / 4)) {
            for (char *c = eol, *e = eol + eollen; c < e; r++, c++)
                *r = *c;
            chunk = 0;
        } else {
            *r++ = basis_64[c1 >> 2];
            *r++ = basis_64[((c1 & 3) << 4) | ((c2 & 240) >> 4)];
            if (len >= 0) {
                if (len >= 1) {
                    *r++ = basis_64[((c2 & 15) << 2) | ((c3 & 192) >> 6)];
                    *r++ = basis_64[c3 & 63];
                } else if (len == 0) {
                    *r++ = basis_64[(c2 & 15) << 2];
                    *r++ = '=';
                } else {
                    *r++ = '=';
                    *r++ = '=';
                }
            }
        }
        chunk++;
    }
}
