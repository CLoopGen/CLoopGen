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
    // Variant 2: Reverse consecutive memory access (backward traversal)
    for (i = n_windowSize - 1; i >= 0; i--) {
        if (!PictureRejected[i]) {
            a00 = a00 + 1.;
            a01 += ReferenceMAD[i];
            a10 = a01;
            a11 += ReferenceMAD[i] * ReferenceMAD[i];
            b0 += PictureMAD[i];
            b1 += PictureMAD[i] * ReferenceMAD[i];
        }
    }
}
