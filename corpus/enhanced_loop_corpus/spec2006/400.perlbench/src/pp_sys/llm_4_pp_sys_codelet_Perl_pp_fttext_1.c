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
for (i = 0; i < len; i++ , s++) {
    if (!*s) {
        odd += len;
        break;
    }
    if (*s & 128) {
        if ((((U8)*s) >= 192 && (((U8)*s) <= 253))) {
            int ulen = PL_utf8skip[*(U8 *)s];
            if (ulen >= len - i) goto increment_odd;
            int j;
            for (j = 1; j < ulen; j++) {
                if (!(((U8)s[j]) >= 128 && (((U8)s[j]) <= 191)))
                    goto increment_odd;
            }
            --ulen;
            s += ulen;
            i += ulen;
            continue;
        }
      increment_odd:
        odd++;
        continue;
    }
    if (*s < 32 && *s != '\n' && *s != '\r' && *s != '\b' && *s != '\t' && *s != '\f' && *s != 27)
        odd++;
}
}
