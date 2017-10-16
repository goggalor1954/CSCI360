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
read_lfsr 			done
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

void init_LFSR(LFSR* L, uint64_t initial_state, uint64_t taps)
{
/*Initialize with state and taps*/
	L->state = initial_state;
	L->taps = taps;
}
int parity(uint64_t N)
{
/* Return the parity of N*/
	int p = __builtin_parity(N); // parity of first 32 bits
	N = __builtin_bswap64(N); //move back 32 to the front
	return (p+__builtin_parity(N))%2; //overall parity
}



//everyhting below is something i had to modify. everything above came with the program



int read_lfsr(LFSR* L)
{
/*Return the current output bit (the rightmost bit of the state variable) */
//get the rghtmost bit by returning L mod 2
	return L->state%2;
}



//showbits function taken from wikipedia for testing
void showbits(int x)
{
    int i; 
    for(i=(sizeof(int)*8)-1; i>=0; i--)
            (x&(1u<<i))?putchar('1'):putchar('0');
    
    printf("\n");
}
//0x80000000 in unsighned int is the equivilent of an int value with only one 1 on the leftmost bit and all zeros after. using this value to add 1 on the leftmost bit when needed.
//above is 32 bit. need to replace it iwth the 64 bit equivlent. 	j = (j >>1) | 0x80000000;

int main()
{
	LFSR L;
	uint64_t initial_state = 0xbeefcafebabecab1;
	uint64_t taps = 0xdeaddeedacedface;
	init_LFSR(&L,initial_state,taps);
	//everyhing after this i need to fill in myself

	//test
	uint64_t i;
	//printf("%d\n", i);
	i=parity(L.taps & L.state);
	printf("%llu\n", i);





}
