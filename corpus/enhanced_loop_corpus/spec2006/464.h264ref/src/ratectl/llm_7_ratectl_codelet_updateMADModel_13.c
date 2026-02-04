#include <stdio.h>

#include <inttypes.h>

extern double PPictureMAD[21];
extern double PictureMAD[21];
extern double ReferenceMAD[21];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i <= 19; i++) {
    double temp_p = PPictureMAD[i - 1];
    double temp_r = ReferenceMAD[i - 1];
    PPictureMAD[i] = temp_p;
    PictureMAD[i] = temp_p;
    ReferenceMAD[i] = temp_r;
}
}
