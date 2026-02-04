#include <stdio.h>

#include <inttypes.h>

extern long mhigh_hi;
extern long mlow_hi;
extern unsigned long mhigh_lo;
extern unsigned long mlow_lo;
extern int lgup;
extern int post_shift;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    long temp_mlow_hi = mlow_hi;
    long temp_mhigh_hi = mhigh_hi;
    unsigned long temp_mlow_lo = mlow_lo;
    unsigned long temp_mhigh_lo = mhigh_lo;
    int shift_count = lgup;
    for (post_shift = lgup; post_shift > 0; post_shift--) {
        unsigned long ml_lo = (temp_mlow_hi << ((8 * 8) - 1)) | (temp_mlow_lo >> 1);
        unsigned long mh_lo = (temp_mhigh_hi << ((8 * 8) - 1)) | (temp_mhigh_lo >> 1);
        if (ml_lo >= mh_lo)
            break;
        temp_mlow_hi = 0;
        temp_mlow_lo = ml_lo;
        temp_mhigh_hi = 0;
        temp_mhigh_lo = mh_lo;
        shift_count--;
    }
    // Write final values back to globals only at the end to eliminate WAW and WAR dependencies in loop
    mlow_hi = temp_mlow_hi;
    mlow_lo = temp_mlow_lo;
    mhigh_hi = temp_mhigh_hi;
    mhigh_lo = temp_mhigh_lo;
    post_shift = shift_count;
}
