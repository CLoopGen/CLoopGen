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
for (int pass = 0; pass < 1; ++pass) {
    for (int block = 0; block < 2; ++block) {
        BLASLONG offset_a = block * 2;
        BLASLONG offset_b = block * 8;

        A1 = *(a1 + offset_a + 0);
        A9 = *(a1 + offset_a + 1);
        A2 = *((a1 + 2) + offset_a + 0);
        A10 = *((a1 + 2) + offset_a + 1);
        A3 = *(a3 + offset_a + 0);
        A11 = *(a3 + offset_a + 1);
        A4 = *((a3 + 2) + offset_a + 0);
        A12 = *((a3 + 2) + offset_a + 1);
        A5 = *(a5 + offset_a + 0);
        A13 = *(a5 + offset_a + 1);
        A6 = *((a5 + 2) + offset_a + 0);
        A14 = *((a5 + 2) + offset_a + 1);
        A7 = *(a7 + offset_a + 0);
        A15 = *(a7 + offset_a + 1);
        A8 = *((a7 + 2) + offset_a + 0);
        A16 = *((a7 + 2) + offset_a + 1);
        B1 = *(b1 + offset_b + 0);
        B9 = *(b1 + offset_b + 1);
        B2 = *(b2 + offset_b + 0);
        B10 = *(b2 + offset_b + 1);
        B3 = *(b3 + offset_b + 0);
        B11 = *(b3 + offset_b + 1);
        B4 = *(b4 + offset_b + 0);
        B12 = *(b4 + offset_b + 1);
        B5 = *(b5 + offset_b + 0);
        B13 = *(b5 + offset_b + 1);
        B6 = *(b6 + offset_b + 0);
        B14 = *(b6 + offset_b + 1);
        B7 = *(b7 + offset_b + 0);
        B15 = *(b7 + offset_b + 1);
        B8 = *(b8 + offset_b + 0);
        B16 = *(b8 + offset_b + 1);

        if (b1 == a1) {
            if (b2 == (a1 + 2)) {
                for (int i = 0; i < 8; ++i) {
                    *(buffer + offset_b + i) = *(a1 + offset_a + i % 2 + (i / 2) * 2);
                }
                for (int i = 8; i < 16; ++i) {
                    *(buffer + offset_b + i) = *(a1 + 2 + offset_a + (i - 8) % 2 + ((i - 8) / 2) * 2);
                }
            } else {
                for (int i = 0; i < 8; ++i) {
                    *(buffer + offset_b + i) = *(a1 + offset_a + i % 2 + (i / 2) * 2);
                }
                for (int i = 8; i < 16; ++i) {
                    *(buffer + offset_b + i) = *(b2 + (i - 8));
                }
                *(b2 + 0) = A2;
                *(b2 + 1) = A10;
                *(b4 + 0) = A4;
                *(b4 + 1) = A12;
                *(b6 + 0) = A6;
                *(b6 + 1) = A14;
                *(b8 + 0) = A8;
                *(b8 + 1) = A16;
            }
        } else if (b1 == (a1 + 2)) {
            if (b2 == (a1 + 2)) {
                for (int i = 0; i < 8; ++i) {
                    *(buffer + offset_b + i) = *(a1 + 2 + offset_a + i % 2 + (i / 2) * 2);
                }
                for (int i = 8; i < 16; ++i) {
                    *(buffer + offset_b + i) = *(a1 + offset_a + (i - 8) % 2 + ((i - 8) / 2) * 2);
                }
            } else {
                for (int i = 0; i < 8; ++i) {
                    *(buffer + offset_b + i) = *(a1 + 2 + offset_a + i % 2 + (i / 2) * 2);
                }
                for (int i = 8; i < 16; ++i) {
                    *(buffer + offset_b + i) = *(b2 + (i - 8));
                }
                *(b2 + 0) = A1;
                *(b2 + 1) = A9;
                *(b4 + 0) = A3;
                *(b4 + 1) = A11;
                *(b6 + 0) = A5;
                *(b6 + 1) = A13;
                *(b8 + 0) = A7;
                *(b8 + 1) = A15;
            }
        } else {
            if (b2 == (a1 + 2)) {
                for (int i = 0; i < 8; ++i) {
                    *(buffer + offset_b + i) = *(b1 + i);
                }
                for (int i = 8; i < 16; ++i) {
                    *(buffer + offset_b + i) = *(a1 + 2 + offset_a + (i - 8) % 2 + ((i - 8) / 2) * 2);
                }
                *(b1 + 0) = A1;
                *(b1 + 1) = A9;
                *(b3 + 0) = A3;
                *(b3 + 1) = A11;
                *(b5 + 0) = A5;
                *(b5 + 1) = A13;
                *(b7 + 0) = A7;
                *(b7 + 1) = A15;
            } else if (b2 == b1) {
                for (int i = 0; i < 8; ++i) {
                    *(buffer + offset_b + i) = *(b1 + i);
                }
                for (int i = 8; i < 16; ++i) {
                    *(buffer + offset_b + i) = *(a1 + offset_a + (i - 8) % 2 + ((i - 8) / 2) * 2);
                }
                *(b1 + 0) = A2;
                *(b1 + 1) = A10;
                *(b3 + 0) = A4;
                *(b3 + 1) = A12;
                *(b5 + 0) = A6;
                *(b5 + 1) = A14;
                *(b7 + 0) = A8;
                *(b7 + 1) = A16;
            } else {
                for (int i = 0; i < 16; ++i) {
                    *(buffer + offset_b + i) = *(b1 + i);
                }
                *(b1 + 0) = A1;
                *(b1 + 1) = A9;
                *(b2 + 0) = A2;
                *(b2 + 1) = A10;
                *(b3 + 0) = A3;
                *(b3 + 1) = A11;
                *(b4 + 0) = A4;
                *(b4 + 1) = A12;
                *(b5 + 0) = A5;
                *(b5 + 1) = A13;
                *(b6 + 0) = A6;
                *(b6 + 1) = A14;
                *(b7 + 0) = A7;
                *(b7 + 1) = A15;
                *(b8 + 0) = A8;
                *(b8 + 1) = A16;
            }
        }
    }

    b1 += 8 * lda;
    b2 += 8 * lda;
    b3 += 8 * lda;
    b4 += 8 * lda;
    b5 += 8 * lda;
    b6 += 8 * lda;
    b7 += 8 * lda;
    b8 += 8 * lda;
    a1 += 4;
    a3 += 4;
    a5 += 4;
    a7 += 4;
    buffer += 32;
}
}
