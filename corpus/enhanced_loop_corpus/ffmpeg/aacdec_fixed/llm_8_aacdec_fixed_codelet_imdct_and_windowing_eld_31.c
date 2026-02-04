#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned int UINTFLOAT;

typedef int INTFLOAT;

extern UINTFLOAT *in;
extern int i;
extern  int n;
extern  int n2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n2; i += 4) {
        INTFLOAT temp1, temp2;
        int idx1 = i;
        int idx2 = n - 1 - i;
        int idx3 = i + 1;
        int idx4 = n - 2 - i;

        if (idx1 < idx2) {
            temp1 = in[idx1];
            in[idx1] = -in[idx2];
            in[idx2] = temp1;
        }

        if (idx3 < idx4 && (i + 1) < n2) {
            temp2 = in[idx3];
            in[idx3] = -in[idx4];
            in[idx4] = temp2;
        }

        if (i + 2 < n2) {
            int j = i + 2;
            int k = n - 3 - i;
            if (j < k) {
                temp1 = in[j];
                in[j] = -in[k];
                in[k] = temp1;
            }
        }

        if (i + 3 < n2) {
            int j = i + 3;
            int k = n - 4 - i;
            if (j < k) {
                temp1 = in[j];
                in[j] = -in[k];
                in[k] = temp1;
            }
        }
    }
}
