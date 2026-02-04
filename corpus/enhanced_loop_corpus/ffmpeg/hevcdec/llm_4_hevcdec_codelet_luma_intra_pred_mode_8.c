#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int intra_pred_mode;
extern int candidate[3];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 3; i++) {
    intra_pred_mode += (intra_pred_mode >= candidate[i]);
}
}
