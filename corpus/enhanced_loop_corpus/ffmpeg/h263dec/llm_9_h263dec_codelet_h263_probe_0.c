#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVProbeData {
    const char *filename;
    unsigned char *buf;
    int buf_size;
    const char *mime_type;
} AVProbeData;

extern  AVProbeData *p;
extern uint64_t code;
extern int i;
extern int valid_psc;
extern int invalid_psc;
extern int res_change;
extern int src_fmt;
extern int last_src_fmt;
extern int last_gn;
extern int tr;
extern int last_tr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 1;
    for (i = 0; i < p->buf_size; i += step) {
        code = (code << 8) + p->buf[i];

        const uint64_t mask1 = 281474909601792ULL;
        const uint64_t target1 = 2147483648ULL;
        const uint64_t mask2 = 281472829227008ULL;

        if ((code & mask1) == target1) {
            tr = (code >> 18) & 255;
            src_fmt = (code >> 10) & 7;

            if (src_fmt != last_src_fmt) {
                if (last_src_fmt > 0 && last_src_fmt < 6 && src_fmt < 6)
                    res_change++;
            }

            if (tr == last_tr) {
                invalid_psc++;
                step = 1;
                continue;
            }

            if (src_fmt != 7) {
                uint64_t flag9 = (code & (1ULL << 9));
                uint64_t flag5 = (code & (1ULL << 5));
                if (!flag9 && flag5) {
                    invalid_psc++;
                    step = 1;
                    continue;
                }
            }

            if (((code & 196608) == 131072) && src_fmt) {
                valid_psc++;
                last_gn = 0;
                step = (src_fmt == 1) ? 2 : 1;
            } else {
                invalid_psc++;
                step = 1;
            }

            last_src_fmt = src_fmt;
            last_tr = tr;
        }
        else if ((code & mask2) == target1) {
            int gn = (code >> 26) & 31;
            if (gn >= last_gn) {
                last_gn = gn;
                step = 1;
            } else {
                invalid_psc++;
                step = (gn == 0) ? 3 : 2;
            }
        }
        else {
            step = 1;
        }
    }
}
