#include <stdio.h>

#include <inttypes.h>

typedef struct ssl_st SSL;

struct ssl_id {
    SSL *s;
    uint64_t id;
    int status;
};


extern uint64_t id;
extern SSL *ssl;
extern int status;
extern struct ssl_id *ssl_ids;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2, then handle remainder)
    int n = 20;
    int stride = 2;

    // First pass: strided access
    for (i = 0; i < n; i += stride) {
        if (ssl_ids[i].s == ((void *)0)) {
            ssl_ids[i].s = ssl;
            ssl_ids[i].id = id;
            ssl_ids[i].status = status;
            return;
        }
    }

    // Second pass: check odd indices if stride skipped any
    for (i = 1; i < n; i += stride) {
        if (ssl_ids[i].s == ((void *)0)) {
            ssl_ids[i].s = ssl;
            ssl_ids[i].id = id;
            ssl_ids[i].status = status;
            return;
        }
    }
}
