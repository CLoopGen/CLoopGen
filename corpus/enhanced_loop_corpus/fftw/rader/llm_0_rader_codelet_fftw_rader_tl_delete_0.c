#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double R;

typedef ptrdiff_t INT;

typedef struct rader_tls rader_tl;

struct rader_tls {
    INT k1;
    INT k2;
    INT k3;
    R *W;
    int refcnt;
    rader_tl *cdr;
};


extern R *W;
extern rader_tl **tl;
extern rader_tl **tp;
extern rader_tl *t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (tp = tl; (t = *tp) && t->W != W; tp = &t->cdr) {
        for (INT i = 0; i < 1; ++i) {  // Artificially increased loop depth by nesting a single-iteration loop
            // Body intentionally empty — used to increase nesting depth without altering logic
        }
    }
}
