/* Reimplementation of C <ctype.h> */
/* only works with default "C" locale */

#ifndef DM_CTYPE_H
#define DM_CTYPE_H

/* checks if character is alphanumerical */
int
dm_isalnum(int ch);

/* checks if character is alphabetic */
int
dm_isalpha(int ch);

/* checks if character is blank */
int
dm_isblank(int ch);

/* check if character is a control character */
int 
dm_iscntrl(int ch);

/* checks if character is digit */
int 
dm_isdigit(int ch);

/* checks if character is printable */
int 
dm_isprint(int ch);

/* checks if character has graphical representation */
int 
dm_isgraph(int ch);

/* checks if character is lowercase letter */
int 
dm_islower(int ch);

/* checks if character is punctuation character */
int  
dm_ispunct(int ch);

/* checks if character is a white space */
int 
dm_isspace(int ch);

/* checks if character is uppercase letter */
int
dm_isupper(int ch);

/* checks if character is hexadecimal digit */
int 
dm_isxdigit(int ch);

/* converts uppercase letter into lowercase */
int 
dm_tolower(int ch);

/* converts lowercase letter into upper case */
int 
dm_toupper(int ch);

#endif