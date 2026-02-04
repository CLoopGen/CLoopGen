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
    I32 local_odd = odd;  // Introduce private copy to eliminate WAW dependency on 'odd'
    I32 local_i = 0;
    const signed char* local_s = s;

    for (; local_i < len; local_i++, local_s++) {
        if (!*local_s) {
            local_odd += len;
            break;
        } else if (*local_s & 128) {
            U8 byte = (U8)*local_s;
            if (byte >= 192 && byte <= 253) {
                int ulen = PL_utf8skip[byte];
                if (ulen < len - local_i) {
                    int valid_utf8 = 1;
                    // Eliminate goto by using direct control flow with flag (removes control dependency)
                    for (int j = 1; j < ulen; j++) {
                        U8 next_byte = (U8)local_s[j];
                        if (!(next_byte >= 128 && next_byte <= 191)) {
                            valid_utf8 = 0;
                            break;
                        }
                    }
                    if (valid_utf8) {
                        local_i += ulen - 1;
                        local_s += ulen - 1;
                        continue;
                    }
                }
            }
            local_odd++;  // Update local accumulator
        } else if (*local_s < 32 && *local_s != '\n' && *local_s != '\r' &&
                   *local_s != '\b' && *local_s != '\t' && *local_s != '\f' && *local_s != 27) {
            local_odd++;
        }
    }
    odd = local_odd;  // Final write-back to shared 'odd' (eliminates loop-carried WAW)
}
