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
for (i = 0; i < p->buf_size; i++) {
    code = (code << 8) + p->buf[i];
    const uint64_t mask1 = 281474909601792L;
    const uint64_t mask2 = 281472829227008L;
    const uint32_t target = 2147483648U;

    if ((code & mask1) == target) {
        tr = (code >> 18) & 255;
        src_fmt = (code >> 10) & 7;

        if (src_fmt != last_src_fmt && (unsigned)(last_src_fmt - 1) < 5 && src_fmt < 6)
            res_change++;

        if (tr == last_tr) {
            invalid_psc++;
        } else {
            if (src_fmt == 7 || (code & (1 << 9)) || !(code & (1 << 5))) {
                if ((code & 196608) == 131072 && src_fmt) {
                    valid_psc++;
                    last_gn = 0;
                } else {
                    invalid_psc++;
                }
            } else {
                invalid_psc++;
            }
            last_src_fmt = src_fmt;
            last_tr = tr;
        }
    } else if ((code & mask2) == target) {
        int gn = (code >> 26) & 31;
        invalid_psc += (gn < last_gn);
        last_gn = (gn >= last_gn) ? gn : last_gn;
    }
}
}
