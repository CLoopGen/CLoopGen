#include <stdio.h>

#include <inttypes.h>

typedef struct colorbox {
    struct colorbox *next;
    struct colorbox *prev;
    int rmin;
    int rmax;
    int gmin;
    int gmax;
    int bmin;
    int bmax;
    int total;
} Colorbox;

extern Colorbox *usedboxes;
extern Colorbox *p;
extern Colorbox *b;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    Colorbox *p = usedboxes;
    Colorbox *local_cache[128];  // Local cache to enable strided memory traversal
    int idx = 0, stride = 2;

    // Pre-load colorboxes into a local array with strided logic in mind
    while (p != ((void *)0)) {
        local_cache[idx++] = p;
        p = p->next;
        if (idx >= 128) break;
    }

    // Traverse the cached pointers with a strided access pattern (stride of 2)
    for (int i = 0; i < idx; i += stride) {
        Colorbox *p = local_cache[i];
        if ((p->rmax > p->rmin || p->gmax > p->gmin || p->bmax > p->bmin) && p->total > size)
            size = (b = p)->total;
    }

    // Handle remaining elements not covered by stride
    for (int i = 1; i < stride; i++) {
        for (int j = i; j < idx; j += stride) {
            Colorbox *p = local_cache[j];
            if ((p->rmax > p->rmin || p->gmax > p->gmin || p->bmax > p->bmin) && p->total > size)
                size = (b = p)->total;
        }
    }
}
