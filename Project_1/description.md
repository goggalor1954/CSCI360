# Project 1
## Historical cryptography

The goal of this project is to break a substitution cipher. A [substitution cipher](https://en.wikipedia.org/wiki/Substitution_cipher) is a cipher in which a plaintext is converted character by character into ciphertext by using a predetermined rule of association.  For example, the Caesar cipher is a special kind of substitution cipher in which

$A \rightarrow D$, $B \rightarrow E$, $C \rightarrow F$, etc.

The Caesar cipher has a very simple form, because each character is simply advanced three places to form the ciphertext.  However, in general, the rule can be more complicated.

The following text is given in the file called `ciphertext.txt` in the assignment folder.

```
<X%Z|*aZXcWZa%c[R>Z[%csX%WZ<X%Z+%[PWPcaZcaWZXP|Z|sL[sXPa\Z[c>|Zi%RRZi*RRZLaZ<X%Z[Ls.|Z4XPsXZ|%%+%WZ<X%+|%Ry%|Z|%a|POR%ZLiZ<X%ZX%c<Z<XL*|caW|ZLiZ\[c||XL77%[|ZXPWW%aZPaZ<X%ZO*|X%|ZsXP[7%WZ4P<XZcZ+LaL<LaL*|ZcaWZW*RRZaL<%Z<X%ZR%cy%|ZLiZ<X%Z+>[<R%ZcaWZLRPy%Z<[%%|Z4cy%WZcaWZ[*|<R%WZPaZ<X%Z4PaWZc<Z%y%[>Z|<%7Z<Xc<Z%W+LaWZ<LL.ZX%ZWP|<*[O%WZ<X%ZRPoc[W|Z\RP<<%[Pa\Z4P<XZ<X%ZX*%|ZLiZ<X%Z%+%[cRWZcic[ZLiiZX%Z|c4Z<X%Z4PRWZ\Lc<|ZOL*aWPa\Zi[L+Zs[c\Z<LZs[c\ZPaZcZ4L[WZ<X%ZP|RcaWZ4c|ZPaXcOP<%WZ>%<Z%W+LaWZi%R<ZXP+|%RiZcRLa%Z\*PW%WZO>Z<X%ZXcaWZLiZ\LWX%Zi%R<ZcaZPaW%|s[POcOR%Z|%a|c<PLaZ|L+%4Xc<Zc.PaZ<LZW[%cW<Xc<ZW[%cWZLiZ<X%ZWc>RP\X<Z4XPsXZ%y%aZPaZ<X%ZW%|%[<Z+c.%|Z*|Zi%c[Z4%Zc[%Z4c<sX%WZcaWZLO|%[y%WZ<XP|Zi%%RPa\Z4c|Z|LZ|<[La\Z<Xc<Zc<Z<X%Z+L+%a<Z4X%aZ%W+LaWZ4c|ZcOL*<Z<LZO%\PaZXP|ZRcOL[ZX%Z|<L77%WZRcPWZWL4aZXP|Z7Ps.c6%Z|%Po%WZXP|Z\*aZ+L*a<%WZ<LZ<X%Z|*++P<ZLiZ<X%ZXP\X%|<Z[Ls.ZcaWZi[L+Z<X%as%Z\co%WZ[L*aWZPaZ%y%[>ZWP[%s<PLaO*<ZP<Z4c|ZaL<Z*7LaZsL[|PscZ<X%Zy%[>ZXL*|%|ZLiZ4XPsXZX%ZsL*RWZWP|<Pa\*P|XZL[ZLaZ|c[WPaPcZL[ZLaZ<X%ZP|RcaWZLiZ%ROcZ4P<XZP<|ZXP|<L[PscRZc||LsPc<PLa|ZL[Z*7LaZ<X%ZcR+L|<ZP+7%[s%7<POR%ZRPa%Z<Xc<Z<LZ<X%Z%67%[P%as%WZ%>%ZLiZcZ|cPRL[ZcRLa%Z[%y%cR%WZ<X%ZsLc|<ZLiZ\%aLcZ<X%Z7[L*WZcaWZR%\XL[aZ<X%ZsL++%[sPcRZ<Xc<ZX%Z\co%WZP<Z4c|Zc<Z<X%ZO[P\ca<Pa%Z<Xc<ZXcWZR%i<ZPaZ<X%Z+L[aPa\ZcaWZ<X%Z<c[<caZ<Xc<ZXcWZ:*|<Z|%<Z|cPRZ<Xc<Z%W+LaWZiP6%WZXP|Z%>%|<X%ZiP[|<Z4c|Z:*|<ZWP|c77%c[Pa\ZPaZ<X%Z|<[cP<|ZLiZOLaPicsPLZ<X%ZL<X%[ZiLRRL4Pa\ZcaZL77L|P<%ZWP[%s<PLaZ4c|ZcOL*<Z<LZ[L*aWZ<X%ZP|RcaWZLiZsL[|Psc<XP|Z|P\X<Z[%c||*[%WZXP+ZX%Z<X%aZRLL.%WZc<Z<X%ZLO:%s<|Za%c[ZXP+ZX%Z|c4Z<Xc<ZX%Z4c|ZLaZ<X%ZXP\X%|<Z7LPa<ZLiZ<X%ZP|RcaWcZ|<c<*%ZLaZ<XP|Zyc|<Z7%W%|<cRZLiZ\[caP<%ZaL<XPa\ZX*+caZc77%c[Pa\ZPaZ|P\X<Z4XPR%Z<X%ZOR*%ZLs%caZO%c<Zc\cPa|<Z<X%ZOc|%ZLiZ<X%ZP|RcaWZcaWZsLy%[%WZP<Z4P<XZcZi[Pa\%ZLiZiLc+Z<X%aZX%ZW%|s%aW%WZ4P<XZsc*<PL*|ZcaWZ|RL4Z|<%7ZiL[ZX%ZW[%cW%WZR%|<ZcaZcssPW%a<Z|P+PRc[Z<LZ<Xc<ZX%ZXcWZ|LZcW[LP<R>Zi%P\a%WZ|XL*RWZXc77%aZPaZ[%cRP<>Wca<|Zc|Z4%ZXcy%Z|cPWZXcWZ<[cs%WZ<X%Z+c[.|ZcRLa\Z<X%Z[Ls.|ZcaWZX%ZXcWZaL<Ps%WZ<Xc<Z<X%>ZR%WZ<LZcZ|+cRRZs[%%.Z4XPsXZ4c|ZXPWW%aZRP.%Z<X%ZOc<XZLiZ|L+%ZcasP%a<Za>+7XZ<XP|Zs[%%.Z4c|Z|*iiPsP%a<R>Z4PW%Zc<ZP<|Z+L*<XZcaWZW%%7ZPaZ<X%Zs%a<[%Z<LZcW+P<ZLiZ<X%Z%a<[cas%ZLiZcZ|+cRRZy%||%RZLiZ<X%ZR*\\%[ZsRc||Z4XPsXZ4L*RWZO%Z7%[i%s<R>ZsLas%cR%WZi[L+ZLO|%[yc<PLa<X%aZiLRRL4Pa\Z<X%ZsR%4Z<Xc<ZPaZ<X%ZXcaW|ZLiZ<X%ZcOOZic[PcZXcWZO%%aZ|LZ|.PRi*RR>Z*|%WZ<LZ\*PW%ZXP+Z<X[L*\XZ<X%ZWWcRPcaZRcO>[Pa<XZLiZ7[LOcOPRP<P%|ZX%Z<XL*\X<Z<Xc<Z<X%Zsc[WPacRZ|7cWcZca6PL*|ZaL<Z<LZO%Z4c<sX%WZXcWZ%a<%[%WZ<X%Zs[%%.ZsLas%cR%WZXP|ZRP<<R%ZOc[C*%ZiLRRL4%WZ<X%ZRPa%Z+c[.%WZO>Z<X%ZaL<sX%|ZPaZ<X%Z[Ls.ZcaWZc<Z<X%Z%aWZLiZP<ZXcWZO*[P%WZXP|Z<[%c|*[%ZP<Z4c|Z<XP|ZPW%cZ<Xc<ZXcWZO[L*\X<ZWca<|ZOcs.Z<LZ<X%ZsP[s*Rc[Z[Ls.ZLa%Z<XPa\ZLaR>Z7%[7R%6%WZ%W+LaWZcaWZW%|<[L>%WZXP|Z<X%L[>ZXL4ZsL*RWZ<XP|Z[Ls.Z4XPsXZ4%P\X%WZ|%y%[cRZ<La|ZXcy%ZO%%aZRPi<%WZ<LZ<XP|Z|7L<Z4P<XL*<Z<X%ZcPWZLiZ+ca>Z+%a|*WW%aR>ZcaZPW%cZiRc|X%WZcs[L||ZXP|Z+PaWZPa|<%cWZLiZ[cP|Pa\ZP<Z<XL*\X<ZX%Z<X%>ZXcy%ZRL4%[%WZP<ZcaWZX%Z|7[ca\Zi[L+Z<X%Z[Ls.ZPaZL[W%[Z<LZPa|7%s<Z<X%ZOc|%ZLaZ4XPsXZP<ZXcWZiL[+%[R>Z|<LLWX%Z|LLaZ7%[s%Py%WZ<Xc<ZcZ|RL7%ZXcWZO%%aZiL[+%WZcaWZ<X%Z[Ls.ZXcWZ|RPWZcRLa\Z<XP|Z*a<PRZP<Z|<L77%WZc<Z<X%Z|7L<ZP<ZaL4ZLss*7P%WZcZRc[\%Z|<La%ZXcWZ|%[y%WZc|ZcZ4%W\%ZiRPa<|ZcaWZ7%OOR%|ZXcWZO%%aZPa|%[<%WZc[L*aWZP<Z|LZc|Z<LZsLas%cRZ<X%ZL[PiPs%Z<XP|Z|7%sP%|ZLiZ+c|La[>ZXcWZO%%aZsLy%[%WZ4P<XZ%c[<XZcaWZ\[c||ZcaWZ4%%W|ZXcWZ\[L4aZ<X%[%Z+L||ZXcWZsR*a\Z<LZ<X%Z|<La%|Z+>[<R%O*|X%|ZXcWZ<c.%aZ[LL<ZcaWZ<X%ZLRWZ[Ls.Z|%%+%WZiP6%WZ<LZ<X%Z%c[<X
```

This ciphertext was produced in the following way:

1.  A plaintext was chosen consisting only of uppercase alphabetical characters and the space character.
2.  A mapping was chosen at random from the ASCII characters {' ','A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'} into all printable ASCII characters.
3.  Each plaintext character was replaced by its image character under the mapping.

In case this is confusing, the following simplified example may be helpful.  Suppose that the plaintext is "WHAT ARE YOU SAYING".  We pick a rule of association that maps the plaintext characters to ciphertext characters in the following way:

$A \rightarrow X$

$B \rightarrow E$

$C \rightarrow v$

$D \rightarrow \&$

$E \rightarrow r$

$F \rightarrow z$

$G \rightarrow @$

$H \rightarrow 6$

$I \rightarrow \backslash$

$J \rightarrow 8$

$K \rightarrow 5$

$L \rightarrow e$

$M \rightarrow :$

$N \rightarrow I$

$O \rightarrow D$

$P \rightarrow )$

