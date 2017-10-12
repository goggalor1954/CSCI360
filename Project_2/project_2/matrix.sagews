︠76b6be2d-b260-4f48-a89a-e89ddcfa88e1i︠
%md
# Using Sage to crack an LFSR

I will begin with a motivating example in which $m=3$.  I will then describe how to generalize this approach to the situation when $m=64$.

We know that to solve a degree 3 LFSR from known keystream $s_0,s_1,s_2,s_3,s_4,s_5$, we must solve this system of equations:


\begin{array}{c}
p_0 s_0+p_1 s_1 + p_2 s_2 = s_3\, (mod\, 2)\\
p_0 s_1+p_1 s_2 + p_2 s_3 = s_4\, (mod\, 2)\\
p_0 s_2+p_1 s_3 + p_2 s_4 = s_5\, (mod\, 2)
\end{array}

In the language of linear algebra, this problem can be translated into matrix form:

$$A\bar{p} = \bar{x}$$

where $A$ is a $3\times 3$ matrix, $\bar{p}$ are the unknown taps, and $\bar{x}$ is the last $m$ bits of the known key stream.

More explicitly, we need to solve this linear system:

$$\left(\begin{array}{rrr}
s_0 & s_1 & s_2 \\
s_1 & s_2 & s_3 \\
s_2 & s_3 & s_4
\end{array}
\right)
\left(\begin{array}{rrr}
p_0 \\
p_1\\
p_2
\end{array}
\right)
=\left(\begin{array}{rrr}
s_3 \\
s_4\\
s_5
\end{array}
\right)\, (mod\, 2)$$

