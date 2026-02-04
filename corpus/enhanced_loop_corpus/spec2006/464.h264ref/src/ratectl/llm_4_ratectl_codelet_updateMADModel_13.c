#include <stdio.h>

#include <inttypes.h>

extern double PPictureMAD[21];
extern double PictureMAD[21];
extern double ReferenceMAD[21];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 19; i > 0; i--) {
    if (i % 2 == 0) {
        PPictureMAD[i] = PPictureMAD[i - 1];
        PictureMAD[i] = PPictureMAD[i];
    } else {
        continue;
    }
    ReferenceMAD[i] = ReferenceMAD[i - 1];
}
}
