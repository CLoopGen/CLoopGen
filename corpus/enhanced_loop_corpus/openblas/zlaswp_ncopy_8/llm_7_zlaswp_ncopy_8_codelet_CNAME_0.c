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
    A1 = *(a1 + 0);
    A9 = *(a1 + 1);
    A2 = *((a1 + 2) + 0);
    A10 = *((a1 + 2) + 1);
    A3 = *(a3 + 0);
    A11 = *(a3 + 1);
    A4 = *((a3 + 2) + 0);
    A12 = *((a3 + 2) + 1);
    A5 = *(a5 + 0);
    A13 = *(a5 + 1);
    A6 = *((a5 + 2) + 0);
    A14 = *((a5 + 2) + 1);
    A7 = *(a7 + 0);
    A15 = *(a7 + 1);
    A8 = *((a7 + 2) + 0);
    A16 = *((a7 + 2) + 1);
    B1 = *(b1 + 0);
    B9 = *(b1 + 1);
    B2 = *(b2 + 0);
    B10 = *(b2 + 1);
    B3 = *(b3 + 0);
    B11 = *(b3 + 1);
    B4 = *(b4 + 0);
    B12 = *(b4 + 1);
    B5 = *(b5 + 0);
    B13 = *(b5 + 1);
    B6 = *(b6 + 0);
    B14 = *(b6 + 1);
    B7 = *(b7 + 0);
    B15 = *(b7 + 1);
    B8 = *(b8 + 0);
    B16 = *(b8 + 1);

    float C1 = A1 + B1;
    float C2 = A2 + B2;
    float C3 = A3 + B3;
    float C4 = A4 + B4;
    float C5 = A5 + B5;
    float C6 = A6 + B6;
    float C7 = A7 + B7;
    float C8 = A8 + B8;
    float C9 = A9 + B9;
    float C10 = A10 + B10;
    float C11 = A11 + B11;
    float C12 = A12 + B12;
    float C13 = A13 + B13;
    float C14 = A14 + B14;
    float C15 = A15 + B15;
    float C16 = A16 + B16;

    if (b1 == a1) {
        if (b2 == (a1 + 2)) {
            *(buffer + 0) = C1;
            *(buffer + 1) = C9;
            *(buffer + 2) = C3;
            *(buffer + 3) = C11;
            *(buffer + 4) = C5;
            *(buffer + 5) = C13;
            *(buffer + 6) = C7;
            *(buffer + 7) = C15;
            *(buffer + 8) = C2;
            *(buffer + 9) = C10;
            *(buffer + 10) = C4;
            *(buffer + 11) = C12;
            *(buffer + 12) = C6;
            *(buffer + 13) = C14;
            *(buffer + 14) = C8;
            *(buffer + 15) = C16;
        } else {
            *(buffer + 0) = C1;
            *(buffer + 1) = C9;
            *(buffer + 2) = C3;
            *(buffer + 3) = C11;
            *(buffer + 4) = C5;
            *(buffer + 5) = C13;
            *(buffer + 6) = C7;
            *(buffer + 7) = C15;
            *(buffer + 8) = C2;
            *(buffer + 9) = C10;
            *(buffer + 10) = C4;
            *(buffer + 11) = C12;
            *(buffer + 12) = C6;
            *(buffer + 13) = C14;
            *(buffer + 14) = C8;
            *(buffer + 15) = C16;
            *(b2 + 0) = C2;
            *(b2 + 1) = C10;
            *(b4 + 0) = C4;
            *(b4 + 1) = C12;
            *(b6 + 0) = C6;
            *(b6 + 1) = C14;
            *(b8 + 0) = C8;
            *(b8 + 1) = C16;
        }
    } else if (b1 == (a1 + 2)) {
        if (b2 == (a1 + 2)) {
            *(buffer + 0) = C2;
            *(buffer + 1) = C10;
            *(buffer + 2) = C4;
            *(buffer + 3) = C12;
            *(buffer + 4) = C6;
            *(buffer + 5) = C14;
            *(buffer + 6) = C8;
            *(buffer + 7) = C16;
            *(buffer + 8) = C1;
            *(buffer + 9) = C9;
            *(buffer + 10) = C3;
            *(buffer + 11) = C11;
            *(buffer + 12) = C5;
            *(buffer + 13) = C13;
            *(buffer + 14) = C7;
            *(buffer + 15) = C15;
        } else {
            *(buffer + 0) = C2;
            *(buffer + 1) = C10;
            *(buffer + 2) = C4;
            *(buffer + 3) = C12;
            *(buffer + 4) = C6;
            *(buffer + 5) = C14;
            *(buffer + 6) = C8;
            *(buffer + 7) = C16;
            *(buffer + 8) = C2;
            *(buffer + 9) = C10;
            *(buffer + 10) = C4;
            *(buffer + 11) = C12;
            *(buffer + 12) = C6;
            *(buffer + 13) = C14;
            *(buffer + 14) = C8;
            *(buffer + 15) = C16;
            *(b2 + 0) = C1;
            *(b2 + 1) = C9;
            *(b4 + 0) = C3;
            *(b4 + 1) = C11;
            *(b6 + 0) = C5;
            *(b6 + 1) = C13;
            *(b8 + 0) = C7;
            *(b8 + 1) = C15;
        }
    } else {
        if (b2 == (a1 + 2)) {
            *(buffer + 0) = C1;
            *(buffer + 1) = C9;
            *(buffer + 2) = C3;
            *(buffer + 3) = C11;
            *(buffer + 4) = C5;
            *(buffer + 5) = C13;
            *(buffer + 6) = C7;
            *(buffer + 7) = C15;
            *(buffer + 8) = C2;
            *(buffer + 9) = C10;
            *(buffer + 10) = C4;
            *(buffer + 11) = C12;
            *(buffer + 12) = C6;
            *(buffer + 13) = C14;
            *(buffer + 14) = C8;
            *(buffer + 15) = C16;
            *(b1 + 0) = C1;
            *(b1 + 1) = C9;
            *(b3 + 0) = C3;
            *(b3 + 1) = C11;
            *(b5 + 0) = C5;
            *(b5 + 1) = C13;
            *(b7 + 0) = C7;
            *(b7 + 1) = C15;
        } else if (b2 == b1) {
            *(buffer + 0) = C1;
            *(buffer + 1) = C9;
            *(buffer + 2) = C3;
            *(buffer + 3) = C11;
            *(buffer + 4) = C5;
            *(buffer + 5) = C13;
            *(buffer + 6) = C7;
            *(buffer + 7) = C15;
            *(buffer + 8) = C1;
            *(buffer + 9) = C9;
            *(buffer + 10) = C3;
            *(buffer + 11) = C11;
            *(buffer + 12) = C5;
            *(buffer + 13) = C13;
            *(buffer + 14) = C7;
            *(buffer + 15) = C15;
            *(b1 + 0) = C2;
            *(b1 + 1) = C10;
            *(b3 + 0) = C4;
            *(b3 + 1) = C12;
            *(b5 + 0) = C6;
            *(b5 + 1) = C14;
            *(b7 + 0) = C8;
            *(b7 + 1) = C16;
        } else {
            *(buffer + 0) = C1;
            *(buffer + 1) = C9;
            *(buffer + 2) = C3;
            *(buffer + 3) = C11;
            *(buffer + 4) = C5;
            *(buffer + 5) = C13;
            *(buffer + 6) = C7;
            *(buffer + 7) = C15;
            *(buffer + 8) = C2;
            *(buffer + 9) = C10;
            *(buffer + 10) = C4;
            *(buffer + 11) = C12;
            *(buffer + 12) = C6;
            *(buffer + 13) = C14;
            *(buffer + 14) = C8;
            *(buffer + 15) = C16;
            *(b1 + 0) = C1;
            *(b1 + 1) = C9;
            *(b2 + 0) = C2;
            *(b2 + 1) = C10;
            *(b3 + 0) = C3;
            *(b3 + 1) = C11;
            *(b4 + 0) = C4;
            *(b4 + 1) = C12;
            *(b5 + 0) = C5;
            *(b5 + 1) = C13;
            *(b6 + 0) = C6;
            *(b6 + 1) = C14;
            *(b7 + 0) = C7;
            *(b7 + 1) = C15;
            *(b8 + 0) = C8;
            *(b8 + 1) = C16;
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
