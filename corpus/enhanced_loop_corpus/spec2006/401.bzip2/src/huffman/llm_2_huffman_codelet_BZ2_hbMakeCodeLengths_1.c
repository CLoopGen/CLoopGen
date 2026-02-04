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



void loop() {
    for (i = 1; i <= alphaSize; i++) {
        parent[i] = -1;
        nHeap++;
        heap[nHeap] = i;

        // Variant 1: Use strided memory access pattern with unrolled steps and indirect indexing
        Int32 idx = nHeap;
        Int32 current_weight = weight[heap[idx]];
        Int32 pos = idx;
        for (; pos > 1 && current_weight < weight[heap[pos / 2]]; ) {
            heap[pos] = heap[pos / 2];
            pos /= 2;
        }
        heap[pos] = heap[nHeap];
    }
}
