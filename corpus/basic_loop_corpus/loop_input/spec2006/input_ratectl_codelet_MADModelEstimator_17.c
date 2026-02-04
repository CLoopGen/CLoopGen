#include <stdio.h>
#include <inttypes.h>

typedef enum {
    FALSE,
    TRUE
} Boolean;

Boolean PictureRejected[21];
double PictureMAD[21];
int n_windowSize;
int i;
double oneSampleQ;

void init_vars() {
    n_windowSize = 21;

    for (int idx = 0; idx < n_windowSize; idx++) {
        PictureRejected[idx] = (idx % 7 == 0) ? TRUE : FALSE;
        PictureMAD[idx] = (double)(idx * 1153); 
    }

    oneSampleQ = 0.0;
}