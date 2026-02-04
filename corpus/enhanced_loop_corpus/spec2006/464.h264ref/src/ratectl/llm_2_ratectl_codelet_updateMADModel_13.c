#include <stdio.h>

#include <inttypes.h>

extern double PPictureMAD[21];
extern double PictureMAD[21];
extern double ReferenceMAD[21];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access (access every other element, then fill in)
    for (i = 18; i >= 0; i -= 2) {
        if (i + 1 <= 19) {
            PPictureMAD[i + 1] = PPictureMAD[i];
            PictureMAD[i + 1] = PPictureMAD[i + 1];
            ReferenceMAD[i + 1] = ReferenceMAD[i];
        }
        if (i - 1 >= 0) {
            PPictureMAD[i - 1] = PPictureMAD[i - 2];
            PictureMAD[i - 1] = PPictureMAD[i - 1];
            ReferenceMAD[i - 1] = ReferenceMAD[i - 2];
        }
    }
    // Final sequential pass to ensure all elements are updated (handle stride gaps)
    for (i = 19; i > 0; i--) {
        if (PPictureMAD[i] == 0 && i - 1 >= 0) { // assuming zero-initialization, fallback
            PPictureMAD[i] = PPictureMAD[i - 1];
            PictureMAD[i] = PPictureMAD[i];
            ReferenceMAD[i] = ReferenceMAD[i - 1];
        }
    }
}
