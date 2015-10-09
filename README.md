# CacheMissExample
Min memory required: ~300 or ~600 MB depending on target arch.

The program is used as a rough example on cache effects and indirection, and shouldn't be taken too scientifically, rather than just to demonstrate a consistent greater-than relationship between the speed of sequential and random memory access.

The software also demonstrates that different cpu architectures, systems, and compilers behave differently in different subcomponents and routines i.e. timeFor(random access) / timeFor(seq access) != invariant ! 

Demonstrates and profiles time taken to do the following things on a 64MB array:

#3: Direct access of N elements, into sum
#1: Direct access of N pointers, pointer resolving to N elements, and sum
#2: Direct access of N pointers, pointer resolving to N elements (in randomized order!), and sum.

Taking the sum and printing it, is used to have the compiler not optimize the routines away.