#include <stdio.h>

#include <inttypes.h>

extern int bx;
extern int by;
extern short ******all_mv;
extern short pmv[2];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Eliminate apparent dependencies by unrolling and parallelizing independent writes (eliminate loop-carried deps)
    // Fully unroll the loop to remove all loop-carried dependencies; each access is now independent
    int idx = 0;
    #define SET_MV(bx_val, by_val) \
        all_mv[bx_val][by_val][0][0][0][0] = pmv[0]; \
        all_mv[bx_val][by_val][0][0][0][1] = pmv[1];

    SET_MV(0,0); SET_MV(1,0); SET_MV(2,0); SET_MV(3,0);
    SET_MV(0,1); SET_MV(1,1); SET_MV(2,1); SET_MV(3,1);
    SET_MV(0,2); SET_MV(1,2); SET_MV(2,2); SET_MV(3,2);
    SET_MV(0,3); SET_MV(1,3); SET_MV(2,3); SET_MV(3,3);

    #undef SET_MV
}
