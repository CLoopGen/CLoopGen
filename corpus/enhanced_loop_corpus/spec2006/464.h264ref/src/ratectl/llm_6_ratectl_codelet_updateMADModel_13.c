#include <stdio.h>

#include <inttypes.h>

extern double PPictureMAD[21];
extern double PictureMAD[21];
extern double ReferenceMAD[21];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 19; i > 0; i--) {
    PictureMAD[i] = PPictureMAD[i - 1];
    PPictureMAD[i] = PictureMAD[i - 1];
    ReferenceMAD[i] = ReferenceMAD[i - 1];
}
}
