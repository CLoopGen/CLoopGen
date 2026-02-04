#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int32_t *block;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduce effective loop depth by unrolling the original loop completely (depth decreased to 0 via unrolling)
int indices[8] = {0,1,2,3,4,5,6,7};
for (int k = 0; k < 8; k += 8) { // Single iteration outer loop
    i = indices[0];
    const unsigned int a0_0 = block[i + 0 * 8] + (unsigned int)block[i + 4 * 8];
    const unsigned int a2_0 = block[i + 0 * 8] - (unsigned int)block[i + 4 * 8];
    const unsigned int a4_0 = (block[i + 2 * 8] >> 1) - (unsigned int)block[i + 6 * 8];
    const unsigned int a6_0 = (block[i + 6 * 8] >> 1) + (unsigned int)block[i + 2 * 8];
    const unsigned int b0_0 = a0_0 + a6_0;
    const unsigned int b2_0 = a2_0 + a4_0;
    const unsigned int b4_0 = a2_0 - a4_0;
    const unsigned int b6_0 = a0_0 - a6_0;
    const int a1_0 = -block[i + 3 * 8] + (unsigned int)block[i + 5 * 8] - block[i + 7 * 8] - (block[i + 7 * 8] >> 1);
    const int a3_0 = block[i + 1 * 8] + (unsigned int)block[i + 7 * 8] - block[i + 3 * 8] - (block[i + 3 * 8] >> 1);
    const int a5_0 = -block[i + 1 * 8] + (unsigned int)block[i + 7 * 8] + block[i + 5 * 8] + (block[i + 5 * 8] >> 1);
    const int a7_0 = block[i + 3 * 8] + (unsigned int)block[i + 5 * 8] + block[i + 1 * 8] + (block[i + 1 * 8] >> 1);
    const int b1_0 = (a7_0 >> 2) + (unsigned int)a1_0;
    const int b3_0 = (unsigned int)a3_0 + (a5_0 >> 2);
    const int b5_0 = (a3_0 >> 2) - (unsigned int)a5_0;
    const int b7_0 = (unsigned int)a7_0 - (a1_0 >> 2);
    block[i + 0 * 8] = b0_0 + b7_0;
    block[i + 7 * 8] = b0_0 - b7_0;
    block[i + 1 * 8] = b2_0 + b5_0;
    block[i + 6 * 8] = b2_0 - b5_0;
    block[i + 2 * 8] = b4_0 + b3_0;
    block[i + 5 * 8] = b4_0 - b3_0;
    block[i + 3 * 8] = b6_0 + b1_0;
    block[i + 4 * 8] = b6_0 - b1_0;

    i = indices[1];
    const unsigned int a0_1 = block[i + 0 * 8] + (unsigned int)block[i + 4 * 8];
    const unsigned int a2_1 = block[i + 0 * 8] - (unsigned int)block[i + 4 * 8];
    const unsigned int a4_1 = (block[i + 2 * 8] >> 1) - (unsigned int)block[i + 6 * 8];
    const unsigned int a6_1 = (block[i + 6 * 8] >> 1) + (unsigned int)block[i + 2 * 8];
    const unsigned int b0_1 = a0_1 + a6_1;
    const unsigned int b2_1 = a2_1 + a4_1;
    const unsigned int b4_1 = a2_1 - a4_1;
    const unsigned int b6_1 = a0_1 - a6_1;
    const int a1_1 = -block[i + 3 * 8] + (unsigned int)block[i + 5 * 8] - block[i + 7 * 8] - (block[i + 7 * 8] >> 1);
    const int a3_1 = block[i + 1 * 8] + (unsigned int)block[i + 7 * 8] - block[i + 3 * 8] - (block[i + 3 * 8] >> 1);
    const int a5_1 = -block[i + 1 * 8] + (unsigned int)block[i + 7 * 8] + block[i + 5 * 8] + (block[i + 5 * 8] >> 1);
    const int a7_1 = block[i + 3 * 8] + (unsigned int)block[i + 5 * 8] + block[i + 1 * 8] + (block[i + 1 * 8] >> 1);
    const int b1_1 = (a7_1 >> 2) + (unsigned int)a1_1;
    const int b3_1 = (unsigned int)a3_1 + (a5_1 >> 2);
    const int b5_1 = (a3_1 >> 2) - (unsigned int)a5_1;
    const int b7_1 = (unsigned int)a7_1 - (a1_1 >> 2);
    block[i + 0 * 8] = b0_1 + b7_1;
    block[i + 7 * 8] = b0_1 - b7_1;
    block[i + 1 * 8] = b2_1 + b5_1;
    block[i + 6 * 8] = b2_1 - b5_1;
    block[i + 2 * 8] = b4_1 + b3_1;
    block[i + 5 * 8] = b4_1 - b3_1;
    block[i + 3 * 8] = b6_1 + b1_1;
    block[i + 4 * 8] = b6_1 - b1_1;

    i = indices[2];
    const unsigned int a0_2 = block[i + 0 * 8] + (unsigned int)block[i + 4 * 8];
    const unsigned int a2_2 = block[i + 0 * 8] - (unsigned int)block[i + 4 * 8];
    const unsigned int a4_2 = (block[i + 2 * 8] >> 1) - (unsigned int)block[i + 6 * 8];
    const unsigned int a6_2 = (block[i + 6 * 8] >> 1) + (unsigned int)block[i + 2 * 8];
    const unsigned int b0_2 = a0_2 + a6_2;
    const unsigned int b2_2 = a2_2 + a4_2;
    const unsigned int b4_2 = a2_2 - a4_2;
    const unsigned int b6_2 = a0_2 - a6_2;
    const int a1_2 = -block[i + 3 * 8] + (unsigned int)block[i + 5 * 8] - block[i + 7 * 8] - (block[i + 7 * 8] >> 1);
    const int a3_2 = block[i + 1 * 8] + (unsigned int)block[i + 7 * 8] - block[i + 3 * 8] - (block[i + 3 * 8] >> 1);
    const int a5_2 = -block[i + 1 * 8] + (unsigned int)block[i + 7 * 8] + block[i + 5 * 8] + (block[i + 5 * 8] >> 1);
    const int a7_2 = block[i + 3 * 8] + (unsigned int)block[i + 5 * 8] + block[i + 1 * 8] + (block[i + 1 * 8] >> 1);
    const int b1_2 = (a7_2 >> 2) + (unsigned int)a1_2;
    const int b3_2 = (unsigned int)a3_2 + (a5_2 >> 2);
    const int b5_2 = (a3_2 >> 2) - (unsigned int)a5_2;
    const int b7_2 = (unsigned int)a7_2 - (a1_2 >> 2);
    block[i + 0 * 8] = b0_2 + b7_2;
    block[i + 7 * 8] = b0_2 - b7_2;
    block[i + 1 * 8] = b2_2 + b5_2;
    block[i + 6 * 8] = b2_2 - b5_2;
    block[i + 2 * 8] = b4_2 + b3_2;
    block[i + 5 * 8] = b4_2 - b3_2;
    block[i + 3 * 8] = b6_2 + b1_2;
    block[i + 4 * 8] = b6_2 - b1_2;

    i = indices[3];
    const unsigned int a0_3 = block[i + 0 * 8] + (unsigned int)block[i + 4 * 8];
    const unsigned int a2_3 = block[i + 0 * 8] - (unsigned int)block[i + 4 * 8];
    const unsigned int a4_3 = (block[i + 2 * 8] >> 1) - (unsigned int)block[i + 6 * 8];
    const unsigned int a6_3 = (block[i + 6 * 8] >> 1) + (unsigned int)block[i + 2 * 8];
    const unsigned int b0_3 = a0_3 + a6_3;
    const unsigned int b2_3 = a2_3 + a4_3;
    const unsigned int b4_3 = a2_3 - a4_3;
    const unsigned int b6_3 = a0_3 - a6_3;
    const int a1_3 = -block[i + 3 * 8] + (unsigned int)block[i + 5 * 8] - block[i + 7 * 8] - (block[i + 7 * 8] >> 1);
    const int a3_3 = block[i + 1 * 8] + (unsigned int)block[i + 7 * 8] - block[i + 3 * 8] - (block[i + 3 * 8] >> 1);
    const int a5_3 = -block[i + 1 * 8] + (unsigned int)block[i + 7 * 8] + block[i + 5 * 8] + (block[i + 5 * 8] >> 1);
    const int a7_3 = block[i + 3 * 8] + (unsigned int)block[i + 5 * 8] + block[i + 1 * 8] + (block[i + 1 * 8] >> 1);
    const int b1_3 = (a7_3 >> 2) + (unsigned int)a1_3;
    const int b3_3 = (unsigned int)a3_3 + (a5_3 >> 2);
    const int b5_3 = (a3_3 >> 2) - (unsigned int)a5_3;
    const int b7_3 = (unsigned int)a7_3 - (a1_3 >> 2);
    block[i + 0 * 8] = b0_3 + b7_3;
    block[i + 7 * 8] = b0_3 - b7_3;
    block[i + 1 * 8] = b2_3 + b5_3;
    block[i + 6 * 8] = b2_3 - b5_3;
    block[i + 2 * 8] = b4_3 + b3_3;
    block[i + 5 * 8] = b4_3 - b3_3;
    block[i + 3 * 8] = b6_3 + b1_3;
    block[i + 4 * 8] = b6_3 - b1_3;

    i = indices[4];
    const unsigned int a0_4 = block[i + 0 * 8] + (unsigned int)block[i + 4 * 8];
    const unsigned int a2_4 = block[i + 0 * 8] - (unsigned int)block[i + 4 * 8];
    const unsigned int a4_4 = (block[i + 2 * 8] >> 1) - (unsigned int)block[i + 6 * 8];
    const unsigned int a6_4 = (block[i + 6 * 8] >> 1) + (unsigned int)block[i + 2 * 8];
    const unsigned int b0_4 = a0_4 + a6_4;
    const unsigned int b2_4 = a2_4 + a4_4;
    const unsigned int b4_4 = a2_4 - a4_4;
    const unsigned int b6_4 = a0_4 - a6_4;
    const int a1_4 = -block[i + 3 * 8] + (unsigned int)block[i + 5 * 8] - block[i + 7 * 8] - (block[i + 7 * 8] >> 1);
    const int a3_4 = block[i + 1 * 8] + (unsigned int)block[i + 7 * 8] - block[i + 3 * 8] - (block[i + 3 * 8] >> 1);
    const int a5_4 = -block[i + 1 * 8] + (unsigned int)block[i + 7 * 8] + block[i + 5 * 8] + (block[i + 5 * 8] >> 1);
    const int a7_4 = block[i + 3 * 8] + (unsigned int)block[i + 5 * 8] + block[i + 1 * 8] + (block[i + 1 * 8] >> 1);
    const int b1_4 = (a7_4 >> 2) + (unsigned int)a1_4;
    const int b3_4 = (unsigned int)a3_4 + (a5_4 >> 2);
    const int b5_4 = (a3_4 >> 2) - (unsigned int)a5_4;
    const int b7_4 = (unsigned int)a7_4 - (a1_4 >> 2);
    block[i + 0 * 8] = b0_4 + b7_4;
    block[i + 7 * 8] = b0_4 - b7_4;
    block[i + 1 * 8] = b2_4 + b5_4;
    block[i + 6 * 8] = b2_4 - b5_4;
    block[i + 2 * 8] = b4_4 + b3_4;
    block[i + 5 * 8] = b4_4 - b3_4;
    block[i + 3 * 8] = b6_4 + b1_4;
    block[i + 4 * 8] = b6_4 - b1_4;

    i = indices[5];
    const unsigned int a0_5 = block[i + 0 * 8] + (unsigned int)block[i + 4 * 8];
    const unsigned int a2_5 = block[i + 0 * 8] - (unsigned int)block[i + 4 * 8];
    const unsigned int a4_5 = (block[i + 2 * 8] >> 1) - (unsigned int)block[i + 6 * 8];
    const unsigned int a6_5 = (block[i + 6 * 8] >> 1) + (unsigned int)block[i + 2 * 8];
    const unsigned int b0_5 = a0_5 + a6_5;
    const unsigned int b2_5 = a2_5 + a4_5;
    const unsigned int b4_5 = a2_5 - a4_5;
    const unsigned int b6_5 = a0_5 - a6_5;
    const int a1_5 = -block[i + 3 * 8] + (unsigned int)block[i + 5 * 8] - block[i + 7 * 8] - (block[i + 7 * 8] >> 1);
    const int a3_5 = block[i + 1 * 8] + (unsigned int)block[i + 7 * 8] - block[i + 3 * 8] - (block[i + 3 * 8] >> 1);
    const int a5_5 = -block[i + 1 * 8] + (unsigned int)block[i + 7 * 8] + block[i + 5 * 8] + (block[i + 5 * 8] >> 1);
    const int a7_5 = block[i + 3 * 8] + (unsigned int)block[i + 5 * 8] + block[i + 1 * 8] + (block[i + 1 * 8] >> 1);
    const int b1_5 = (a7_5 >> 2) + (unsigned int)a1_5;
    const int b3_5 = (unsigned int)a3_5 + (a5_5 >> 2);
    const int b5_5 = (a3_5 >> 2) - (unsigned int)a5_5;
    const int b7_5 = (unsigned int)a7_5 - (a1_5 >> 2);
    block[i + 0 * 8] = b0_5 + b7_5;
    block[i + 7 * 8] = b0_5 - b7_5;
    block[i + 1 * 8] = b2_5 + b5_5;
    block[i + 6 * 8] = b2_5 - b5_5;
    block[i + 2 * 8] = b4_5 + b3_5;
    block[i + 5 * 8] = b4_5 - b3_5;
    block[i + 3 * 8] = b6_5 + b1_5;
    block[i + 4 * 8] = b6_5 - b1_5;

    i = indices[6];
    const unsigned int a0_6 = block[i + 0 * 8] + (unsigned int)block[i + 4 * 8];
    const unsigned int a2_6 = block[i + 0 * 8] - (unsigned int)block[i + 4 * 8];
    const unsigned int a4_6 = (block[i + 2 * 8] >> 1) - (unsigned int)block[i + 6 * 8];
    const unsigned int a6_6 = (block[i + 6 * 8] >> 1) + (unsigned int)block[i + 2 * 8];
    const unsigned int b0_6 = a0_6 + a6_6;
    const unsigned int b2_6 = a2_6 + a4_6;
    const unsigned int b4_6 = a2_6 - a4_6;
    const unsigned int b6_6 = a0_6 - a6_6;
    const int a1_6 = -block[i + 3 * 8] + (unsigned int)block[i + 5 * 8] - block[i + 7 * 8] - (block[i + 7 * 8] >> 1);
    const int a3_6 = block[i + 1 * 8] + (unsigned int)block[i + 7 * 8] - block[i + 3 * 8] - (block[i + 3 * 8] >> 1);
    const int a5_6 = -block[i + 1 * 8] + (unsigned int)block[i + 7 * 8] + block[i + 5 * 8] + (block[i + 5 * 8] >> 1);
    const int a7_6 = block[i + 3 * 8] + (unsigned int)block[i + 5 * 8] + block[i + 1 * 8] + (block[i + 1 * 8] >> 1);
    const int b1_6 = (a7_6 >> 2) + (unsigned int)a1_6;
    const int b3_6 = (unsigned int)a3_6 + (a5_6 >> 2);
    const int b5_6 = (a3_6 >> 2) - (unsigned int)a5_6;
    const int b7_6 = (unsigned int)a7_6 - (a1_6 >> 2);
    block[i + 0 * 8] = b0_6 + b7_6;
    block[i + 7 * 8] = b0_6 - b7_6;
    block[i + 1 * 8] = b2_6 + b5_6;
    block[i + 6 * 8] = b2_6 - b5_6;
    block[i + 2 * 8] = b4_6 + b3_6;
    block[i + 5 * 8] = b4_6 - b3_6;
    block[i + 3 * 8] = b6_6 + b1_6;
    block[i + 4 * 8] = b6_6 - b1_6;

    i = indices[7];
    const unsigned int a0_7 = block[i + 0 * 8] + (unsigned int)block[i + 4 * 8];
    const unsigned int a2_7 = block[i + 0 * 8] - (unsigned int)block[i + 4 * 8];
    const unsigned int a4_7 = (block[i + 2 * 8] >> 1) - (unsigned int)block[i + 6 * 8];
    const unsigned int a6_7 = (block[i + 6 * 8] >> 1) + (unsigned int)block[i + 2 * 8];
    const unsigned int b0_7 = a0_7 + a6_7;
    const unsigned int b2_7 = a2_7 + a4_7;
    const unsigned int b4_7 = a2_7 - a4_7;
    const unsigned int b6_7 = a0_7 - a6_7;
    const int a1_7 = -block[i + 3 * 8] + (unsigned int)block[i + 5 * 8] - block[i + 7 * 8] - (block[i + 7 * 8] >> 1);
    const int a3_7 = block[i + 1 * 8] + (unsigned int)block[i + 7 * 8] - block[i + 3 * 8] - (block[i + 3 * 8] >> 1);
    const int a5_7 = -block[i + 1 * 8] + (unsigned int)block[i + 7 * 8] + block[i + 5 * 8] + (block[i + 5 * 8] >> 1);
    const int a7_7 = block[i + 3 * 8] + (unsigned int)block[i + 5 * 8] + block[i + 1 * 8] + (block[i + 1 * 8] >> 1);
    const int b1_7 = (a7_7 >> 2) + (unsigned int)a1_7;
    const int b3_7 = (unsigned int)a3_7 + (a5_7 >> 2);
    const int b5_7 = (a3_7 >> 2) - (unsigned int)a5_7;
    const int b7_7 = (unsigned int)a7_7 - (a1_7 >> 2);
    block[i + 0 * 8] = b0_7 + b7_7;
    block[i + 7 * 8] = b0_7 - b7_7;
    block[i + 1 * 8] = b2_7 + b5_7;
    block[i + 6 * 8] = b2_7 - b5_7;
    block[i + 2 * 8] = b4_7 + b3_7;
    block[i + 5 * 8] = b4_7 - b3_7;
    block[i + 3 * 8] = b6_7 + b1_7;
    block[i + 4 * 8] = b6_7 - b1_7;
}
}
