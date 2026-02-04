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
    for (i = 0; i < 10; i++) {
        uint64_t base_id = 18446744073709551615UL;
        uint64_t offset = i * 2;
        ssl_ids[i * 2].id = base_id - offset;
        ssl_ids[i * 2 + 1].id = base_id - offset - 1;
    }
}
