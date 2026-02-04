#include <stdio.h>
#include <inttypes.h>

typedef enum {
    FALSE,
    TRUE
} Boolean;

double MADPictureC1 = 0.0;
Boolean PictureRejected[21] = {FALSE};
double PictureMAD[21] = {0.0};
double ReferenceMAD[21] = {1.0};
int n_windowSize = 21;
int n_realSize = 1;
int i = 0;
double oneSampleQ = -1.0;
Boolean estimateX2 = FALSE;

void init_vars() {
    n_windowSize = 21;
    n_realSize = 1;
    oneSampleQ = -1.0;
    estimateX2 = FALSE;
    MADPictureC1 = 0.0;

    for (int idx = 0; idx < 21; idx++) {
        PictureRejected[idx] = (idx % 7 == 0) ? TRUE : FALSE;
        PictureMAD[idx] = (double)(idx * 11 + 1);
        ReferenceMAD[idx] = (double)(idx * 3 + 1);
    }
}