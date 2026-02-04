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
for (i = 0; i < n_windowSize; i++) {
    a00 = a00 + (PictureRejected[i] ? 0. : 1.);
    a01 += (PictureRejected[i] ? 0. : ReferenceMAD[i]);
    a10 = a01;
    a11 += (PictureRejected[i] ? 0. : ReferenceMAD[i] * ReferenceMAD[i]);
    b0 += (PictureRejected[i] ? 0. : PictureMAD[i]);
    b1 += (PictureRejected[i] ? 0. : PictureMAD[i] * ReferenceMAD[i]);
}
}
