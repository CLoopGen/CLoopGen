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
for (chunk = 0; len > 0; len -= 3 , chunk++) {
    if (chunk != (76 / 4)) {
        c1 = *str++;
        c2 = len > 1 ? *str++ : '\x00';
        *r++ = basis_64[c1 >> 2];
        *r++ = basis_64[((c1 & 3) << 4) | ((c2 & 240) >> 4)];
        if (len > 2) {
            c3 = *str++;
            *r++ = basis_64[((c2 & 15) << 2) | ((c3 & 192) >> 6)];
            *r++ = basis_64[c3 & 63];
        } else if (len == 2) {
            *r++ = basis_64[(c2 & 15) << 2];
            *r++ = '=';
        } else {
            *r++ = '=';
            *r++ = '=';
        }
    } else {
        char *c = eol;
        char *e = eol + eollen;
        while (c < e)
            *r++ = *c++;
        chunk = 0;
    }
}
}
