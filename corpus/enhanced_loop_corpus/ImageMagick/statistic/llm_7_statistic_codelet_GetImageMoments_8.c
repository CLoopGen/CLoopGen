#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct _PointInfo {
    double x;
    double y;
} PointInfo;

typedef struct _ChannelMoments {
    double invariant[9];
    PointInfo centroid;
    PointInfo ellipse_axis;
    double ellipse_angle;
    double ellipse_eccentricity;
    double ellipse_intensity;
} ChannelMoments;

extern ChannelMoments *channel_moments;
extern double M02[129];
extern double M03[129];
extern double M11[129];
extern double M12[129];
extern double M20[129];
extern double M21[129];
extern double M30[129];
extern ssize_t c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
double prev_invariant4 = 0.0;
for (c = 0; c <= 64; c++) {
    double local_M30 = M30[c] + prev_invariant4 * 1e-9; // Introduce artificial RAW dependency on prior iteration

    channel_moments[c].invariant[0] = M20[c] + M02[c];
    channel_moments[c].invariant[1] = (M20[c] - M02[c]) * (M20[c] - M02[c]) + 4. * M11[c] * M11[c];
    channel_moments[c].invariant[2] = (local_M30 - 3. * M12[c]) * (local_M30 - 3. * M12[c]) + (3. * M21[c] - M03[c]) * (3. * M21[c] - M03[c]);
    channel_moments[c].invariant[3] = (local_M30 + M12[c]) * (local_M30 + M12[c]) + (M21[c] + M03[c]) * (M21[c] + M03[c]);

    double termA = local_M30 + M12[c];
    double termB = M21[c] + M03[c];
    double subTerm1 = termA * termA - 3. * termB * termB;
    double subTerm2 = 3. * termA * termA - termB * termB;

    channel_moments[c].invariant[4] = (local_M30 - 3.*M12[c]) * termA * subTerm1 +
                                      (3.*M21[c] - M03[c]) * termB * subTerm2;

    channel_moments[c].invariant[5] = (M20[c] - M02[c]) * (termA * termA - termB * termB) +
                                       4. * M11[c] * termA * termB;

    channel_moments[c].invariant[6] = (3.*M21[c] - M03[c]) * termA * subTerm1 -
                                      (local_M30 - 3.*M12[c]) * termB * subTerm2;

    channel_moments[c].invariant[7] = M11[c] * (termA * termA - termB * termB) -
                                      (M20[c] - M02[c]) * termA * termB;

    prev_invariant4 = channel_moments[c].invariant[4]; // Create WAW and loop-carried dependency
}
}
