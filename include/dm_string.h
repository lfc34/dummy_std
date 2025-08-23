/* Reimplementation of C <string.h> */

// this shit costed me virginity
#ifndef DM_STRING_H
#define DM_STRING_H

/* POSIX NULL definition is 0 casted to void pointer */
#define NULL ((void*)0)

typedef unsigned long dm_size_t;

/* copy SRC to DEST */
char*
dm_strcpy(char* dest, const char* src);

/* copy no more than COUNT characters of SRC to DEST */
char*
dm_strncpy(char* dest, const char* src, dm_size_t count);

/* append SRC to DEST */
char*
dm_strcat(char* dest, const char* src);

/* append no more than COUNT characters of SRC to DEST */
char*
dm_strncat(char* dest, const char* src, dm_size_t count);

/* Lets not touch locale yet */
// void
// dm_strxfrm(char* dest, const char* src, dm_size_t count);
// dm_strcoll(const char* lhs, const char* rhs);

/* TODO: IMPLEMENT DM_MALLOC TO PERFORM THIS OPERATION */
// char*
// dm_strdup(const char* src);
// char*
// dm_strndup(const char* src);

/* return the length of s */
dm_size_t
dm_strlen(const char* s);

/* compare two strings, return 0 if equal */
int
dm_strcmp(const char* lhs, const char* rhs);

/* compare two strings, return 0 if equal */
int
dm_striseq(const char* s1, const char* s2);

/* compare no more than COUNT characters in two strings */
int
dm_strncmp(const char* lhs, const char* rhs, dm_size_t count);

/* return pointer to first occurence of CH in S */
char*
dm_strchr(const char* s, int ch);

/* return pointer to last occurence of CH in S */
char*
dm_strrchr(const char* s, int ch);

/* return the length of initial segment of DEST,
   which consists entirely of characters found in SRC */
dm_size_t
dm_strspn(const char* dest, const char* src);

/* return the length of initial segment of DEST, 
   which consists entirely of characters NOT found in SRC */
dm_size_t
dm_strcspn(const char* dest, const char* src);

/* returns a pointer to first occurence of any character from BREAKSET
   in DEST. Returns NULL in case BREASKET characters not found in DEST */
char*
dm_strpbrk(const char* dest, const char* breakset);

/* returns pointer to the start of SUBSTR in STR */
char*
dm_strstr(const char* str, const char* substr);

/* separate STR into tokens, separated by DELIM,
   returns a pointer to the next token */
char*
dm_strtok(char* str, const char* delim);

/* return pointer to first occurence of CH in PTR, 
   scan no more characters than COUNT */
void*
dm_memchr(const void* ptr, int ch, dm_size_t count);

/* compare no more than COUNT bytes in two objects,
   return 0 if objects equal */
int
dm_memcmp(const void* lhs, const void* rhs, dm_size_t count);

/* set COUNT bytes of CH to DEST */
void*
dm_memset(void* dest, int ch, dm_size_t count);

/* copy COUNT bytes of SRC to DEST */
void*
dm_memcpy(void* dest, const void* src, dm_size_t count);

/* copy COUNT bytes of SRC to DEST,
   correct behaviour guaranteed for overlapping memory */
void*
dm_memmove(void* dest, const void* src, dm_size_t count);

#endif