$Q \rightarrow Y$

$R \rightarrow L$

$S \rightarrow Q$

$T \rightarrow +$

$U \rightarrow ``$

$V \rightarrow \_$

$W \rightarrow n$

$X \rightarrow b$

$Y \rightarrow \#$

$Z \rightarrow <$

$space \rightarrow \hat{ }$

Then, under this rule,

ENC("WHAT ARE YOU SAYING") = "`n6X+^XLr^#D"^QX#\I@`"

where ENC denotes encryption.  You may want to confirm that the first few letters are consistent with the mapping shown above.  For instance, it is indeed true that W maps to n, H maps to 6, etc.

The embedding used in the simple example is not the same embedding that was used to produce the long ciphertext given at the beginning of this project description.  Your job is to recover that embedding as well as the unknown plaintext.

---

### Requirements

Your code should meet the following requirements.

1. You can use any of the acceptable programming languages we discussed in class.
1. Your code must read in input from a file.  In other words, you must read in the ciphertext from the file ciphertext.txt.  Do not hard code it as a string literal. This is essential because I will test your code on other ciphertexts.
1. Whatever language you choose, the basename of your solution should be "sol".  For example, if you use C call your solution `sol.c`, if you use Java then call your solution `sol.java`.
1. You are free to work in your own IDE, but I would prefer it if you could ensure that all paths are relative, so that the same code works unchanged on cocalc.

