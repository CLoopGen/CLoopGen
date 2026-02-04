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
            for (char *c = eol, *e = eol + eollen; c < e; c++, r++)
                *r = *c;
            chunk = 0;
        }
        unsigned char temp_c1 = *str++;
        unsigned char temp_c2 = (len > 1) ? *str++ : '\x00';
        unsigned char temp_c3 = (len > 2) ? *str++ : '\x00';

        // Eliminate WAW and WAR dependencies by precomputing indices
        int idx1 = temp_c1 >> 2;
        int idx2 = ((temp_c1 & 3) << 4) | ((temp_c2 & 240) >> 4);
        *r++ = basis_64[idx1];
        *r++ = basis_64[idx2];

        if (len > 2) {
            int idx3 = ((temp_c2 & 15) << 2) | ((temp_c3 & 192) >> 6);
            int idx4 = temp_c3 & 63;
            *r++ = basis_64[idx3];
            *r++ = basis_64[idx4];
        } else if (len == 2) {
            *r++ = basis_64[(temp_c2 & 15) << 2];
            *r++ = '=';
        } else {
            *r++ = '=';
            *r++ = '=';
        }
    }
}
