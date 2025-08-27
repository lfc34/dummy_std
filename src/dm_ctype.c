#include "dm_ctype.h"

int 
dm_isalnum(int ch)
{
  // 6 checks? sounds unoptimized as hell
  if    (ch >= 48 && ch <= 57      // numerical
      || ch >= 65 && ch <= 90      // uppercase letter
      || ch >= 97 && ch <= 122)    // lowercase letter
  {
    return 1;
  } 
  else {
    return 0;
  }
}

int 
dm_isalpha(int ch)
{
  if (  ch >= 65 && ch <= 90
     || ch >= 97 && ch <= 122)
  {
    return 1;
  } 
  else {
    return 0;
  }
}