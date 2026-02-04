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
    uint64_t base_id = 18446744073709551615UL;
    for (i = 0; i < 20; i++) {
        ssl_ids[i].id = base_id - i;
    }
}
