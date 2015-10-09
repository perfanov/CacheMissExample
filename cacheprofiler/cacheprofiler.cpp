#include "stdafx.h"

#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <sstream>
#include <cstring>
using namespace std;

int main(int argc, char* argv[]) {
	#define SIZE 64*1024*1024
	char* data = (char*)malloc(SIZE);
	if (data == NULL) { cout << "OutOfMem"; return 0; }
	char** seq_ptrs = (char**)malloc(SIZE*sizeof(char*));
	if (seq_ptrs == NULL) { cout << "OutOfMem 2"; return 0; }

	
	for (int i = 0; i < SIZE; ++i)
	{
		seq_ptrs[i] = (&data[i]);
	}
	
	for (int i = 0; i < SIZE; ++i)
	{
		data[i] = rand()%255;
	}
	
	char** rnd_ptrs = (char**) malloc(SIZE*sizeof(char*));
	if (rnd_ptrs == NULL) { cout << "OutOfMem 3"; return 0; }
	memcpy(rnd_ptrs,seq_ptrs,SIZE*sizeof(char*));

	for (int i = 0; i < SIZE-1; ++i)
	{
		int num = rand() % (SIZE - i - 1) + i;
		char* a = rnd_ptrs[num];
		rnd_ptrs[num] = rnd_ptrs[i];
		rnd_ptrs[i] = a;
	}

	clock_t t;
  	t = clock();
  	int sum=0;
	for (int i = 0; i < SIZE; ++i) sum += *(seq_ptrs[i]);
    t = clock() - t;
  	printf ("seq: %d clicks (%f seconds). Don't optimize sum=%d!",t,((float)t)/CLOCKS_PER_SEC,sum);
    
    clock_t t2;
  	t2 = clock();
  	int sum2=0;
	for (int i = 0; i < SIZE; ++i) sum2 += *(rnd_ptrs[i]);
    t2 = clock() - t2;
  	printf ("\nrnd: %d clicks (%f seconds). Don't optimize sum2=%d!",t2,((float)t2)/CLOCKS_PER_SEC,sum2);

	clock_t t3;
  	t3 = clock();
  	int sum3=0;
	for (int i = 0; i < SIZE; ++i) sum3 += data[i];
    t3 = clock() - t3;
  	printf ("\ndirect access: %d clicks (%f seconds). Don't optimize sum3=%d!",t3,((float)t3)/CLOCKS_PER_SEC,sum3);

	return 0;
}