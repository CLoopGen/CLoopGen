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
    for (post_shift = lgup; post_shift > 0; post_shift--) {
        unsigned long ml_lo = (mlow_hi << ((8 * 8) - 2)) | (mlow_lo >> 2);
        unsigned long mh_lo = (mhigh_hi << ((8 * 8) - 2)) | (mhigh_lo >> 2);
        unsigned long mask = (1UL << ((8 * 8) - 1)) - 1;
        ml_lo &= mask;
        mh_lo &= mask;
        if (ml_lo >= mh_lo || (mh_lo == 0)) {
            mlow_lo = 0;
            mhigh_lo = 0;
            break;
        }
        mlow_hi = (ml_lo >> ((8 * 8) - 1)) & 1;
        mlow_lo = ml_lo;
        mhigh_hi = (mh_lo >> ((8 * 8) - 1)) & 1;
        mhigh_lo = mh_lo;
    }
}
