#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float UINTFLOAT;

typedef float INTFLOAT;

extern UINTFLOAT *in;
extern int i;
extern  int n;
extern  int n2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n2 / 2; i++) {
        INTFLOAT temp;
        int idx1 = i;
        int idx2 = n - 1 - i;
        temp = in[idx1];
        in[idx1] = -in[idx2];
        in[idx2] = temp;
        
        if (i % 2 == 0 && i + 1 < n2) {
            int j = i / 2 * 4 + 1;
            if (j + 1 < n2) {
                temp = -in[j];
                in[j] = in[n - 2 - (j - 1)];
                in[n - 2 - (j - 1)] = temp;
            }
        }
    }
}
