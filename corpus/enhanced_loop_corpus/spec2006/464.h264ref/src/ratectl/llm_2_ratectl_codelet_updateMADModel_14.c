#include <stdio.h>

#include <inttypes.h>

typedef enum {
    FALSE,
    TRUE
} Boolean;

extern Boolean PictureRejected[21];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (i = 0; i < 20; i += 2) {
        PictureRejected[i] = FALSE;
    }
    for (i = 1; i < 20; i += 2) {
        PictureRejected[i] = FALSE;
    }
}
