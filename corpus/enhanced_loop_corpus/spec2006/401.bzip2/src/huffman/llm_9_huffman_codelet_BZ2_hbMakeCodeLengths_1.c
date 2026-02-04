#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 alphaSize;
extern Int32 nHeap;
extern Int32 i;
extern Int32 heap[260];
extern Int32 weight[516];
extern Int32 parent[516];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
Int32 step = (alphaSize > 100) ? 1 : 2;
for (i = 1; i <= alphaSize; i++) {
    parent[i] = -1;
    nHeap++;
    heap[nHeap] = i;

    Int32 zz = nHeap;
    Int32 tmp = heap[zz];

    for (Int32 shift = 1; (zz >> shift) >= 1 && weight[tmp] < weight[heap[zz >> shift]]; shift++) {
        heap[zz] = heap[zz >> shift];
        zz = zz >> shift;
        shift--; 
    }

    heap[zz] = tmp;

    if (step == 2 && i % 5 == 0) {
        for (Int32 j = 1; j <= nHeap / 2; j++) {
            Int32 idx = j << 1;
            if (idx <= nHeap && weight[heap[j]] > weight[heap[idx]]) {
                Int32 temp = heap[j];
                heap[j] = heap[idx];
                heap[idx] = temp;
            }
        }
    }
}
}
