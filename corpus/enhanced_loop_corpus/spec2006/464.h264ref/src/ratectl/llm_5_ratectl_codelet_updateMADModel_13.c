#include <stdio.h>

#include <inttypes.h>

extern double PPictureMAD[21];
extern double PictureMAD[21];
extern double ReferenceMAD[21];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 19; i > 0; i--) {
    PPictureMAD[i] = PPictureMAD[i - 1];
    if (i > 5) {
        PictureMAD[i] = PPictureMAD[i];
        ReferenceMAD[i] = ReferenceMAD[i - 1];
    } else {
        PictureMAD[i] = 0.0;
        ReferenceMAD[i] = 0.0;
    }
}
}