If you would like information about how to compile your code from the command line on cocalc, I would be happy to assist you.

### Input/Output Conditions

#### Corpus cleaner

Please create a program called `sol_cleaner.ext`, where `ext` denotes the file extension corresponding to your choice of programming language (.py, .c, .cpp, .c++, or .java).

This program should open and read in a file named `corpus.txt`.  This file should be a large body of work written in English (such as one of the [books freely downloadable from Project Gutenberg](https://www.gutenberg.org/files/2600/2600-0.txt)).

As output, the program should produce a new file called `corpus_clean.txt` which is similar to the input, except that:

* All characters that are not spaces or alphabetical characters have been filtered out.
* All alphabetical characters have been capitalized.


#### Statistics analyzer (plaintext):

Please create a program called `sol_sap.ext`, where `ext` denotes the file extension corresponding to your choice of programming language (.py, .c, .cpp, .c++, or .java).

This program should open and read in a file named `corpus_clean.txt`, which is the output from `sol_cleaner.ext`.  As output it should produce a file called `corpus_freq.txt`, which contains the following.  Each row is a pair

```
<letter>, <rel_freq>
```
where `letter` is a character occurring in the text and `rel_freq` is the relative frequency of the letter in the corpus.  The relative frequency of a letter `c` is defined by:

$$relative\, frequency\, of\, c = \frac{\#\,occurrences\, of\, c\, in\, corpus}{\#\, letters\, in\, corpus}$$

Note that this will be a floating point number.

The letter/frequency pairs should be given in order of descending frequency. For example, the file should roughly look like this.

```
e, 0.082198
a, 0.050031
(etc)
z, 0.003000

```
I have made up the values in the above table for the sake of example.

It is possible to implement this algorithm in a way that only makes one pass over the corpus.  However, if you prefer to read through the file 27 times, that is feasible.

#### Statistics analyzer (ciphertext)

Please create a program called `sol_sac.ext`, where `ext` denotes the file extension corresponding to your choice of programming language (.py, .c, .cpp, .c++, or .java).

This program should read in the file `ciphertext.txt`.  The output should be a file `cipher_freq.txt` which is much like `corpus_freq.txt`, but with ciphertext characters rather than only letters and spaces.
This is very similar to the statistical analyzer for the corpus, and you should be able to reuse the code you have from the previous task with very few changes. In fact there is a way to arrange things so that this program is identical to `sol_sap.ext`.  (But please hand in two files to make the grading uniform.)

#### Cipher cracker

Please create a program called `sol_cracker.ext`, where `ext` denotes the file extension corresponding to your choice of programming language (.py, .c, .cpp, .c++, or .java).

This program reads in three files: `ciphertext.txt`, `cipher_freq.txt`, and `corpus_freq.txt`.

The output of this program should be a file called `cracked.txt`.  It should be the result of replacing each charact of ciphertext.txt with a capital Roman letter or a space.  The correspondnce is given by the files `cipher_freq.txt` and `corpus_freq.txt`.  The character in row $i$ of `cipher_freq.txt` should be replaced with the letter (or space) in row $i$ of `corpus_freq.txt`.  (Note that for this to work, both `cipher_freq.txt` and `corpus_freq.txt` must be sorted by frequency.)

The result will probably not be a perfect decrypt, but the output should be close enough to cleartext to repair the remaining problems manually.

#### Manual corrections (optional)

In this optional part of the project, you should create a file called `sol_corrections.ext`, where `ext` denotes the file extension corresponding to your choice of programming language (.py, .c, .cpp, .c++, or .java).

This program should read the file `cracked.txt` as input and output a file called `clear.txt`.  The output should be the original plaintext used to produce the ciphertext.

This program works by making letter substitutions in `cracked.txt` that you observe to be appropriate, treating the remaining work to be done as a recreational [cryptogram](https://en.wikipedia.org/wiki/Cryptogram).


---

#### Reports

In this directory you will see a script called `test.py`.  I will use this script, or something like it, to help grade your code.  You can execute it from the command line like this:

```
$ python test.py
```

Do not type the `$`, that is only in the above to show where the command prompt is.  Please let me know if you get strange results.

The script will produce a file called `Pr
