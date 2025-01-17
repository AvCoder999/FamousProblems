#include <cstdio>
#include <cmath>
#include <cstring>
#include <unistd.h>

int 
main()
{
    float A = 0, B = 0;  // Rotation angles
    float i, j;          // Loop counters
    int k;               // Frame character index
    char output[1760];   // Output buffer
    float zbuffer[1760]; // Depth buffer
    printf("\x1b[2J");   // Clear the screen

    while (1) {
        memset(output, ' ', 1760);      // Fill output with spaces
        memset(zbuffer, 0, 1760 * 4);  // Initialize depth buffer

        for (j = 0; j < 6.28; j += 0.07) {
            for (i = 0; i < 6.28; i += 0.02) {
                float c = sin(i), d = cos(j), e = sin(A), f = sin(j),
                      g = cos(A), h = d + 2, D = 1 / (c * h * e + f * g + 5);
                float l = cos(i), m = cos(B), n = sin(B),
                      t = c * h * g - f * e;
                int x = 40 + 30 * D * (l * h * m - t * n);
                int y = 12 + 15 * D * (l * h * n + t * m);
                int o = x + 80 * y;
                int N =
                    8 * ((f * e - c * d * g) * m - c * d * e - f * g - l * d * n);
                if (1760 > o && o > 0 && D > zbuffer[o]) {
                    zbuffer[o] = D;
                    output[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
                }
            }
        }

        printf("\x1b[H"); // Move cursor to home position
        for (k = 0; k < 1760; k++) {
            putchar(k % 80 ? output[k] : '\n');
        }

        A += 0.04; // Increment rotation angles
        B += 0.02;
        usleep(30000); // Pause for smooth animation
    }

    return 0;
}



