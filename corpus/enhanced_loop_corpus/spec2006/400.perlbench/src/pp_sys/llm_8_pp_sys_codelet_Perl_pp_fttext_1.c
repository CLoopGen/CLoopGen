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
for (i = 0; i < len; i += 2, s += 2) {
    if (i + 1 >= len) {
        i = len - 1;
        s = (signed char *)((U8 *)s - (U8 *)s + len - 1);
        if (!*s) {
            odd += len;
            break;
        } else if (*s & 128) {
            if ((((U8)*s) >= 192 && (((U8)*s) <= 253))) {
                int ulen = PL_utf8skip[*(U8 *)s];
                if (ulen < len - i) {
                    int j;
                    for (j = 1; j < ulen; j++) {
                        if (!(((U8)s[j]) >= 128 && (((U8)s[j]) <= 191)))
                            goto not_utf8;
                    }
                    --ulen;
                    s += ulen;
                    i += ulen;
                    continue;
                }
            }
          not_utf8:
            odd++;
        } else if (*s < 32 && *s != '\n' && *s != '\r' && *s != '\b' && *s != '\t' && *s != '\f' && *s != 27)
            odd++;
        break;
    }

    I32 processed = 0;
    for (I32 k = 0; k < 2; k++) {
        signed char c = s[k];
        if (!c) {
            odd += len;
            processed = 1;
            break;
        } else if (c & 128) {
            if ((((U8)c) >= 192 && (((U8)c) <= 253))) {
                int ulen = PL_utf8skip[(U8)c];
                if (ulen < len - i - k) {
                    int j;
                    for (j = 1; j < ulen; j++) {
                        if (i + k + j >= len || !(((U8)s[k + j]) >= 128 && (((U8)s[k + j]) <= 191)))
                            goto not_utf8_2;
                    }
                    --ulen;
                    i += ulen;
                    s += ulen + k;
                    k += ulen;
                    processed = 1;
                    break;
                }
            }
          not_utf8_2:
            odd++;
        } else if (c < 32 && c != '\n' && c != '\r' && c != '\b' && c != '\t' && c != '\f' && c != 27)
            odd++;
    }
    if (processed) break;
}
}
