#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double x;
extern double p;
extern double q;
extern ssize_t i;
extern  double Pone[];
extern  double Qone[];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double s = p, t = q;
    for (i = 4; i >= 0; i--) {
        double factor = (8. / x) * (8. / x);
        double p_prev = s;
        double q_prev = t;
        s = p_prev * factor + Pone[i];
        t = q_prev * factor + Qone[i];
        p = (i == 0) ? s : p; // Write to p only on last iteration (WAW dependency reduced)
        q = (i == 0) ? t : q; // Write to q only on last iteration
    }
}
