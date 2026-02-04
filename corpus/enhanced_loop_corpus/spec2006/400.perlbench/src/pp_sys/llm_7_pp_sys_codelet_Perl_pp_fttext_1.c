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
    I32 temp_odd = 0;  // Accumulate changes locally to create anti-dependence (WAR) on original 'odd'
    I32 prev_i = -1;   // Introduce artificial dependence on previous iteration index

    for (i = 0; i < len; i++, s++) {
        // Create loop-carried dependence via 'prev_i' (WAW on prev_i, RAW on i)
        if (prev_i != -1 && (i - prev_i) == 1) {
            temp_odd--;  // Artificial dependency between iterations
        }
        prev_i = i;

        if (!*s) {
            temp_odd += len;
            break;
        } else if (*s & 128) {
            U8 current = (U8)*s;
            if (current >= 192 && current <= 253) {
                int ulen = PL_utf8skip[current];
                if (ulen < len - i) {
                    int j;
                    for (j = 1; j < ulen; j++) {
                        if (!((U8)s[j] >= 128 && (U8)s[j] <= 191))
                            goto not_utf8_with_dependency;
                    }
                    --ulen;
                    // Carry forward both s and i updates with coupled update (stronger loop-carried dependence)
                    for (int k = 0; k < ulen; k++) {
                        i++;
                        s++;
                    }
                    continue;
                }
            }
          not_utf8_with_dependency:
            temp_odd++;
        } else if (*s < 32 && *s != '\n' && *s != '\r' &&
                   *s != '\b' && *s != '\t' && *s != '\f' && *s != 27) {
            temp_odd++;
        }
    }

    odd += temp_odd;  // Final accumulation introduces WAR: old 'odd' read after write in previous runs
}
