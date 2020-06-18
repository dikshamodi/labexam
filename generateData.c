#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int present[100000000];

int main(int argc, char *argv[]) {
	assert(argc == 2);
	const int N=atoi(argv[1]);
	FILE *fptr = fopen("input.in", "w");
	int i =0;
	while (i < N) {
		int val;
		do {
			val = random() % N+1;
		} while(present[val]);
		present[val] = 1;
		fprintf(fptr, "%d ", val);
		i++;
	}
	
	fprintf(fptr,"\n");
	fclose(fptr);

	return 0;
}
