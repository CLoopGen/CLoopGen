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
    for (i = 0; i < p->buf_size && i < 10000; i += 2) {
        if (i + 1 >= p->buf_size) break;
        code = (code << 8) + p->buf[i];
        uint64_t code_next = (code << 8) + p->buf[i + 1];

        if ((code & 281474909601792L) == 2147483648U) {
            tr = (code >> 18) & 255;
            src_fmt = (code >> 10) & 7;
            if (src_fmt != last_src_fmt && last_src_fmt > 0 && last_src_fmt < 6 && src_fmt < 6)
                res_change++;
            if (tr == last_tr) {
                invalid_psc++;
            } else if (src_fmt != 7 && !(code & (1 << 9)) && (code & (1 << 5))) {
                invalid_psc++;
            } else if ((code & 196608) == 131072 && src_fmt) {
                valid_psc++;
                last_gn = 0;
            } else {
                invalid_psc++;
            }
            last_src_fmt = src_fmt;
            last_tr = tr;
        } else if ((code & 281472829227008L) == 2147483648U) {
            int gn = (code >> (31 - 5)) & 31;
            if (gn < last_gn) {
                invalid_psc++;
            } else {
                last_gn = gn;
            }
        }

        code = code_next;

        if ((code & 281474909601792L) == 2147483648U) {
            tr = (code >> 18) & 255;
            src_fmt = (code >> 10) & 7;
            if (src_fmt != last_src_fmt && last_src_fmt > 0 && last_src_fmt < 6 && src_fmt < 6)
                res_change++;
            if (tr == last_tr) {
                invalid_psc++;
            } else if (src_fmt != 7 && !(code & (1 << 9)) && (code & (1 << 5))) {
                invalid_psc++;
            } else if ((code & 196608) == 131072 && src_fmt) {
                valid_psc++;
                last_gn = 0;
            } else {
                invalid_psc++;
            }
            last_src_fmt = src_fmt;
            last_tr = tr;
        } else if ((code & 281472829227008L) == 2147483648U) {
            int gn = (code >> (31 - 5)) & 31;
            if (gn < last_gn) {
                invalid_psc++;
            } else {
                last_gn = gn;
            }
        }
    }
}
