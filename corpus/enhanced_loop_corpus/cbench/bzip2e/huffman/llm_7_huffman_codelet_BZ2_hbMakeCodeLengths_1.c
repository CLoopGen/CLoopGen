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

#pragma unroll
for (i = 1; i <= alphaSize; i++) {
    parent[i] = -1;
    local_nHeap++;
    heap[local_nHeap] = i;

    Int32 zz = local_nHeap;
    Int32 tmp = heap[zz];
    Int32 p_index;

    for (p_index = zz >> 1; 
         zz > 1 && weight[tmp] < weight[heap[p_index]]; 
         p_index = zz >> 1) {
        heap[zz] = heap[p_index];
        zz = p_index;
    }

    heap[zz] = tmp;
}

nHeap = local_nHeap;
}
