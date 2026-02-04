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
    Int32 next_zz;
    for (; weight[tmp] < weight[heap[zz >> 1]] && (zz > 1); ) {
        next_zz = zz >> 1;
        heap[zz] = heap[next_zz];
        zz = next_zz;
    }
    heap[zz] = tmp;
}
}
