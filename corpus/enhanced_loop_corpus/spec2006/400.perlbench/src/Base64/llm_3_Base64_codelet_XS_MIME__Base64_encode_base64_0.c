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
    char *str_ptr = str;
    char *r_ptr = r;
    for (chunk = 0; len > 0; len -= 3, chunk++, str_ptr += 3) {
        if (chunk == (76 / 4)) {
            for (STRLEN i = 0; i < eollen; i++) {
                r_ptr[i] = *(eol + i);
            }
            r_ptr += eollen;
            chunk = 0;
        }
        unsigned char block[3] = {0};
        block[0] = str_ptr[0];
        block[1] = (len > 1) ? str_ptr[1] : 0;
        block[2] = (len > 2) ? str_ptr[2] : 0;

        r_ptr[0] = basis_64[block[0] >> 2];
        r_ptr[1] = basis_64[((block[0] & 3) << 4) | ((block[1] & 240) >> 4)];
        r_ptr[2] = basis_64[((block[1] & 15) << 2) | ((block[2] & 192) >> 6)];
        r_ptr[3] = basis_64[block[2] & 63];

        if (len == 1) {
            r_ptr[2] = '=';
            r_ptr[3] = '=';
        } else if (len == 2) {
            r_ptr[3] = '=';
        }
        r_ptr += 4;
    }
    r = r_ptr;
    str = str_ptr;
}
