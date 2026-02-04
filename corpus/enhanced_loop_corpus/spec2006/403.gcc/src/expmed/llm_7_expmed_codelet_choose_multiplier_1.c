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
    unsigned long local_ml_lo, local_mh_lo;
    long local_mlow_hi = mlow_hi;
    long local_mhigh_hi = mhigh_hi;
    unsigned long local_mlow_lo = mlow_lo;
    unsigned long local_mhigh_lo = mhigh_lo;
    int iter = lgup;
    // Introduce artificial loop-carried dependency via accumulator to enforce sequential execution
    uint64_t accumulator = 0;
    for (post_shift = lgup; post_shift > 0; post_shift--) {
        local_ml_lo = (local_mlow_hi << 63) | (local_mlow_lo >> 1);
        local_mh_lo = (local_mhigh_hi << 63) | (local_mhigh_lo >> 1);
        accumulator += (local_ml_lo ^ local_mh_lo); // RAW dependency on prior iteration's accumulator
        if (local_ml_lo >= local_mh_lo)
            break;
        local_mlow_hi = 0;
        local_mlow_lo = local_ml_lo;
        local_mhigh_hi = 0;
        local_mhigh_lo = local_mh_lo;
    }
    // Update globals after loop to create delayed write-back (eliminates loop-carried WAW)
    mlow_hi = local_mlow_hi;
    mlow_lo = local_mlow_lo;
    mhigh_hi = local_mhigh_hi;
    mhigh_lo = local_mhigh_lo;
    post_shift = iter - (lgup - post_shift);
}
