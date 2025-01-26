#ifndef TYPES_H
#define TYPES_H

#include <stdbool.h>
// ===================================
//
// Structures declaration
//
// ===================================

// -----------------------------------
// Color
// -----------------------------------

// tColor - Stucture for the object's color: 
// r (float) - red color, 
// g (float) - green color, 
// b (float) - blue color.
typedef struct Color {
  // Red color
  float r;
  // Green color
  float g;
  // Blue color
  float b;
} tColor;

// tObject - structure for the base object's parameters:
// X (float) - position on the X axis,
// Y (float) - position on the Y axis,
// color (tColor) - object's color,
// collision (bool) - object's collision.
typedef struct Object {
  // Position on the X axis
  float x;
  // Position on the Y axis
  float y;
  // Object's color
  tColor color;
  // Object's collision
  bool collision;
} tObject;

// ===================================
//
// Functions for structures
// 
// ===================================

// -----------------------------------
// tColor
// -----------------------------------

// Initialize object of tColor type.
void tColorInit(tColor* color);

// Set custom color for object of tColor type:
// color (tColor) - editable object
// r (float) - red color [0; 1]
// g (float) - green color [0; 1]
// b (float) - blue color [0; 1]
void tColorSetFloat(tColor* color, float r, float g, float b);

// Set custom color for object of tColor type:
// color (tColor) - editable object
// hex (char*)- hexadecimal code of the color [000000; FFFFFF]
void tColorSetHex(tColor* color, const char* hex);

// -----------------------------------
// tObject
// -----------------------------------

// Initialize object of tObject type.
void tObjectInit(tObject* obj);

// Set custom properties for object of tObject type:
// r (float) - reg color,
// g (float) - green color,
// b (float) - blue color,
// collis (bool) - collision of the object
void tObjectSetAll(tObject* obj, float r, float g, float b, bool collis);

// Set custom properties for object of tObject type:
// hex (char*) - hexadecimal value of the color (examples: FFFFFF, 000000, AAAAAA)
// collis (bool) - collision of the object
void tObjectSetHex(tObject* obj, char* hex, bool collis);
void tObjectSetTColor(tObject* obj, tColor color, bool collis);

void tObjectSetColorFloat(tObject* obj, float r, float g, float b);
void tObjectSetColorHex(tObject* obj, char* hex);
void tObjectSetColorTColor(tObject* obj, tColor color);

void tObjectSetCollision(tObject* obj, bool collis);

#endif // TYPES_H