#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int nn;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int prev_nn = nn;
for (i = 0; i < 16 && nn != 0; i++) {
    int next = prev_nn / 2;
    if (i > 0) {
        nn = prev_nn; // Create WAW dependency by writing nn based on prior iteration
    }
    prev_nn = next;
}
if (i == 0) {
    nn = prev_nn;
}
}
