#include <stdio.h>

#include <inttypes.h>

typedef struct ssl_st SSL;

struct ssl_id {
    SSL *s;
    uint64_t id;
    int status;
};


extern struct ssl_id *ssl_ids;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t prev_id = 1000;
    for (i = 0; i < 20; i++) {
        if (i == 0) {
            ssl_ids[i].id = prev_id;
        } else {
            ssl_ids[i].id = ssl_ids[i-1].id * 2 + 1;
        }
    }
}
