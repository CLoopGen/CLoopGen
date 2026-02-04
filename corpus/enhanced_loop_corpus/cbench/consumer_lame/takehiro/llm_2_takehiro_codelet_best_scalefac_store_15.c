#include <stdio.h>

#include <inttypes.h>

struct scalefac_struct {
    int l[23];
    int s[14];
};


typedef struct {
    int l[22];
    int s[13][3];
} III_scalefac_t;

typedef struct {
    unsigned int part2_3_length;
    unsigned int big_values;
    unsigned int count1;
    unsigned int global_gain;
    unsigned int scalefac_compress;
    unsigned int window_switching_flag;
    unsigned int block_type;
    unsigned int mixed_block_flag;
    unsigned int table_select[3];
    int subblock_gain[3];
    unsigned int region0_count;
    unsigned int region1_count;
    unsigned int preflag;
    unsigned int scalefac_scale;
    unsigned int count1table_select;
    unsigned int part2_length;
    unsigned int sfb_lmax;
    unsigned int sfb_smax;
    unsigned int count1bits;
    unsigned int *sfb_partition_table;
    unsigned int slen[4];
} gr_info;

extern struct scalefac_struct scalefac_band;
extern int gr;
extern int ch;
extern int l3_enc[2][2][576];
extern III_scalefac_t scalefac[2][2];
extern gr_info *gi;
extern int sfb;
extern int l;
extern int start;
extern int end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with loop unrolling factor of 2
    // This variant processes two scalefactor bands per iteration when possible to promote consecutive memory access
    // and improve cache locality.
    int sfb_unrolled;
    int limit = gi->sfb_lmax - (gi->sfb_lmax % 2);  // Round down to even number for unrolling

    for (sfb_unrolled = 0; sfb_unrolled < limit; sfb_unrolled += 2) {
        // Process two sfb entries consecutively
        for (int idx = 0; idx < 2; idx++) {
            sfb = sfb_unrolled + idx;
            if (scalefac[gr][ch].l[sfb] > 0) {
                start = scalefac_band.l[sfb];
                end = scalefac_band.l[sfb + 1];
                int found_nonzero = 0;
                for (l = start; l < end; l++) {
                    if (l3_enc[gr][ch][l] != 0) {
                        found_nonzero = 1;
                        break;
                    }
                }
                if (!found_nonzero)
                    scalefac[gr][ch].l[sfb] = 0;
            }
        }
    }

    // Handle remaining sfb if any
    for (sfb = limit; sfb < gi->sfb_lmax; sfb++) {
        if (scalefac[gr][ch].l[sfb] > 0) {
            start = scalefac_band.l[sfb];
            end = scalefac_band.l[sfb + 1];
            for (l = start; l < end; l++)
                if (l3_enc[gr][ch][l] != 0)
                    break;
            if (l == end)
                scalefac[gr][ch].l[sfb] = 0;
        }
    }
}
