/*
Code for 64 bit LFSR
Hunter Johnson
9/15/17

modified by: James Roesemann
10/12/17
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

int parity(uint64_t N)
{
/* Return the parity of N*/
	int p = __builtin_parity(N); // parity of first 32 bits
	N = __builtin_bswap64(N); //move back 32 to the front
	return (p+__builtin_parity(N))%2; //overall parity
}

int read_lfsr(LFSR* L)
{
/*Return the current output bit (the rightmost bit of the state variable) */


/* You implement this*/
	return L->state%2;

}

void next_state(LFSR* L)
{
/*Takes LFSR.
  Returns nothing.
  Side effect: advances L to next state.(shift to the right and replace leftmost bit with appropriate value)
*/

 /* You implement this.
    Hint:  make use of the parity() function provided above*/
    int lib=parity(L->state & L->taps);
    if(lib==1) L->state = (L->state >>1) | 0x8000000000000000;
    else L->state = (L->state >> 1);

}

void init_LFSR(LFSR* L, uint64_t initial_state, uint64_t taps)
{
/*Initialize with state and taps*/
	L->state = initial_state;
	L->taps = taps;
}


unsigned char get_stream_byte(LFSR* L)
{
/*Return one byte of keystream.
  Note that the byte fills up from left to right.
*/
	unsigned char C = 0;
	int i = 7;
	for(;i>=0;i--)
	{
		//printf("%d\n",read_lfsr(L));
		C |= (read_lfsr(L)<<i);
		next_state(L);
	}
	//printf("\t%d\n",C);
	return C;
}

void encrypt(char* pt,char* ct,LFSR *L)
{
/*Use the LFSR stream cipher to encrypt
  the file named pt (plaintext) and write the
  output to the file named ct (ciphertext);
*/
	FILE* PT = fopen(pt,"r");
	FILE* CT = fopen(ct,"w");
	assert(PT); //make sure files opened okay
	assert(CT);
	int c;
	while((c=getc(PT))!=-1)
	{
		unsigned char sb = get_stream_byte(L);
		fputc(sb^c,CT);
	}
	fclose(PT);
	fclose(CT);
}

void decrypt(char* pt,char* ct,LFSR *L){
/*Make sure L has been reset to the initial state*/
	encrypt(pt,ct,L);
}

void get_128_keystream_bits(char* ct,char* kpt)
{
/*This function takes 16 bytes of ciphertext and 16 bytes of
  known plaintext.
  The output is a file named "key_stream.txt" that contains 128 bits
  of keystream.  The stream is represented in ASCII, with 128 lines, and
  either a "0" or a "1" on each line.  */

/*This is the plaintext attack in which you recover 2m keystream bits.

      You implement this.
//idea for this. for loop to get the first 16 chatacter, maybe store them. combine them to a 64 bit int somehow in order. ah, i know. combine them into a word. no. i think you do an unsigned 64bit, shift by 8 and add the bytes fof the nex tcharacter. fill untill done. no. outoouting to a text file. i can just mod 2 to get the rightmost bit. store it. right shift, and when done output line by line/
*/
/*
creates an 8 value int array for stroage purposes.
reads in 16 characters of ct and then kpt
uses a for loop to get the rightmost bit, store it in the array and shift right untill the end of the character is reached. 
outputs the bit values one line at a time to the file "key_stream.txt"
*/
//i'm uncluar about what order i'm ment to output the bits. do i houtput the leftmost bit of the characters first or the rightmost bit? acoring to him leastsignificat bit first. ie rightmost bit.
	unsigned char C;
	FILE* CT = fopen(ct,"r");
	FILE* KPT = fopen(kpt,"r");
	FILE* KST = fopen("key_stream.txt","wb");
	assert(CT);
	assert(KPT);
	assert(KST);
	//read in 16 characters from ct, output their bit values to kst
	for(int i=0; i<16; i++)
	{
		C = getc(CT);
		//output bits to key_stream.txt
		for(int j=0; j<8; j++)
		{
			fputc(C%2, KST);
			fputc('\n', KST);
			C=C >>1;
		}
	}
	//read in 16 characters from kpt, output their bit values to kst
	for(int i=0; i<16; i++)
	{
		C = getc(KPT);
		//output bits to key_stream.txt
		for(int j=0; j<8; j++)
		{
			fputc(C%2, KST);
			fputc('\n', KST);
			C=C >>1;
		}
	}
	fclose(CT);
	fclose(KPT);
	fclose(KST);
}


void shape_keystream()
{
/* This function opens the file "key_stream.txt" created by
   get_128_keystream_bits().  It uses this data to create a file called
   "S.mat.sage" which is a 64x64 matrix of keystream bits of the form
    discussed in the project description. It also creates a vector
    (a 64x1 matrix) of keystream bits of the form described in the
    project description.  This is stored in a file called "V.mat.sage" */

      //See the file matrix.sagews for examples of what the output should look like.

  /*You implement this*/
}
//function that gets the first 8 bytes of the plaintest, prints it to the screen inorder to set initial state. remove when done.
void getFirstEight()
{
	unsigned char C;
	uint64_t firstEight=0;
	FILE* PT = fopen("toy_pt.txt","r");
	for(int i=0; i<8; i++)
	{
		C = getc(PT);
		for(int j=0; j<8; j++)
		{
			printf("%d",C%2);
			firstEight |= C%2;
			C = C>> 1;
		}
	}
	printf("\n");
	fclose(PT);	
}
//hex value of first 8 bytes of 


int main()
{
	LFSR L;
	//uint64_t initial_state = 0xbeefcafebabecab1; //original initial state.
	uint64_t 0xF7DDFD2A16A6040A;
	uint64_t taps = 0xdeaddeedacedface;
	init_LFSR(&L,initial_state,taps);
	encrypt("toy_pt.txt","ct.dat",&L);
	init_LFSR(&L,initial_state,taps);
	decrypt("ct.dat","toy_ot.txt",&L);
	//get_128_keystream_bits("target_ciphertext","<you fill this in>");
	//shape_keystream();

//test
	getFirstEight();
	//charTest('G');
}
