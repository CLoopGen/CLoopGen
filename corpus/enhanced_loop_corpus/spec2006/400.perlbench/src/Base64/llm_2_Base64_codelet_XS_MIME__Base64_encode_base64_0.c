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
    for (chunk = 0; len > 0; len -= 3, chunk++) {
        if (chunk == (76 / 4)) {
            for (ssize_t i = 0; i < eollen; i++) {
                r[i] = eol[i];
            }
            r += eollen;
            chunk = 0;
        }
        c1 = str[0];
        c2 = (len > 1) ? str[1] : '\x00';
        r[0] = basis_64[c1 >> 2];
        r[1] = basis_64[((c1 & 3) << 4) | ((c2 & 240) >> 4)];
        if (len > 2) {
            c3 = str[2];
            r[2] = basis_64[((c2 & 15) << 2) | ((c3 & 192) >> 6)];
            r[3] = basis_64[c3 & 63];
            r += 4;
        } else if (len == 2) {
            r[2] = basis_64[(c2 & 15) << 2];
            r[3] = '=';
            r += 4;
        } else {
            r[2] = '=';
            r[3] = '=';
            r += 4;
        }
        str += (len >= 3) ? 3 : len;
    }
}
