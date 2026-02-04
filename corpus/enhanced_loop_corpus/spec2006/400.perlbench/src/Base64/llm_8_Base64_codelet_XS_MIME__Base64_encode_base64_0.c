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
    for (chunk = 0; len > 0; len -= 6, chunk++) {
        if (chunk == (76 / 4)) {
            char *c = eol;
            char *e = eol + eollen;
            for (; c < e; c++)
                *r++ = *c++;
            chunk = 0;
        }
        // Process two triplets per iteration to reduce trip count and increase arithmetic density
        if (len >= 3) {
            c1 = *str++;
            c2 = *str++;
            c3 = *str++;
            *r++ = basis_64[c1 >> 2];
            *r++ = basis_64[((c1 & 3) << 4) | ((c2 & 240) >> 4)];
            *r++ = basis_64[((c2 & 15) << 2) | ((c3 & 192) >> 6)];
            *r++ = basis_64[c3 & 63];
        } else {
            switch(len) {
                case 2:
                    c1 = *str++;
                    c2 = *str++;
                    *r++ = basis_64[c1 >> 2];
                    *r++ = basis_64[((c1 & 3) << 4) | ((c2 & 240) >> 4)];
                    *r++ = basis_64[(c2 & 15) << 2];
                    *r++ = '=';
                    break;
                case 1:
                    c1 = *str++;
                    *r++ = basis_64[c1 >> 2];
                    *r++ = basis_64[(c1 & 3) << 4];
                    *r++ = '=';
                    *r++ = '=';
                    break;
            }
            break;
        }

        // Second triplet in same iteration
        if (len >= 4) {
            if (len >= 6) {
                c1 = *str++;
                c2 = *str++;
                c3 = *str++;
                *r++ = basis_64[c1 >> 2];
                *r++ = basis_64[((c1 & 3) << 4) | ((c2 & 240) >> 4)];
                *r++ = basis_64[((c2 & 15) << 2) | ((c3 & 192) >> 6)];
                *r++ = basis_64[c3 & 63];
            } else if (len == 5) {
                c1 = *str++;
                c2 = *str++;
                *r++ = basis_64[c1 >> 2];
                *r++ = basis_64[((c1 & 3) << 4) | ((c2 & 240) >> 4)];
                *r++ = basis_64[(c2 & 15) << 2];
                *r++ = '=';
            } else if (len == 4) {
                c1 = *str++;
                c2 = *str++;
                *r++ = basis_64[c1 >> 2];
                *r++ = basis_64[((c1 & 3) << 4) | ((c2 & 240) >> 4)];
                *r++ = '=';
                *r++ = '=';
            }
        }
    }
}
