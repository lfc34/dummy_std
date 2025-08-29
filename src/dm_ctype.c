#include "dm_ctype.h"

int 
dm_isalnum(int ch)
{
  return   dm_isdigit(ch) 
        || dm_isupper(ch)
        || dm_islower(ch); 
}

int 
dm_isalpha(int ch)
{
  return   dm_islower(ch)
        || dm_isupper(ch);
}

int
dm_isblank(int ch)
{
  return (ch == ' ' || ch == '\t');
}

int 
dm_iscntrl(int ch) 
{
  return (ch >= 0 && ch <= 31) || ch == 0x7f;
}

int 
dm_isdigit(int ch)
{
  return (ch >= 48 && ch <= 57);
}

int
dm_isprint(int ch)
{
  return (ch >= 32 && ch <= 127);
}

int 
dm_isgraph(int ch) 
{
  return (dm_isprint(ch) && ch != ' ');
}

int 
dm_islower(int ch)
{
  return (ch >= 97 && ch <= 122);
}

int 
dm_ispunct(int ch)
{
  return   (ch >= 33 && ch <= 47)
        || (ch >= 0x3a && ch <= 0x40)
        || (ch >= 0x5b && ch <= 0x60);
}

int 
dm_isspace(int ch)
{
  return   (ch >= 9 && ch <= 13) 
        || (ch == ' ');
}

int 
dm_isupper(int ch) 
{
  return (ch >= 65 && ch <= 90);
}

int 
dm_isxdigit(int ch)
{
  return   dm_isdigit(ch) 
        || (ch >= 65 && ch <= 70)
        || (ch >= 97 && ch <= 102);
}

int 
dm_tolower(int ch)
{
  return dm_isupper(ch) ? (ch + 32) : ch;
}

int 
dm_toupper(int ch)
{
  return dm_islower(ch) ? (ch - 32) : ch;
}