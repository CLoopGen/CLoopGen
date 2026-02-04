#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG k;
extern float *ptrba;
extern float *ptrbb;
extern float res0_0;
extern float res0_1;
extern float res0_2;
extern float res0_3;
extern float res0_4;
extern float res0_5;
extern float res0_6;
extern float res0_7;
extern float res1_0;
extern float res1_1;
extern float res1_2;
extern float res1_3;
extern float res1_4;
extern float res1_5;
extern float res1_6;
extern float res1_7;
extern float a0;
extern float a1;
extern float b0;
extern float b1;
extern BLASLONG temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (temp > 0) {
        for (k = 0; k < temp; k++) {
            b0 = ptrbb[0];
            b1 = ptrbb[1];
            for (BLASLONG unroll_idx = 0; unroll_idx < 8; unroll_idx++) {
                float a_val = ptrba[unroll_idx];
                if (unroll_idx % 2 == 0) {
                    res0_0 += a_val * b0; res1_0 += a_val * b1;
                } else {
                    res0_1 += a_val * b0; res1_1 += a_val * b1;
                }
                // Simulate staggered accumulation using offset logic
                switch (unroll_idx) {
                    case 2: res0_2 += a_val * b0; res1_2 += a_val * b1; break;
                    case 3: res0_3 += a_val * b0; res1_3 += a_val * b1; break;
                    case 4: res0_4 += a_val * b0; res1_4 += a_val * b1; break;
                    case 5: res0_5 += a_val * b0; res1_5 += a_val * b1; break;
                    case 6: res0_6 += a_val * b0; res1_6 += a_val * b1; break;
                    case 7: res0_7 += a_val * b0; res1_7 += a_val * b1; break;
                }
            }
            ptrba = ptrba + 8;
            ptrbb = ptrbb + 2;
        }
    }
}
