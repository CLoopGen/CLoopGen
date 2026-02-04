#include <stdio.h>

#include <inttypes.h>

struct pq_heap_st {
    void *data;
    size_t index;
};


struct pq_elem_st {
    size_t posn;
};


struct ossl_pqueue_st {
    struct pq_heap_st *heap;
    struct pq_elem_st *elements;
    int (*compare)(const void *, const void *);
    size_t htop;
    size_t hmax;
    size_t freelist;
};


typedef struct ossl_pqueue_st OSSL_PQUEUE;

extern OSSL_PQUEUE *pq;
extern size_t from;
extern struct pq_elem_st *e;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access (step by 2) forward traversal
    for (i = from + 1; i < pq->hmax; i += 2) {
        e[i].posn = i - 1;
        if (i + 1 < pq->hmax)
            e[i + 1].posn = i;
    }
}
