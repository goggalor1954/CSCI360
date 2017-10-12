/*
Code for 64 bit LFSR
Hunter Johnson
9/15/17

modified by: James Roesemann
10/12/17
this program is a modification of lfsr.c for the purpose of developing the missing functions of that program.
*/

/*
to do:
read_lfsr
next_state
get_128_keystream
shape_keystream
*/


#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/*The following struct will represent an LFSR with a 64 bit state.
  The taps are represented by a 64 bit number, where the ith bit (from the right)
  corresponds to p_i (in the notation of the textbook).
  The uint64_t is a 64 bit unsigned integer.
  There is a small chance that this code may behave unexpectedly if compiled on Windows or Mac.
  Please let me know if you get issues.
  It compiles and runs under clang and gcc. */
typedef struct {
	uint64_t state;
	uint64_t taps;
} LFSR;

int main()
{

}