If you do not find this notation familiar, you may need to spend a few minutes reviewing [matrix multiplication.](https://en.wikipedia.org/wiki/Matrix_multiplication)

Sage has built-in libraries for solving these kinds of problems.

The syntax is the following:

```
M = MatrixSpace(Zmod(2),3,3)
A = M([s0,s1,s2,s1,s2,s3,s2,s3,s4])
x = vector([s3,s4,s5])
p = A.solve_right(x)

```

```

```


We now give an example in the next cell.
︡3ed70748-7621-4e97-a3b4-6bc26f6cda0a︡{"done":true,"md":"# Using Sage to crack an LFSR\n\nI will begin with a motivating example in which $m=3$.  I will then describe how to generalize this approach to the situation when $m=64$.\n\nWe know that to solve a degree 3 LFSR from known keystream $s_0,s_1,s_2,s_3,s_4,s_5$, we must solve this system of equations:\n\n\n\\begin{array}{c}\np_0 s_0+p_1 s_1 + p_2 s_2 = s_3\\, (mod\\, 2)\\\\\np_0 s_1+p_1 s_2 + p_2 s_3 = s_4\\, (mod\\, 2)\\\\\np_0 s_2+p_1 s_3 + p_2 s_4 = s_5\\, (mod\\, 2)\n\\end{array}\n\nIn the language of linear algebra, this problem can be translated into matrix form:\n\n$$A\\bar{p} = \\bar{x}$$\n\nwhere $A$ is a $3\\times 3$ matrix, $\\bar{p}$ are the unknown taps, and $\\bar{x}$ is the last $m$ bits of the known key stream.\n\nMore explicitly, we need to solve this linear system:\n\n$$\\left(\\begin{array}{rrr}\ns_0 & s_1 & s_2 \\\\\ns_1 & s_2 & s_3 \\\\\ns_2 & s_3 & s_4\n\\end{array}\n\\right)\n\\left(\\begin{array}{rrr}\np_0 \\\\\np_1\\\\\np_2\n\\end{array}\n\\right)\n=\\left(\\begin{array}{rrr}\ns_3 \\\\\ns_4\\\\\ns_5\n\\end{array}\n\\right)\\, (mod\\, 2)$$\n\nIf you do not find this notation familiar, you may need to spend a few minutes reviewing [matrix multiplication.](https://en.wikipedia.org/wiki/Matrix_multiplication)\n\nSage has built-in libraries for solving these kinds of problems.\n\nThe syntax is the following:\n\n```\nM = MatrixSpace(Zmod(2),3,3)\nA = M([s0,s1,s2,s1,s2,s3,s2,s3,s4])\nx = vector([s3,s4,s5])\np = A.solve_right(x)\n\n```\n\n```\n\n```\n\n\nWe now give an example in the next cell."}
︠ce6ff87c-9caf-456f-8ff6-71719de200d7s︠
"""
    This is an example of how Sage can solve a system of linear equations modulo 2.
    Run this cell to see how it works.
    You can run a cell by putting the cursor in the cell and hitting SHIFT-ENTER.
"""
#Declare M to be the space of 3x3 matrices mod 2.
M = MatrixSpace(Zmod(2),3,3)
#Suppose that these are the known keystream bits:
s0,s1,s2,s3,s4,s5 = 0, 1, 0, 1, 1, 1
#Let A be this particular matrix:
A = M([s0,s1,s2,s1,s2,s3,s2,s3,s4])
x = vector([s3,s4,s5])
print "\n\nHere is A:"
print A
print "\n Here is x:"
print x
print "\n Here is the solution (namely p) to the matrix equation Ap=x:"
p = A.solve_right(x)
print p

print "\nCheck that it works:"

A*p==x
︡7b8b23bd-48c8-4a90-99a3-22dad3afec8f︡{"stdout":"'\\n    This is an example of how Sage can solve a system of linear equations modulo 2.\\n    Run this cell to see how it works.\\n    You can run a cell by putting the cursor in the cell and hitting SHIFT-ENTER.\\n'\n"}︡{"stdout":"\n\nHere is A:\n"}︡{"stdout":"[0 1 0]\n[1 0 1]\n[0 1 1]\n"}︡{"stdout":"\n Here is x:\n"}︡{"stdout":"(1, 1, 1)\n"}︡{"stdout":"\n Here is the solution (namely p) to the matrix equation Ap=x:\n"}︡{"stdout":"(1, 1, 0)\n"}︡{"stdout":"\nCheck that it works:\n"}︡{"stdout":"True\n"}︡{"done":true}︡
︠47959c3b-dfef-40df-af48-20a5971da455i︠
%md

You can think of the code in the above box as cracking an LFSR with initial state

$$s_0,s_1,s_2= 0, 1, 0$$

and taps given by

$$p_0,p_1,p_2= 1, 1, 0$$

The equation solved is exactly the one given in the book for $m=3$, and $2m=6$ bits of known plaintext.

The known 6 bits of the keystream are:

```
s0,s1,s2,s3,s4,s5 = 0, 1, 0, 1, 1, 1
```

The code then tells us the taps.

Here we write the state transitions resulting from the taps and the initial state:


$$
\begin{array}
0010 \rightarrow 0 \\
101 \rightarrow 1 \\
110 \rightarrow 0 \\
111 \rightarrow 1 \\
011 \rightarrow 1 \\
001 \rightarrow 1 \\
\vdots
\end{array}
$$


Observe that the output,

```
s0,s1,s2,s3,s4,s5 = 0, 1, 0, 1, 1, 1
```

is exactly as expected.

This gives good reason to believe that the LFSR will generate the desired keystream.

---

Note that sage returns the solution ($\bar{p} = (p_0,p_1,p_2)$) to the equation below with the indexes on the $p$'s in increasing order.

$$\left(\begin{array}{rrr}
s_0 & s_1 & s_2 \\
s_1 & s_2 & s_3 \\
s_2 & s_3 & s_4
\end{array}
\right)
\left(\begin{array}{rrr}
p_0 \\
p_1\\
p_2
\end{array}
\right)
=\left(\begin{array}{rrr}
s_3 \\
s_4\\
s_5
\end{array}
\right)\, (mod\, 2).$$

However the usual notation for LFSRs would write these in reverse order,

$$s_2,s_1,s_0= 0, 1, 0$$

and taps given by

$$p_2,p_1,p_0= 0, 1, 1.$$

*For this reason we will need to reverse the Sage output to make it correspond with the tap input given in the file `lfsr.c`*.



The simple example just given generalizes to solving the problem from Project 2.  The only difference is that the degree is now $m=64$, which is a little bit larger than 3.
︡14f3a27b-4a4d-4b19-837c-08133bf9bb5e︡{"done":true,"md":"\nYou can think of the code in the above box as cracking an LFSR with initial state\n\n$$s_0,s_1,s_2= 0, 1, 0$$\n\nand taps given by\n\n$$p_0,p_1,p_2= 1, 1, 0$$\n\nThe equation solved is exactly the one given in the book for $m=3$, and $2m=6$ bits of known plaintext.\n\nThe known 6 bits of the keystream are:\n\n```\ns0,s1,s2,s3,s4,s5 = 0, 1, 0, 1, 1, 1\n```\n\nThe code then tells us the taps.\n\nHere we write the state transitions resulting from the taps and the initial state:\n\n\n$$\n\\begin{array}\n0010 \\rightarrow 0 \\\\\n101 \\rightarrow 1 \\\\\n110 \\rightarrow 0 \\\\\n111 \\rightarrow 1 \\\\\n011 \\rightarrow 1 \\\\\n001 \\rightarrow 1 \\\\\n\\vdots\n\\end{array}\n$$\n\n\nObserve that the output,\n\n```\ns0,s1,s2,s3,s4,s5 = 0, 1, 0, 1, 1, 1\n```\n\nis exactly as expected.\n\nThis gives good reason to believe that the LFSR will generate the desired keystream.\n\n---\n\nNote that sage returns the solution ($\\bar{p} = (p_0,p_1,p_2)$) to the equation below with the indexes on the $p$'s in increasing order.\n\n$$\\left(\\begin{array}{rrr}\ns_0 & s_1 & s_2 \\\\\ns_1 & s_2 & s_3 \\\\\ns_2 & s_3 & s_4\n\\end{array}\n\\right)\n\\left(\\begin{array}{rrr}\np_0 \\\\\np_1\\\\\np_2\n\\end{array}\n\\right)\n=\\left(\\begin{array}{rrr}\ns_3 \\\\\ns_4\\\\\ns_5\n\\end{array}\n\\right)\\, (mod\\, 2).$$\n\nHowever the usual notation for LFSRs would write these in reverse order,\n\n$$s_2,s_1,s_0= 0, 1, 0$$\n\nand taps given by\n\n$$p_2,p_1,p_0= 0, 1, 1.$$\n\n*For this reason we will need to reverse the Sage output to make it correspond with the tap input given in the file `lfsr.c`*.\n\n\n\nThe simple example just given generalizes to solving the problem from Project 2.  The only difference is that the degree is now $m=64$, which is a little bit larger than 3."}
︠8a60499b-1a9d-4f0c-a8a4-248062a2eeb5i︠
%md

In order to solve Project 2 you will need to use a known plaintext attack to recover $2m=128$ bits of keystream,

$$s_0,s_1,\ldots,s_{126},s_{127}.$$

Once you know these bits, you will need to use Sage to solve the linear system


$$\left(\begin{array}{rrr}
s_0 & s_1 & \ldots & s_{63} \\
s_1 & s_2 & \ldots & s_{64} \\
\vdots & \vdots & \ldots & \vdots \\
s_{63} & s_{64} & \ldots & s_{126}
\end{array}
\right)
\left(\begin{array}{rrr}
p_0 \\
p_1\\
\vdots \\
p_{63}
\end{array}
\right)
=\left(\begin{array}{rrr}
s_{64} \\
s_{65}\\
\vdots \\
s_{127}
\end{array}
\right)\, (mod\, 2)$$

Sage will then solve for the vector $(p_0,p_1,\ldots,p_{63})$.
You can then reverse the order of these bits and use them to load into the LFSR.
Together with the known initial state $(s_0,\ldots,s_{63})$ you can then generate the keystream and decrypt the ciphertext.

The Sage code you need to do this is provided below.  Everything is ready except for the values in the matrix

$$A =  \left(\begin{array}{rrr}
s_0 & s_1 & \ldots & s_{63} \\
s_1 & s_2 & \ldots & s_{64} \\
\vdots & \vdots & \ldots & \vdots \\
s_{63} & s_{64} & \ldots & s_{126}
\end{array}
\right)
$$

and the vector

$$
x=\left(\begin{array}{rrr}
s_{64} \\
s_{65}\\
\vdots \\
s_{127}
\end{array}
\right)
$$

If you can provide these, then the Sage code will proceed to solve

$$A\bar{p} = \bar{x}$$

and return $\bar{p}=(p_0,p_1,\ldots,p_{63})$.  As stated above, this bit string will need to be reversed (and converet to hex) in order to feed into `lfsr.c`.

The Sage code below automatically does that part, so that the hex output can be directly pasted into `lfsr.c`.

The thing that you must do is to supply the files `S.mat.sage` and `V.mat.sage` from which the data is loaded.

Right now these files contain toy data.  For example, here is `S.mat.sage`:

```
A = matrix(Zmod(2),[[0,1,1],
[1,1,1],
[0,0,1]])
```

```
```

This plays the role of the $m\times m$ matrix of state bits

$$A =  \left(\begin{array}{rrr}
s_0 & s_1 & \ldots & s_{63} \\
s_1 & s_2 & \ldots & s_{64} \\
\vdots & \vdots & \ldots & \vdots \\
s_{63} & s_{64} & \ldots & s_{126}
\end{array}
\right).
$$

Here is `V.mat.sage`:

```
x = vector(Zmod(2),[0,1,0])
```

```
```

This plays the role of the known state bits

$$
x=\left(\begin{array}{rrr}
s_{64} \\
s_{65}\\
\vdots \\
s_{127}
\end{array}
\right).
$$

The problem is that right now they are too small, and contain irrelevant data.

You must fill them up with real data pertinent to the problem posed in Project 2.

Because this would require a major amount of typing (mostly to produce the $64\times 64$ matrix, which has 4096 entries), you will want to use computer code to make the files `S.mat.sage` and `V.mat.sage`.

The outline of the code for doing this is provided for you in this function in `lfsr.c`:

```
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
```

You can then run the Sage coded provided below, and you will then have the taps for the target LFSR.


︡32fd2ff1-cc77-4c2d-82b6-aa55f7a8e5da︡{"done":true,"md":"\nIn order to solve Project 2 you will need to use a known plaintext attack to recover $2m=128$ bits of keystream,\n\n$$s_0,s_1,\\ldots,s_{126},s_{127}.$$\n\nOnce you know these bits, you will need to use Sage to solve the linear system\n\n\n$$\\left(\\begin{array}{rrr}\ns_0 & s_1 & \\ldots & s_{63} \\\\\ns_1 & s_2 & \\ldots & s_{64} \\\\\n\\vdots & \\vdots & \\ldots & \\vdots \\\\\ns_{63} & s_{64} & \\ldots & s_{126}\n\\end{array}\n\\right)\n\\left(\\begin{array}{rrr}\np_0 \\\\\np_1\\\\\n\\vdots \\\\\np_{63}\n\\end{array}\n\\right)\n=\\left(\\begin{array}{rrr}\ns_{64} \\\\\ns_{65}\\\\\n\\vdots \\\\\ns_{127}\n\\end{array}\n\\right)\\, (mod\\, 2)$$\n\nSage will then solve for the vector $(p_0,p_1,\\ldots,p_{63})$.\nYou can then reverse the order of these bits and use them to load into the LFSR.\nTogether with the known initial state $(s_0,\\ldots,s_{63})$ you can then generate the keystream and decrypt the ciphertext.\n\nThe Sage code you need to do this is provided below.  Everything is ready except for the values in the matrix\n\n$$A =  \\left(\\begin{array}{rrr}\ns_0 & s_1 & \\ldots & s_{63} \\\\\ns_1 & s_2 & \\ldots & s_{64} \\\\\n\\vdots & \\vdots & \\ldots & \\vdots \\\\\ns_{63} & s_{64} & \\ldots & s_{126}\n\\end{array}\n\\right)\n$$\n\nand the vector\n\n$$\nx=\\left(\\begin{array}{rrr}\ns_{64} \\\\\ns_{65}\\\\\n\\vdots \\\\\ns_{127}\n\\end{array}\n\\right)\n$$\n\nIf you can provide these, then the Sage code will proceed to solve\n\n$$A\\bar{p} = \\bar{x}$$\n\nand return $\\bar{p}=(p_0,p_1,\\ldots,p_{63})$.  As stated above, this bit string will need to be reversed (and converet to hex) in order to feed into `lfsr.c`.\n\nThe Sage code below automatically does that part, so that the hex output can be directly pasted into `lfsr.c`.\n\nThe thing that you must do is to supply the files `S.mat.sage` and `V.mat.sage` from which the data is loaded.\n\nRight now these files contain toy data.  For example, here is `S.mat.sage`:\n\n```\nA = matrix(Zmod(2),[[0,1,1],\n[1,1,1],\n[0,0,1]])\n```\n\n```\n```\n\nThis plays the role of the $m\\times m$ matrix of state bits\n\n$$A =  \\left(\\begin{array}{rrr}\ns_0 & s_1 & \\ldots & s_{63} \\\\\ns_1 & s_2 & \\ldots & s_{64} \\\\\n\\vdots & \\vdots & \\ldots & \\vdots \\\\\ns_{63} & s_{64} & \\ldots & s_{126}\n\\end{array}\n\\right).\n$$\n\nHere is `V.mat.sage`:\n\n```\nx = vector(Zmod(2),[0,1,0])\n```\n\n```\n```\n\nThis plays the role of the known state bits\n\n$$\nx=\\left(\\begin{array}{rrr}\ns_{64} \\\\\ns_{65}\\\\\n\\vdots \\\\\ns_{127}\n\\end{array}\n\\right).\n$$\n\nThe problem is that right now they are too small, and contain irrelevant data.\n\nYou must fill them up with real data pertinent to the problem posed in Project 2.\n\nBecause this would require a major amount of typing (mostly to produce the $64\\times 64$ matrix, which has 4096 entries), you will want to use computer code to make the files `S.mat.sage` and `V.mat.sage`.\n\nThe outline of the code for doing this is provided for you in this function in `lfsr.c`:\n\n```\nvoid shape_keystream()\n{\n/* This function opens the file \"key_stream.txt\" created by\n   get_128_keystream_bits().  It uses this data to create a file called\n   \"S.mat.sage\" which is a 64x64 matrix of keystream bits of the form\n    discussed in the project description. It also creates a vector\n    (a 64x1 matrix) of keystream bits of the form described in the\n    project description.  This is stored in a file called \"V.mat.sage\" */\n\n      //See the file matrix.sagews for examples of what the output should look like.\n\n  /*You implement this*/\n\n}\n```\n\nYou can then run the Sage coded provided below, and you will then have the taps for the target LFSR."}
︠eafbb88c-866a-49ab-94c8-18952f9257ac︠
load("S.mat.sage") #loads the matrix A
load("V.mat.sage") #loads the vector x
P=A.solve_left(x)  #solves for p as a list of numbers eg (0,1,0,...,1,1)
P=list(reversed(P))#reverse the list eg (1,1, ..., 0,1,0)
Pstr = map(str,P)  #convert the list of numbers to a list of strings eg ('1','1',...,'0','1','0')
pis = "".join(Pstr)#concatenate the strings to make a bit sequence in string form, eg "11...010"
P_num = int(pis,2) #turn this bitstring into an integer, eg 100
hex(P_num)         #print the integer in hex format, eg 0x64
︡034ac6fd-551c-4f0b-8e88-14848e525ede︡{"stdout":"'0x5'\n"}︡{"done":true}︡
︠1a80cf10-681a-4532-9c5c-2f4761d7a019i︠
%md

When `S.mat.sage` and `V.mat.sage` contain the right data for the problem, the hex output from the previous cell can be pasted into the `taps` variable in `lfsr.c` to produce the keystream.

This keystream can then be used to decrypt the target.
︡1ca247f3-98b0-4494-8899-25c758154754︡{"done":true,"md":"\nWhen `S.mat.sage` and `V.mat.sage` contain the right data for the problem, the hex output from the previous cell can be pasted into the `taps` variable in `lfsr.c` to produce the keystream.  \n\nThis keystream can then be used to decrypt the target."}
︠fc26a147-5d9f-4d95-bf32-3d07c6207bd7︠









