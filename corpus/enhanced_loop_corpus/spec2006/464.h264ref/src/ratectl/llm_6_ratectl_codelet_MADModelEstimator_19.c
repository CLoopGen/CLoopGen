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
    double temp_a01 = a01;
    double temp_a11 = a11;
    double temp_b0 = b0;
    double temp_b1 = b1;
    double temp_a00 = a00;

    for (i = 0; i < n_windowSize; i++) {
        if (!PictureRejected[i]) {
            temp_a00 += 1.0;
            temp_a01 += ReferenceMAD[i];
            temp_a11 += ReferenceMAD[i] * ReferenceMAD[i];
            temp_b0 += PictureMAD[i];
            temp_b1 += PictureMAD[i] * ReferenceMAD[i];
        }
    }

    a00 = temp_a00;
    a01 = temp_a01;
    a10 = temp_a01;
    a11 = temp_a11;
    b0 = temp_b0;
    b1 = temp_b1;
}
