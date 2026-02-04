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
for (i = 1; i <= alphaSize; i += 2) {
    parent[i] = -1;
    nHeap++;
    heap[nHeap] = i;
    if (i + 1 <= alphaSize) {
        parent[i + 1] = -1;
        nHeap++;
        heap[nHeap] = i + 1;
    }
    for (Int32 zz = nHeap, tmp = heap[zz]; zz > 1 && weight[tmp] < weight[heap[zz >> 1]]; ) {
        heap[zz] = heap[zz >> 1];
        zz >>= 1;
        if (zz <= 1 || weight[tmp] >= weight[heap[zz >> 1]]) {
            heap[zz] = tmp;
            break;
        }
        if (zz == 2) {
            heap[zz] = tmp;
            break;
        }
    }
    if (nHeap > 1 && (nHeap & 1) == 0 && weight[heap[nHeap]] < weight[heap[nHeap >> 1]]) {
        Int32 temp = heap[nHeap];
        heap[nHeap] = heap[nHeap >> 1];
        heap[nHeap >> 1] = temp;
    }
}
}
