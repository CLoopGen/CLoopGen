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



void loop() {
    // Variant 1: Strided Memory Access Pattern
    // Instead of processing each byte sequentially, process every second byte (stride of 2),
    // then revisit the skipped bytes in a second pass within the same loop structure.
    I32 stride = 2;
    for (i = 0; i < len; i++, s++) {
        // First, handle current element with even index in original sequence
        if (!*s) {
            odd += len;
            break;
        } else if (*s & 128) {
            U8 current = (U8)*s;
            if (current >= 192 && current <= 253) {
                int ulen = PL_utf8skip[current];
                if (ulen < len - i) {
                    int j;
                    for (j = 1; j < ulen; j++) {
                        U8 next = (U8)s[j];
                        if (!(next >= 128 && next <= 191))
                            goto not_utf8_stride;
                    }
                    --ulen;
                    s += ulen;
                    i += ulen;
                    continue;
                }
            }
          not_utf8_stride:
            odd++;
        } else if (*s < 32 && *s != '\n' && *s != '\r' && *s != '\b' && *s != '\t' && *s != '\f' && *s != 27) {
            odd++;
        }

        // Now simulate strided access by peeking at next-next element if within bounds
        I32 next_i = i + 1;
        signed char *next_s = s + 1;
        if (next_i < len && next_s) {
            if (!*next_s) {
                odd += len;
                break;
            } else if (*next_s & 128) {
                U8 current = (U8)*next_s;
                if (current >= 192 && current <= 253) {
                    int ulen = PL_utf8skip[current];
                    if (ulen < len - next_i) {
                        int j;
                        for (j = 1; j < ulen; j++) {
                            if (next_s + j >= s + len) break;
                            U8 next_val = (U8)next_s[j];
                            if (!(next_val >= 128 && next_val <= 191))
                                goto not_utf8_stride_next;
                        }
                        --ulen;
                        s += ulen + 1;  // account for both steps
                        i += ulen + 1;
                        continue;
                    }
                }
              not_utf8_stride_next:
                odd++;
            } else if (*next_s < 32 && *next_s != '\n' && *next_s != '\r' &&
                       *next_s != '\b' && *next_s != '\t' && *next_s != '\f' && *next_s != 27) {
                odd++;
            }
            i++; s++;
        }
    }
}
