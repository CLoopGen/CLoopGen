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
Int32 step = (alphaSize > 100) ? 1 : (alphaSize > 50) ? 2 : 3;
for (i = 1; i <= alphaSize; i++) {
    parent[i] = -1;
    nHeap++;
    heap[nHeap] = i;
    Int32 zz = nHeap;
    Int32 idx;
    for (idx = 0; idx < step && zz > 1; idx++) {
        Int32 parentIdx = zz >> 1;
        if (weight[heap[zz]] >= weight[heap[parentIdx]]) break;
        Int32 temp = heap[zz];
        heap[zz] = heap[parentIdx];
        heap[parentIdx] = temp;
        zz = parentIdx;
    }
}
}
