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
    for (int outer = 0; outer < 10; outer++) {
        for (int inner = 0; inner < 2; inner++) {
            int index = outer * 2 + inner;
            PictureRejected[index] = FALSE;
        }
    }
}
