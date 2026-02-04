#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

OSSL_PQUEUE *pq;
size_t from;
struct pq_elem_st *e;
size_t i;

void init_vars() {
    const size_t data_size = 131072; // ~128KB of data

    e = (struct pq_elem_st *)calloc(data_size, sizeof(struct pq_elem_st));
    if (!e) exit(1);

    pq = (OSSL_PQUEUE *)malloc(sizeof(OSSL_PQUEUE));
    if (!pq) exit(1);

    pq->heap = (struct pq_heap_st *)malloc(sizeof(struct pq_heap_st));
    if (!pq->heap) exit(1);
    pq->heap->data = NULL;
    pq->heap->index = 0;

    pq->elements = e;
    pq->compare = NULL;
    pq->htop = 0;
    pq->hmax = data_size;
    pq->freelist = 0;

    from = 1;
}