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
for (i = 1; i <= alphaSize; i++) {
    parent[i] = -1;
    nHeap++;
    heap[nHeap] = i;

    Int32 zz = nHeap;
    Int32 tmp = heap[zz];

    if (zz == 1) {
        heap[zz] = tmp;
        continue;
    }

    Int32 p = zz >> 1;
    if (weight[tmp] >= weight[heap[p]]) {
        heap[zz] = tmp;
        continue;
    }

    while (1) {
        heap[zz] = heap[p];
        zz = p;
        if (zz == 1) break;
        p = zz >> 1;
        if (weight[tmp] >= weight[heap[p]]) break;
    }
    heap[zz] = tmp;
}
}
