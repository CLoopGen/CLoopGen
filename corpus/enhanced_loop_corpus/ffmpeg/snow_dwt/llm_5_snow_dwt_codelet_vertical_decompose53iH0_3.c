#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int DWTELEM;

extern DWTELEM *b0;
extern DWTELEM *b1;
extern DWTELEM *b2;
extern int width;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < width; i++) {
        int sum = b0[i] + b2[i];
        if (sum % 2 == 0) {
            b1[i] -= sum >> 1;
        } else {
            b1[i] -= (sum + 1) >> 1;
        }
    }
}
