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
    unsigned long ml_lo = (mlow_hi << ((8 * 8) - 1)) | (mlow_lo >> 1);
    unsigned long mh_lo = (mhigh_hi << ((8 * 8) - 1)) | (mhigh_lo >> 1);
    if (ml_lo >= mh_lo)
        break;
    mlow_hi = 0;
    mlow_lo = ml_lo;
    mhigh_hi = 0;
    mhigh_lo = mh_lo;
}

}
