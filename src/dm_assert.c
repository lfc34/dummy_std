#include <signal.h>
#include <unistd.h> /* for writing to stderr in case of failure */

#include "dm_assert.h"

void 
dm_assert(int exp)
{
  if (exp == 0) {
    write(2, "\nAssertion failed\n",  sizeof("\nAssertion failed\n") - 1);
    raise(SIGABRT);
  }
}
