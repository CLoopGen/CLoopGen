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
    // Introduce loop-carried dependency via delayed write using buffer
    char local_buf[4];
    int buf_idx = 0;

    for (chunk = 0; len > 0; len -= 3, chunk++) {
        if (chunk == (76 / 4)) {
            for (int i = 0; i < buf_idx; i++)
                *r++ = local_buf[i];
            buf_idx = 0;
            char *c = eol;
            for (int i = 0; i < eollen; i++)
                *r++ = c[i];
            chunk = 0;
        }

        c1 = *str++;
        c2 = len > 1 ? *str++ : '\x00';

        local_buf[0] = basis_64[c1 >> 2];
        local_buf[1] = basis_64[((c1 & 3) << 4) | ((c2 & 240) >> 4)];
        buf_idx = 2;

        if (len > 2) {
            c3 = *str++;
            local_buf[2] = basis_64[((c2 & 15) << 2) | ((c3 & 192) >> 6)];
            local_buf[3] = basis_64[c3 & 63];
            buf_idx = 4;
        } else if (len == 2) {
            local_buf[2] = basis_64[(c2 & 15) << 2];
            local_buf[3] = '=';
            buf_idx = 4;
        } else {
            local_buf[2] = '=';
            local_buf[3] = '=';
            buf_idx = 4;
        }

        // Flush buffer to output in reverse order — introduces artificial RAW/WAW dependency
        for (int i = 0; i < buf_idx; i++)
            *r++ = local_buf[i];
        buf_idx = 0;
    }
}
