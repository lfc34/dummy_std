#include "dm_string.h"

char*
dm_strcpy(char* dest, const char* src)
{
  while ((*dest++ = *src++));
  return dest;
}

char*
dm_strncpy(char* dest, const char* src, dm_size_t count)
{
  while (count--) {
    *dest++ = *src++;
  }
  return dest;
}

char*
dm_strcat(char* dest, const char* src)
{
  while (*dest) {
    ++dest; // Move to the end of the string
  }
  while (*src) {
    *dest++ = *src++;
  }
  *dest = '\0'; // terminate the string
  return dest;
}

char*
dm_strncat(char* dest, const char* src, dm_size_t count)
{
  while (*dest) {
    ++dest; // Move to the end of the string
  }
  while (count--) {
    *dest++ = *src++;
  }
  *dest = '\0';
  return dest;
}

dm_size_t
dm_strlen(const char* s)
{
  dm_size_t length = 0;
  while (*s++ != '\0')
    ++length;
  return length;
}

// This imitates the original strcmp, comparing two strings lexiographically
// (whatever that means), so it's kinda bloated and unecessary
int
dm_strcmp(const char* lhs, const char* rhs)
{
  int lhs_sum = 0, rhs_sum = 0;
  while (*lhs++ != '\0') {
    lhs_sum += *lhs;
  }
  while (*rhs++ != '\0') {
    rhs_sum += *rhs;
  }
  return lhs_sum - rhs_sum;
}

// less bloated way of strcmp
// because most people just need to know are strings equal or not
int
dm_striseq(const char* s1, const char* s2)
{
  while (*s1 != '\0' && *s2 != '\0') {
    if (*s1++ != *s2++)
      return 1;
    else
      return 0;
  }

  // in case s1 or s2 are either terminated early or some voodoo happens
  return -1;
}

int
dm_strncmp(const char* lhs, const char* rhs, dm_size_t count)
{
  int lhs_sum = 0, rhs_sum = 0;
  for (int i = count; i > 0; i--) {
    lhs_sum += *lhs++;
    rhs_sum += *rhs++;
  }
  return lhs_sum - rhs_sum;
}

char*
dm_strchr(const char* s, int ch)
{
  while (*s++) {
    if (*s == ch)
      return (char*)s;
  }
  return NULL;
}

char*
dm_strrchr(const char* s, int ch)
{
  char* last;
  while (*s++) {
    if (*s == ch)
      last = (char*)s;
  }
  return last;
}

dm_size_t
dm_strspn(const char* dest, const char* src)
{
  if (src[0] == '\0')
    return 0;

  dm_size_t len = 0;

  // let's create a set
  char set[128] = { 0 }; // for each printable ASCII char
  while (*src) {
    set[(int)*src] = 1; // mark character as existing
    src++;
  }

  while (*dest) {
    if (set[(int)*dest]) {
      ++len;
    } else {
      break;
    }
    ++dest;
  }

  return len;
}

dm_size_t
dm_strcspn(const char* dest, const char* src)
{
  if (src[0] == '\0')
    return 0;

  dm_size_t len = 0;

  // let's create a set
  char set[128] = { 0 }; // for each printable ASCII char
  while (*src) {
    set[(int)*src] = 1; // mark character as existing
    src++;
  }

  while (*dest) {
    if (set[(int)*dest]) {
      break;
    }
    ++len;
    ++dest;
  }

  return len;
}

char*
dm_strpbrk(const char* dest, const char* breakset)
{
  // basically: if this string doesn't contain any break chars,
  // dm_strcspn will return the length of whole string,
  // and pointer will jump to '\0' which is FALSE
  dest += dm_strcspn(dest, breakset);
  return *dest ? (char*)dest : NULL;
}

char*
dm_strstr(const char* str, const char* substr)
{
  // find the first char from substr in str
  str = dm_strchr(str, substr[0]);

  // compare the remaining of str with substr, if not eq jump to the next char
  while (dm_strncmp(str, substr, dm_strlen(substr)) != 0) {
    str++;
  }

  return *str ? (char*)str : NULL;
}

char*
dm_strtok(char* str, const char* delim)
{
  // not thread safe
  static char* save_ptr;
  char* end_of_token;

  if (str == NULL) {
    str = save_ptr;
  }

  if (*str == '\0') {
    save_ptr = str;
    return NULL;
  }

  // skip first delimeters
  str += dm_strspn(str, delim);
  if (*str == '\0') {
    save_ptr = str;
    return NULL;
  }
  // move to the first delimeter after token
  end_of_token = str + dm_strcspn(str, delim);
  if (*end_of_token == '\0') {
    save_ptr = end_of_token;
    return str;
  }

  // terminate the token and make save ptr past it
  *end_of_token = '\0';
  save_ptr = end_of_token + 1;

  return save_ptr;
}

void*
dm_memchr(const void* ptr, int ch, dm_size_t count)
{
  while (count--) {
    if (*(unsigned char*)ptr == ch)
      return (void*)ptr;
  }
  return NULL;
}

int
dm_memcmp(const void* lhs, const void* rhs, dm_size_t count)
{
  int lhs_sum = 0, rhs_sum = 0;

  while (count--) {
    if (*(unsigned char*)lhs++)
      lhs_sum += *(unsigned char*)lhs;
    if (*(unsigned char*)rhs++)
      rhs_sum += *(unsigned char*)rhs;
  }
  return lhs_sum - rhs_sum;
}

void*
dm_memset(void* dest, int ch, dm_size_t count)
{
  unsigned char* p = (unsigned char*)dest;
  while (count--) {
    *p++ = (unsigned char)ch;
  }
  return dest;
}

void*
dm_memcpy(void* dest, const void* src, dm_size_t count)
{
  unsigned char* pDest = (unsigned char*)dest;
  const unsigned char* pSrc = (const unsigned char*)src;
  while (count--) {
    *pDest++ = *pSrc++;
  }
  return dest;
}

void*
dm_memmove(void* dest, const void* src, dm_size_t count)
{
  unsigned char* pDest = (void*)dest;
  const unsigned char* pSrc = (const void*)src;
  // check for overlap
  if (pDest < pSrc) {
    dm_memcpy(pDest, pSrc, count);
  } else {
    for (dm_size_t i = count; i > 0; i--) {
      pDest[i - 1] = pSrc[i - 1];
    }
  }

  return dest;
}