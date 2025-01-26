#ifndef TEXT_H
#define TEXT_H
#include "types.h"

typedef struct charStruct
{
  char character;
  tObject param;
} tChar;

void tCharInit(tChar* character);

void tCharSet(tChar* character, char ch);

void tCharDraw(tChar* character, float x, float y);

void tCharMove(tChar* character, float x, float y);

#endif // TEXT_H