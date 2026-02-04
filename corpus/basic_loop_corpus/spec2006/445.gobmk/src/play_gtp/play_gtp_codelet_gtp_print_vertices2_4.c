#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int *moves;
extern int movei[361];
extern int movej[361];
extern int k;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (k = 0; k < n; k++) {
    movei[k] = ((moves[k]) / (19 + 1) - 1);
    movej[k] = ((moves[k]) % (19 + 1) - 1);
}

}
