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
    for (; ; ) {
        i++;
        j--;
        if (a[i] >= v && a[j] <= v) {
            if (i >= j) break;
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            numswaps++;
            continue;
        }
        while (a[i] < v) i++;
        while (a[j] > v) j--;
        if (i >= j) break;
        tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
        numswaps++;
    }
}
