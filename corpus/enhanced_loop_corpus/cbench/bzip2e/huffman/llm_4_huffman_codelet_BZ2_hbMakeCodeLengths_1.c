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
    if (i > 0) {
        parent[i] = -1;
        nHeap++;
        heap[nHeap] = i;
        {
            Int32 zz, tmp;
            zz = nHeap;
            tmp = heap[zz];
            if (!(weight[tmp] < weight[heap[zz >> 1]])) {
                heap[zz] = tmp;
            } else {
                do {
                    heap[zz] = heap[zz >> 1];
                    zz >>= 1;
                } while (zz > 1 && weight[tmp] < weight[heap[zz >> 1]]);
                heap[zz] = tmp;
            }
        }
    }
}
}
