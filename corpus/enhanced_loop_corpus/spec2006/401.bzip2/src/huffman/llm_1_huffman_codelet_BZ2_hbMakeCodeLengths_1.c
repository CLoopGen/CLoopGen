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
    for (Int32 step = zz >> 1; step >= 1 && weight[tmp] < weight[heap[step]]; step >>= 1) {
        heap[zz] = heap[step];
        zz = step;
    }
    heap[zz] = tmp;
}
}
