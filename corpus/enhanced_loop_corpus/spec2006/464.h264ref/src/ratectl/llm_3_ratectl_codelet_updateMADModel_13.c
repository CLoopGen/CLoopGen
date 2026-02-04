#include <stdio.h>

#include <inttypes.h>

extern double PPictureMAD[21];
extern double PictureMAD[21];
extern double ReferenceMAD[21];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access using index mapping array
    int indices[20];
    for (int j = 0; j < 20; j++) {
        indices[j] = 19 - j; // reverse order access: 19,18,...,0
    }
    for (int j = 0; j < 19; j++) {
        int i = indices[j];
        int next_i = indices[j + 1];
        PPictureMAD[i] = PPictureMAD[next_i];
        PictureMAD[i] = PPictureMAD[i];
        ReferenceMAD[i] = ReferenceMAD[next_i];
    }
}
