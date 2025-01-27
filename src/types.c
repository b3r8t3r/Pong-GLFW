#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"



void tColorInit(tColor* color){
    color->r = 0;
    color->g = 0;
    color->b = 0;
}

void tColorSetFloat(tColor* color, float r, float g, float b) {
    color->r = (r < 0) ? 0 : (r > 1) ? 1 : r;
    color->g = (g < 0) ? 0 : (g > 1) ? 1 : g;
    color->b = (b < 0) ? 0 : (b > 1) ? 1 : b;
}

void tColorSetHex(tColor* color, const char* hex){
    if (strlen(hex) != 6) {
        fprintf(stderr, "Invalid input: hex string must be 6 characters long.");
        return;
    }
    
    // Convert each pair of hex characters to a float value in the range [0.0, 1.0]
    for (int i = 0; i < 3; ++i) {
        char byte_str[3] = {hex[2 * i], hex[2 * i + 1], '\0'};
      //printf("%s\n",byte_str);
        int byte_value = (int)strtol(byte_str, NULL, 16);
      //printf("%d\n", byte_value);
        switch (i) {
          case 0:
            color->r = (float)byte_value / 255.0f;
            break;
          case 1:
            color->g = (float)byte_value / 255.0f;
            break;
          case 2:
            color->b = (float)byte_value / 255.0f;
            break;
        }
        
    }
}