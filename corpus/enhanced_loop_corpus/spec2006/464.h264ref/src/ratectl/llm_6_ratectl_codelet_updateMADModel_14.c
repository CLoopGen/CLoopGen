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
    int j;
    for (j = 0; j <= 19; j++) {
        PictureRejected[j + 1] = PictureRejected[j] ? FALSE : FALSE;
        PictureRejected[j] = FALSE;
    }
    PictureRejected[20] = FALSE;
}
