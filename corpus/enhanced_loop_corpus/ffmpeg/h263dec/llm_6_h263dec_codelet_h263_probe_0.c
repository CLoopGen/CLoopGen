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
    uint64_t local_code = code; // Introduce local copy to reduce loop-carried WAW on global 'code'
    int local_valid_psc = valid_psc;
    int local_invalid_psc = invalid_psc;
    int local_last_src_fmt = last_src_fmt;
    int local_last_tr = last_tr;
    int local_last_gn = last_gn;
    int local_res_change = res_change;
    int local_src_fmt, local_tr;

    for (i = 0; i < p->buf_size; i++) {
        local_code = (local_code << 8) + p->buf[i];

        if ((local_code & 281474909601792L) == 2147483648U) {
            local_tr = (local_code >> 18) & 255;
            local_src_fmt = (local_code >> 10) & 7;

            // Introduce artificial dependency: res_change now affects src_fmt logic
            if (local_res_change > 0)
                local_src_fmt = (local_src_fmt + local_res_change) % 8;

            if (local_src_fmt != local_last_src_fmt && local_last_src_fmt > 0 && local_last_src_fmt < 6 && local_src_fmt < 6)
                local_res_change++;

            if (local_tr == local_last_tr) {
                local_invalid_psc++;
                continue;
            }

            if (local_src_fmt != 7 && !(local_code & (1 << 9)) && (local_code & (1 << 5))) {
                local_invalid_psc++;
                continue;
            }

            if ((local_code & 196608) == 131072 && local_src_fmt) {
                local_valid_psc++;
                local_last_gn = 0;
            } else
                local_invalid_psc++;

            local_last_src_fmt = local_src_fmt;
            local_last_tr = local_tr;
        } else if ((local_code & 281472829227008L) == 2147483648U) {
            int gn = (local_code >> (31 - 5)) & 31;

            // Add dependency: use of res_change in gn validation
            if (gn < local_last_gn || (local_res_change > 10)) {
                local_invalid_psc++;
            } else
                local_last_gn = gn;
        }
    }

    // Update globals only once at the end (eliminates loop-carried dependencies on globals)
    code = local_code;
    valid_psc = local_valid_psc;
    invalid_psc = local_invalid_psc;
    res_change = local_res_change;
    last_src_fmt = local_last_src_fmt;
    last_tr = local_last_tr;
    last_gn = local_last_gn;
}
