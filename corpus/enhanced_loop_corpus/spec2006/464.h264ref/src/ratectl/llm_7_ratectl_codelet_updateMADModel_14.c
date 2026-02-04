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
    int k;
    for (k = 19; k >= 0; k--) {
        PictureRejected[k] = FALSE;
    }
}
