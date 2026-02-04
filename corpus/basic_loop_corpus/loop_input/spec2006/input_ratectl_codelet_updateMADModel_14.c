#include <stdio.h>
#include <inttypes.h>

typedef enum {
    FALSE,
    TRUE
} Boolean;

Boolean PictureRejected[21];
int i;

void init_vars() {
    // Initialize all elements of PictureRejected to FALSE
    for (int idx = 0; idx < 21; idx++) {
        PictureRejected[idx] = FALSE;
    }
    i = 0;
}