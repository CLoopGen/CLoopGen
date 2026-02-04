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
Int32 local_nHeap = nHeap;
for (i = 1; i <= alphaSize; i++) {
    parent[i] = -1;
    local_nHeap++;
    heap[local_nHeap] = i;
    Int32 zz = local_nHeap;
    while (zz > 1 && weight[heap[zz]] < weight[heap[zz >> 1]]) {
        Int32 temp = heap[zz];
        heap[zz] = heap[zz >> 1];
        heap[zz >> 1] = temp;
        zz >>= 1;
    }
}
nHeap = local_nHeap;
}
