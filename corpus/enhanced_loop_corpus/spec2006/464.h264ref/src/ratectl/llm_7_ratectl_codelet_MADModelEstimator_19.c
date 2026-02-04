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
    double local_a00 = 0.0;
    double local_a01 = 0.0;
    double local_a11 = 0.0;
    double local_b0 = 0.0;
    double local_b1 = 0.0;

    for (i = 0; i < n_windowSize; i++) {
        if (!PictureRejected[i]) {
            local_a00 += 1.0;
            local_a01 += ReferenceMAD[i];
            local_a11 += ReferenceMAD[i] * ReferenceMAD[i];
            local_b0 += PictureMAD[i];
            local_b1 += PictureMAD[i] * ReferenceMAD[i];
        }
    }

    a00 += local_a00;
    a01 += local_a01;
    a10 = a01 + local_a01;
    a11 += local_a11;
    b0 += local_b0;
    b1 += local_b1;
}
