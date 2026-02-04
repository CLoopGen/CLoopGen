#include <stdio.h>

#include <inttypes.h>

typedef enum {
    FALSE,
    TRUE
} Boolean;

extern Boolean PictureRejected[21];
extern int n_windowSize;
extern int n_realSize;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_size = n_realSize;
    for (i = 0; i < n_windowSize; i++) {
        if (PictureRejected[i])
            temp_size--;
    }
    n_realSize = temp_size;
}
