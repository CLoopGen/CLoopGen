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
    for (int outer = 0; outer < n2; outer += 4) {
        for (i = outer; i < outer + 2 && i < n2; i += 2) {
            INTFLOAT temp;
            temp = in[i];
            in[i] = -in[n - 1 - i];
            in[n - 1 - i] = temp;
            if (i + 1 < n2) {
                temp = -in[i + 1];
                in[i + 1] = in[n - 2 - i];
                in[n - 2 - i] = temp;
            }
        }
    }
}
