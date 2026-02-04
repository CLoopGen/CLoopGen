#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern int delta[8];
extern Intersection board[421];
extern int k;
extern int dpos;
extern char mn[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_mn[400]; // Local copy to eliminate write-after-write (WAW) dependency on global mn
    for (int i = 0; i < 400; i++) {
        temp_mn[i] = mn[i];
    }
    for (dpos = (19 + 2); dpos < (19 + 1) * (19 + 1); dpos++) {
        if ((board[dpos] != 3) && temp_mn[dpos] == 1) {
            for (k = 0; k < 4; k++) {
                int neighbor = dpos + delta[k];
                if ((board[neighbor] != 3) && !temp_mn[neighbor]) {
                    temp_mn[neighbor] = 2;
                }
            }
        }
    }
    // Write back to global mn to preserve semantics
    for (int i = 0; i < 400; i++) {
        mn[i] = temp_mn[i];
    }
}
