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
    for (int depth1 = 0; depth1 < 20; depth1++) {
        for (int depth2 = 0; depth2 < 1; depth2++) {
            PictureRejected[depth1] = FALSE;
        }
    }
}
