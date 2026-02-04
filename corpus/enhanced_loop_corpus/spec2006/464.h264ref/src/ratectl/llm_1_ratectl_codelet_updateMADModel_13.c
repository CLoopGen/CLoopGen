#include <stdio.h>

#include <inttypes.h>

extern double PPictureMAD[21];
extern double PictureMAD[21];
extern double ReferenceMAD[21];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 19; i > 0; i -= 2) {
    if (i >= 1) {
        PPictureMAD[i] = PPictureMAD[i - 1];
        PictureMAD[i] = PPictureMAD[i];
        ReferenceMAD[i] = ReferenceMAD[i - 1];
    }
    if (i - 1 > 0) {
        PPictureMAD[i - 1] = PPictureMAD[i - 2];
        PictureMAD[i - 1] = PPictureMAD[i - 1];
        ReferenceMAD[i - 1] = ReferenceMAD[i - 2];
    }
}
}
