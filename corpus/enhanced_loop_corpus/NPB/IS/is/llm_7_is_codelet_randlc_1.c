#include <stdio.h>

extern  double R46;
extern  double T46;
extern int i;



void loop(){
double local_R = R46;
double local_T = T46;
for (i = 1; i <= 46; i++) {
    local_R = 0.5 * local_R;
    local_T = 2.0 * local_T;
}
R46 = local_R; // Remove loop-carried dependencies by using local variables
T46 = local_T; // Eliminate all intra-loop WAW and WAR hazards
}
