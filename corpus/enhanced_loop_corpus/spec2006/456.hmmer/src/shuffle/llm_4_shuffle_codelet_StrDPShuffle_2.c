#include <stdio.h>

#include <inttypes.h>

extern int x;
extern int *nE;
extern char sf;
extern char Z[26];
extern int is_eulerian;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < 26; x++) {
        if (nE[x] != 0 && x != sf) {
            if (Z[x] == 0) {
                is_eulerian = 0;
                return;
            }
        }
    }
}
