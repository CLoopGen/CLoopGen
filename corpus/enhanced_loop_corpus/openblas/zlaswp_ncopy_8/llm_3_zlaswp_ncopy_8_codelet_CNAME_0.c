#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *buffer;
extern float *a1;
extern float *a3;
extern float *a5;
extern float *a7;
extern float *b1;
extern float *b2;
extern float *b3;
extern float *b4;
extern float *b5;
extern float *b6;
extern float *b7;
extern float *b8;
extern float A1;
extern float A2;
extern float A3;
extern float A4;
extern float A5;
extern float A6;
extern float A7;
extern float A8;
extern float B1;
extern float B2;
extern float B3;
extern float B4;
extern float B5;
extern float B6;
extern float B7;
extern float B8;
extern float A9;
extern float A10;
extern float A11;
extern float A12;
extern float A13;
extern float A14;
extern float A15;
extern float A16;
extern float B9;
extern float B10;
extern float B11;
extern float B12;
extern float B13;
extern float B14;
extern float B15;
extern float B16;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int pass = 0; pass < 2; ++pass) {
    // Variant 2: Strided memory access with indirect addressing via index array
    // Simulate non-unit stride or scatter/gather pattern using fixed offset array
    const int offsets[8] = {0, 1, 2, 3, 4, 5, 6, 7}; // Logical offsets for clarity and potential vectorization

    // Load from strided locations using indirect indexing
    A1 = *(a1 + offsets[0]); A9 = *(a1 + offsets[1]);
    A2 = *((a1 + 2) + offsets[0]); A10 = *((a1 + 2) + offsets[1]);
    A3 = *(a3 + offsets[0]); A11 = *(a3 + offsets[1]);
    A4 = *((a3 + 2) + offsets[0]); A12 = *((a3 + 2) + offsets[1]);
    A5 = *(a5 + offsets[0]); A13 = *(a5 + offsets[1]);
    A6 = *((a5 + 2) + offsets[0]); A14 = *((a5 + 2) + offsets[1]);
    A7 = *(a7 + offsets[0]); A15 = *(a7 + offsets[1]);
    A8 = *((a7 + 2) + offsets[0]); A16 = *((a7 + 2) + offsets[1]);

    B1 = *(b1 + offsets[0]); B9 = *(b1 + offsets[1]);
    B2 = *(b2 + offsets[0]); B10 = *(b2 + offsets[1]);
    B3 = *(b3 + offsets[0]); B11 = *(b3 + offsets[1]);
    B4 = *(b4 + offsets[0]); B12 = *(b4 + offsets[1]);
    B5 = *(b5 + offsets[0]); B13 = *(b5 + offsets[1]);
    B6 = *(b6 + offsets[0]); B14 = *(b6 + offsets[1]);
    B7 = *(b7 + offsets[0]); B15 = *(b7 + offsets[1]);
    B8 = *(b8 + offsets[0]); B16 = *(b8 + offsets[1]);

    if (b1 == a1) {
        if (b2 == (a1 + 2)) {
            for (int i = 0; i < 16; i++) {
                switch(i) {
                    case 0: buffer[i] = A1; break; case 1: buffer[i] = A9; break;
                    case 2: buffer[i] = A3; break; case 3: buffer[i] = A11; break;
                    case 4: buffer[i] = A5; break; case 5: buffer[i] = A13; break;
                    case 6: buffer[i] = A7; break; case 7: buffer[i] = A15; break;
                    case 8: buffer[i] = A2; break; case 9: buffer[i] = A10; break;
                    case 10: buffer[i] = A4; break; case 11: buffer[i] = A12; break;
                    case 12: buffer[i] = A6; break; case 13: buffer[i] = A14; break;
                    case 14: buffer[i] = A8; break; case 15: buffer[i] = A16; break;
                }
            }
        } else {
            buffer[0] = A1; buffer[1] = A9; buffer[2] = A3; buffer[3] = A11;
            buffer[4] = A5; buffer[5] = A13; buffer[6] = A7; buffer[7] = A15;
            buffer[8] = B2; buffer[9] = B10; buffer[10] = B4; buffer[11] = B12;
            buffer[12] = B6; buffer[13] = B14; buffer[14] = B8; buffer[15] = B16;

            *(b2 + 0) = A2; *(b2 + 1) = A10; *(b4 + 0) = A4; *(b4 + 1) = A12;
            *(b6 + 0) = A6; *(b6 + 1) = A14; *(b8 + 0) = A8; *(b8 + 1) = A16;
        }
    } else if (b1 == (a1 + 2)) {
        if (b2 == (a1 + 2)) {
            buffer[0] = A2; buffer[1] = A10; buffer[2] = A4; buffer[3] = A12;
            buffer[4] = A6; buffer[5] = A14; buffer[6] = A8; buffer[7] = A16;
            buffer[8] = A1; buffer[9] = A9; buffer[10] = A3; buffer[11] = A11;
            buffer[12] = A5; buffer[13] = A13; buffer[14] = A7; buffer[15] = A15;
        } else {
            buffer[0] = A2; buffer[1] = A10; buffer[2] = A4; buffer[3] = A12;
            buffer[4] = A6; buffer[5] = A14; buffer[6] = A8; buffer[7] = A16;
            buffer[8] = B2; buffer[9] = B10; buffer[10] = B4; buffer[11] = B12;
            buffer[12] = B6; buffer[13] = B14; buffer[14] = B8; buffer[15] = B16;

            *(b2 + 0) = A1; *(b2 + 1) = A9; *(b4 + 0) = A3; *(b4 + 1) = A11;
            *(b6 + 0) = A5; *(b6 + 1) = A13; *(b8 + 0) = A7; *(b8 + 1) = A15;
        }
    } else {
        if (b2 == (a1 + 2)) {
            buffer[0] = B1; buffer[1] = B9; buffer[2] = B3; buffer[3] = B11;
            buffer[4] = B5; buffer[5] = B13; buffer[6] = B7; buffer[7] = B15;
            buffer[8] = A2; buffer[9] = A10; buffer[10] = A4; buffer[11] = A12;
            buffer[12] = A6; buffer[13] = A14; buffer[14] = A8; buffer[15] = A16;

            *(b1 + 0) = A1; *(b1 + 1) = A9; *(b3 + 0) = A3; *(b3 + 1) = A11;
            *(b5 + 0) = A5; *(b5 + 1) = A13; *(b7 + 0) = A7; *(b7 + 1) = A15;
        } else if (b2 == b1) {
            buffer[0] = B1; buffer[1] = B9; buffer[2] = B3; buffer[3] = B11;
            buffer[4] = B5; buffer[5] = B13; buffer[6] = B7; buffer[7] = B15;
            buffer[8] = A1; buffer[9] = A9; buffer[10] = A3; buffer[11] = A11;
            buffer[12] = A5; buffer[13] = A13; buffer[14] = A7; buffer[15] = A15;

            *(b1 + 0) = A2; *(b1 + 1) = A10; *(b3 + 0) = A4; *(b3 + 1) = A12;
            *(b5 + 0) = A6; *(b5 + 1) = A14; *(b7 + 0) = A8; *(b7 + 1) = A16;
        } else {
            buffer[0] = B1; buffer[1] = B9; buffer[2] = B3; buffer[3] = B11;
            buffer[4] = B5; buffer[5] = B13; buffer[6] = B7; buffer[7] = B15;
            buffer[8] = B2; buffer[9] = B10; buffer[10] = B4; buffer[11] = B12;
            buffer[12] = B6; buffer[13] = B14; buffer[14] = B8; buffer[15] = B16;

            *(b1 + 0) = A1; *(b1 + 1) = A9; *(b2 + 0) = A2; *(b2 + 1) = A10;
            *(b3 + 0) = A3; *(b3 + 1) = A11; *(b4 + 0) = A4; *(b4 + 1) = A12;
            *(b5 + 0) = A5; *(b5 + 1) = A13; *(b6 + 0) = A6; *(b6 + 1) = A14;
            *(b7 + 0) = A7; *(b7 + 1) = A15; *(b8 + 0) = A8; *(b8 + 1) = A16;
        }
    }

    b1 += 4 * lda;
    b2 += 4 * lda;
    b3 += 4 * lda;
    b4 += 4 * lda;
    b5 += 4 * lda;
    b6 += 4 * lda;
    b7 += 4 * lda;
    b8 += 4 * lda;
    a1 += 4;
    a3 += 4;
    a5 += 4;
    a7 += 4;
    buffer += 16;
}
}
