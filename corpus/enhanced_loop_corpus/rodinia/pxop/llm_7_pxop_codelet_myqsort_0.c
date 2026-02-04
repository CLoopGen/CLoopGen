#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *a;
extern int i;
extern int j;
extern int tmp;
extern int v;
extern int numswaps;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_i = i + 1;
    int local_j = j - 1;
    int swapped = 0;

    for (; ; ) {
        if (swapped) {
            local_i = i + 1;
            local_j = j - 1;
            swapped = 0;
        }

        if (a[local_i] >= v && a[local_j] <= v) {
            if (local_i >= local_j) {
                i = local_i;
                j = local_j;
                break;
            }
            tmp = a[local_i];
            a[local_i] = a[local_j];
            a[local_j] = tmp;
            numswaps++;
            i = local_i;
            j = local_j;
            swapped = 1;
        } else {
            if (a[local_i] < v) local_i++;
            if (a[local_j] > v) local_j--;
        }

        if (local_i >= j || local_j <= i) {
            i = local_i;
            j = local_j;
            break;
        }
    }
}
