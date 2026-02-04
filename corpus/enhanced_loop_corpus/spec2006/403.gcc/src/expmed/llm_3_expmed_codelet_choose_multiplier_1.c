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
long temp_array[4];
for (post_shift = lgup; post_shift > 0; post_shift--) {
    temp_array[0] = mlow_hi;
    temp_array[1] = mlow_lo;
    temp_array[2] = mhigh_hi;
    temp_array[3] = mhigh_lo;

    unsigned long ml_lo = (temp_array[0] << ((8 * 8) - 1)) | (temp_array[1] >> 1);
    unsigned long mh_lo = (temp_array[2] << ((8 * 8) - 1)) | (temp_array[3] >> 1);

    if (ml_lo >= mh_lo)
        break;

    mlow_hi = 0;
    mlow_lo = ml_lo;
    mhigh_hi = 0;
    mhigh_lo = mh_lo;
}
}
