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
        int offset = pass * 8; // Reduced nesting: flattened logic with index scaling
        A1 = *(a1 + 0 + offset);
        A9 = *(a1 + 1 + offset);
        A2 = *((a1 + 2) + 0 + offset);
        A10 = *((a1 + 2) + 1 + offset);
        A3 = *(a3 + 0 + offset);
        A11 = *(a3 + 1 + offset);
        A4 = *((a3 + 2) + 0 + offset);
        A12 = *((a3 + 2) + 1 + offset);
        A5 = *(a5 + 0 + offset);
        A13 = *(a5 + 1 + offset);
        A6 = *((a5 + 2) + 0 + offset);
        A14 = *((a5 + 2) + 1 + offset);
        A7 = *(a7 + 0 + offset);
        A15 = *(a7 + 1 + offset);
        A8 = *((a7 + 2) + 0 + offset);
        A16 = *((a7 + 2) + 1 + offset);
        B1 = *(b1 + 0 + offset);
        B9 = *(b1 + 1 + offset);
        B2 = *(b2 + 0 + offset);
        B10 = *(b2 + 1 + offset);
        B3 = *(b3 + 0 + offset);
        B11 = *(b3 + 1 + offset);
        B4 = *(b4 + 0 + offset);
        B12 = *(b4 + 1 + offset);
        B5 = *(b5 + 0 + offset);
        B13 = *(b5 + 1 + offset);
        B6 = *(b6 + 0 + offset);
        B14 = *(b6 + 1 + offset);
        B7 = *(b7 + 0 + offset);
        B15 = *(b7 + 1 + offset);
        B8 = *(b8 + 0 + offset);
        B16 = *(b8 + 1 + offset);

        if (b1 == a1) {
            if (b2 == (a1 + 2)) {
                for (int i = 0; i < 16; i++) {
                    static const float* src[] = {&A1,&A9,&A3,&A11,&A5,&A13,&A7,&A15,&A2,&A10,&A4,&A12,&A6,&A14,&A8,&A16};
                    *(buffer + i) = *(src[i]);
                }
            } else {
                for (int i = 0; i < 16; i++) {
                    static const float* src[] = {&A1,&A9,&A3,&A11,&A5,&A13,&A7,&A15,&B2,&B10,&B4,&B12,&B6,&B14,&B8,&B16};
                    *(buffer + i) = *(src[i]);
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
                for (int i = 0; i < 16; i++) {
                    static const float* src[] = {&A2,&A10,&A4,&A12,&A6,&A14,&A8,&A16,&A1,&A9,&A3,&A11,&A5,&A13,&A7,&A15};
                    *(buffer + i) = *(src[i]);
                }
            } else {
                for (int i = 0; i < 16; i++) {
                    static const float* src[] = {&A2,&A10,&A4,&A12,&A6,&A14,&A8,&A16,&B2,&B10,&B4,&B12,&B6,&B14,&B8,&B16};
                    *(buffer + i) = *(src[i]);
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
                for (int i = 0; i < 16; i++) {
                    static const float* src[] = {&B1,&B9,&B3,&B11,&B5,&B13,&B7,&B15,&A2,&A10,&A4,&A12,&A6,&A14,&A8,&A16};
                    *(buffer + i) = *(src[i]);
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
                for (int i = 0; i < 16; i++) {
                    static const float* src[] = {&B1,&B9,&B3,&B11,&B5,&B13,&B7,&B15,&A1,&A9,&A3,&A11,&A5,&A13,&A7,&A15};
                    *(buffer + i) = *(src[i]);
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
                for (int i = 0; i < 16; i++) {
                    static const float* src[] = {&B1,&B9,&B3,&B11,&B5,&B13,&B7,&B15,&B2,&B10,&B4,&B12,&B6,&B14,&B8,&B16};
                    *(buffer + i) = *(src[i]);
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
