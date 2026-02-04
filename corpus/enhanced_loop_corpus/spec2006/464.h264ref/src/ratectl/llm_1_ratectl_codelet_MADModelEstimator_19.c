#include <stdio.h>

#include <inttypes.h>

typedef enum {
    FALSE,
    TRUE
} Boolean;

extern Boolean PictureRejected[21];
extern double PictureMAD[21];
extern double ReferenceMAD[21];
extern int n_windowSize;
extern int i;
extern double a00;
extern double a01;
extern double a10;
extern double a11;
extern double b0;
extern double b1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 1;
    for (i = 0; i < n_windowSize; i += stride) {
        for (int j = i; j < i + stride && j < n_windowSize; j++) {
            if (!PictureRejected[j]) {
                a00 = a00 + 1.;
                a01 += ReferenceMAD[j];
                a10 = a01;
                a11 += ReferenceMAD[j] * ReferenceMAD[j];
                b0 += PictureMAD[j];
                b1 += PictureMAD[j] * ReferenceMAD[j];
            }
        }
    }
}
