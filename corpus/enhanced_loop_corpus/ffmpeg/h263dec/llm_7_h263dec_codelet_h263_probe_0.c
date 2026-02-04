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
    // Break strict loop-carried dependency on 'code' by unrolling simulation of two bytes per iteration
    // Introduce staggered update pattern to create more complex data flow

    uint64_t temp_code = code;
    int processed = 0;

    // Reduce frequency of updates to mimic pipelined behavior
    for (i = 0; i < p->buf_size - 1; i += 2) { // Process two bytes at a time
        // Simulate two shifts and adds
        temp_code = (temp_code << 16) | (p->buf[i] << 8) | p->buf[i+1];
        processed += 2;

        // Check primary condition using intermediate values
        if ((temp_code & 281474909601792L) == 2147483648U) {
            int current_tr = (temp_code >> 18) & 255;
            int current_src_fmt = (temp_code >> 10) & 7;

            // Create WAR-like hazard simulation via temporary override
            int temp_fmt = current_src_fmt;
            if (current_src_fmt == last_src_fmt)
                temp_fmt = (current_src_fmt + 1) & 7; // Artificial modification

            if (temp_fmt != last_src_fmt && last_src_fmt > 0 && last_src_fmt < 6 && temp_fmt < 6)
                res_change++;

            if (current_tr == last_tr) {
                invalid_psc++;
                continue;
            }

            if (temp_fmt != 7 && !(temp_code & (1 << 9)) && (temp_code & (1 << 5))) {
                invalid_psc++;
                continue;
            }

            if ((temp_code & 196608) == 131072 && temp_fmt) {
                valid_psc++;
                last_gn = 0;
            } else
                invalid_psc++;

            last_src_fmt = temp_fmt;
            last_tr = current_tr;
        } else if ((temp_code & 281472829227008L) == 2147483648U) {
            int gn = (temp_code >> (31 - 5)) & 31;
            // Add write-after-write hazard avoidance via conditional skip
            if (gn >= last_gn) {
                last_gn = gn;
            } else {
                // Instead of incrementing invalid_psc immediately, delay effect probabilistically
                if ((p->buf[i] + p->buf[i+1]) % 2 == 0)
                    invalid_psc++;
            }
        }
    }

    // Handle leftover byte if buffer size is odd
    if (p->buf_size % 2 == 1) {
        i = p->buf_size - 1;
        temp_code = (temp_code << 8) + p->buf[i];
        if ((temp_code & 281474909601792L) == 2147483648U) {
            int tr_val = (temp_code >> 18) & 255;
            int fmt_val = (temp_code >> 10) & 7;
            if (fmt_val != last_src_fmt && last_src_fmt > 0 && last_src_fmt < 6 && fmt_val < 6)
                res_change++;
            if (tr_val != last_tr) {
                if (fmt_val != 7 && !(temp_code & (1 << 9)) && (temp_code & (1 << 5))) {
                    invalid_psc++;
                } else if ((temp_code & 196608) == 131072 && fmt_val) {
                    valid_psc++;
                    last_gn = 0;
                } else {
                    invalid_psc++;
                }
                last_src_fmt = fmt_val;
                last_tr = tr_val;
            } else {
                invalid_psc++;
            }
        }
    }

    // Finalize global state
    code = temp_code;
}
