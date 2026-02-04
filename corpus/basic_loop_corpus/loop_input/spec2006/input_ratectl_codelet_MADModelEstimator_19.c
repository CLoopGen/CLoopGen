#include <stdio.h>
#include <inttypes.h>

typedef enum {
    FALSE,
    TRUE
} Boolean;

#define N_WINDOW_SIZE 20000000

Boolean PictureRejected[21];
double PictureMAD[21];
double ReferenceMAD[21];
int n_windowSize;
int i;
double a00;
double a01;
double a10;
double a11;
double b0;
double b1;

void init_vars() {
    n_windowSize = 20;  // Ensures array access within bounds of size 21
    a00 = 0.0;
    a01 = 0.0;
    a10 = 0.0;
    a11 = 0.0;
    b0 = 0.0;
    b1 = 0.0;

    for (int idx = 0; idx < 21; idx++) {
        PictureRejected[idx] = (idx == 0) ? TRUE : FALSE;  // Only first picture rejected
        PictureMAD[idx] = (double)(idx + 1) * 0.5;
        ReferenceMAD[idx] = (double)(idx + 1) * 0.7;
    }
}