#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ns;
extern  int os;
extern  uint16_t *nptr;
extern  uint16_t *optr;
extern  int w;
extern int64_t bdif;
extern int64_t tdif;
extern int64_t pdif;
extern int t;
extern  uint16_t *rend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t *nptr_base = nptr;
    uint16_t *optr_base = optr;
    int64_t temp_sum_p = 0;
    int64_t temp_sum_t = 0;
    int64_t temp_sum_b = 0;

    // Introduce loop-carried dependency via cumulative sum pattern with delayed write-back
    int64_t acc_p = 0, acc_t = 0, acc_b = 0;
    uint16_t val_t;

    for (int i = 0; i < w; i++) {
        uint16_t *curr_n = nptr_base + i;
        uint16_t *curr_o = optr_base + i;

        // RAW dependency: each iteration depends on previous accumulation
        val_t = ((curr_n[0] - curr_n[ns]) << 2) + curr_n[ns << 1] - curr_n[-ns];
        acc_p += val_t * val_t;

        val_t = ((curr_n[0] - curr_o[os]) << 2) + curr_n[ns << 1] - curr_o[-os];
        acc_t += val_t * val_t;

        val_t = ((curr_o[0] - curr_n[ns]) << 2) + curr_o[os << 1] - curr_n[-ns];
        acc_b += val_t * val_t;

        // WAW and WAR avoidance: staggered update schedule simulated via temporary accumulation
        if ((i & 7) == 0 && i > 0) {  // Partial reduction every 8 iterations
            temp_sum_p += acc_p; acc_p = 0;
            temp_sum_t += acc_t; acc_t = 0;
            temp_sum_b += acc_b; acc_b = 0;
        }
    }

    // Final accumulation to global variables
    pdif += temp_sum_p + acc_p;
    tdif += temp_sum_t + acc_t;
    bdif += temp_sum_b + acc_b;
}
