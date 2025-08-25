/* Reimplementation of C <assert.h> */
/* ONLY AVAILABLE IN OS WITH UNISTD.H (UNIX-LIKE) */

#ifndef DM_ASSERT_H
#define DM_ASSERT_H

#ifndef NDEBUG
void dm_assert(int exp);
#endif

#endif