#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long INT32;

typedef short JCOEF;

typedef JCOEF *JCOEFPTR;

typedef int ISLOW_MULT_TYPE;

extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 tmp13;
extern INT32 tmp14;
extern INT32 tmp20;
extern INT32 tmp21;
extern INT32 tmp22;
extern INT32 tmp23;
extern INT32 tmp24;
extern INT32 tmp25;
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern INT32 z4;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (ctr = 0; ctr < 8; ctr++, inptr++, quantptr++, wsptr++) {
        // Eliminate some temporary reuse to break WAW dependencies and flatten computation
        INT32 t10, t20, t21, t22, t23, t24, t25, tz1, tz2, tz3, tz4;
        INT32 u10, u11, u12, u13, u14;

        t10 = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
        t10 <<= 13;
        t10 += ((INT32)1) << (13 - 2 - 1);

        tz1 = (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]));
        tz2 = (((ISLOW_MULT_TYPE)(inptr[8 * 4])) * (quantptr[8 * 4]));
        tz3 = (((ISLOW_MULT_TYPE)(inptr[8 * 6])) * (quantptr[8 * 6]));

        t20 = ((tz2 - tz3) * (((INT32)((2.5466401319999998) * (((INT32)1) << 13) + 0.5))));
        t23 = ((tz2 - tz1) * (((INT32)((0.43081504500000001) * (((INT32)1) << 13) + 0.5))));
        tz4 = tz1 + tz3;
        t24 = (tz4 * (-((INT32)((1.155664402) * (((INT32)1) << 13) + 0.5))));
        tz4 -= tz2;
        t25 = t10 + (tz4 * (((INT32)((1.3569279759999999) * (((INT32)1) << 13) + 0.5))));
        t21 = t20 + t23 + t25 - (tz2 * (((INT32)((1.821790775) * (((INT32)1) << 13) + 0.5))));
        t20 = t20 + t25 + (tz3 * (((INT32)((2.1158250870000002) * (((INT32)1) << 13) + 0.5))));
        t23 = t23 + t25 - (tz1 * (((INT32)((1.5135984769999999) * (((INT32)1) << 13) + 0.5))));
        t24 = t24 + t25;
        t22 = t24 - (tz3 * (((INT32)((0.78874911999999997) * (((INT32)1) << 13) + 0.5))));
        t24 = t24 + (tz2 * (((INT32)((1.9444135220000001) * (((INT32)1) << 13) + 0.5)))) - (tz1 * (((INT32)((1.3909757300000001) * (((INT32)1) << 13) + 0.5))));
        t25 = t10 - (tz4 * (((INT32)((1.414213562) * (((INT32)1) << 13) + 0.5))));

        // Use fresh temporaries to remove false dependencies (WAW/RAR eliminated)
        u10 = (((ISLOW_MULT_TYPE)(inptr[8 * 1])) * (quantptr[8 * 1]));
        u11 = (((ISLOW_MULT_TYPE)(inptr[8 * 3])) * (quantptr[8 * 3]));
        u12 = (((ISLOW_MULT_TYPE)(inptr[8 * 5])) * (quantptr[8 * 5]));
        u13 = (((ISLOW_MULT_TYPE)(inptr[8 * 7])) * (quantptr[8 * 7]));

        INT32 v11 = u10 + u11;
        INT32 v14 = ((v11 + u12 + u13) * (((INT32)((0.39843000299999998) * (((INT32)1) << 13) + 0.5))));
        INT32 v11_scaled = (v11 * (((INT32)((0.88798390199999999) * (((INT32)1) << 13) + 0.5))));
        INT32 v12 = ((u10 + u12) * (((INT32)((0.67036129499999997) * (((INT32)1) << 13) + 0.5))));
        INT32 v13 = v14 + ((u10 + u13) * (((INT32)((0.36615157399999998) * (((INT32)1) << 13) + 0.5))));
        INT32 v10 = v11_scaled + v12 + v13 - (u10 * (((INT32)((0.92310786600000005) * (((INT32)1) << 13) + 0.5))));
        INT32 vz1 = v14 - ((u11 + u12) * (((INT32)((1.163011579) * (((INT32)1) << 13) + 0.5))));
        INT32 v11_final = v11_scaled + vz1 + (u11 * (((INT32)((2.0732765880000001) * (((INT32)1) << 13) + 0.5))));
        INT32 v12_final = v12 + vz1 - (u12 * (((INT32)((1.1921936230000001) * (((INT32)1) << 13) + 0.5))));
        INT32 vz2 = ((u11 + u13) * (-((INT32)((1.7982489100000001) * (((INT32)1) << 13) + 0.5))));
        INT32 v11_out = v11_final + vz2;
        INT32 v13_final = v13 + vz2 + (u13 * (((INT32)((2.1024586319999998) * (((INT32)1) << 13) + 0.5))));
        INT32 v14_final = v14 + (u11 * (-((INT32)((1.4672213009999999) * (((INT32)1) << 13) + 0.5)))) 
                              + (u12 * (((INT32)((1.001388905) * (((INT32)1) << 13) + 0.5)))) 
                              - (u13 * (((INT32)((1.6848439070000001) * (((INT32)1) << 13) + 0.5))));

        // Store results using computed values without reusing tmp variables across iterations
        wsptr[8 * 0] = (int)((t20 + v10) >> (13 - 2));
        wsptr[8 * 10] = (int)((t20 - v10) >> (13 - 2));
        wsptr[8 * 1] = (int)((t21 + v11_out) >> (13 - 2));
        wsptr[8 * 9] = (int)((t21 - v11_out) >> (13 - 2));
        wsptr[8 * 2] = (int)((t22 + v12_final) >> (13 - 2));
        wsptr[8 * 8] = (int)((t22 - v12_final) >> (13 - 2));
        wsptr[8 * 3] = (int)((t23 + v13_final) >> (13 - 2));
        wsptr[8 * 7] = (int)((t23 - v13_final) >> (13 - 2));
        wsptr[8 * 4] = (int)((t24 + v14_final) >> (13 - 2));
        wsptr[8 * 6] = (int)((t24 - v14_final) >> (13 - 2));
        wsptr[8 * 5] = (int)(t25 >> (13 - 2));
    }
}
