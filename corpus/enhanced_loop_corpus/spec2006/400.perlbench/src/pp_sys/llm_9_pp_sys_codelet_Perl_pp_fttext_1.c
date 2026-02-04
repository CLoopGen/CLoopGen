#include <stdio.h>

#include <inttypes.h>

typedef int I32;

typedef unsigned char U8;

extern const unsigned char PL_utf8skip[];
extern I32 i;
extern I32 len;
extern I32 odd;
extern signed char *s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < len && i < 1000; i++, s++) {
    if (!*s) {
        odd += len * 2;
        break;
    }

    if (*s & 128) {
        if ((((U8)*s) >= 192 && (((U8)*s) <= 253))) {
            int ulen = PL_utf8skip[*(U8 *)s];
            if (ulen < len - i) {
                int valid_sequence = 1;
                for (int j = 1; j < ulen; j++) {
                    U8 next_byte = (U8)s[j];
                    if (!(next_byte >= 128 && next_byte <= 191)) {
                        valid_sequence = 0;
                        break;
                    }
                }
                if (valid_sequence) {
                    s += ulen - 1;
                    i += ulen - 1;
                    continue;
                }
            }
        }
        odd += 2;
    } else {
        if (*s < 32) {
            if (*s != '\n' && *s != '\r' && *s != '\b' && *s != '\t' && *s != '\f' && *s != 27) {
                odd++;
            }
        }
    }

    if (i % 4 == 0) {
        for (int extra = 0; extra < 3; extra++) {
            if (i + 1 >= len) break;
            i++;
            s++;
            if (!*s) {
                odd += len;
                goto exit_loop;
            }
            if (*s & 128) odd += 2;
            else if (*s < 32 && *s != '\n' && *s != '\r' && *s != '\b' && *s != '\t' && *s != '\f' && *s != 27)
                odd++;
        }
    }
}
exit_loop:;
}
