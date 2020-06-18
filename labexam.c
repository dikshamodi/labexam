#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

int arr[100000000] = {};

// QuickSelect algorithm
int kthSmallest(int l , int r, int k) {
	if (l > r)	return -1;
	int pivind = l;
	int pivot = arr[pivind];

	int left = l;
  int i = l;
	while (i <=r) {
		if (arr[i] < pivot) {		
			int temp = arr[left];
			arr[left] = arr[i];
			arr[i] = temp;
      left++;
		}
		i++;
	}

  int pivotInd = left;

  if (k == left-l+1) {
    return arr[left];
  }
  else if (k < left - l + 1) {// left
    return kthSmallest(l,left-1,k);
  } 
  else  { // right
    return kthSmallest(left+1, r, k- (left - l +1));
  }
}


int main(int argc, char *argv[]) {
	assert(argc >= 2);
	int n = atoi(argv[1]);
	FILE *fptr = fopen("input.in", "r");
	
	for (int i = 0; i < n; i++) {
		int val;	
		fscanf(fptr, "%d", &val);
		arr[i] = val;
	}
	clock_t start = clock();
  int k;
  scanf("%d", &k);
	printf("the kth smallest is %d\n",kthSmallest(0,n-1, k));

	clock_t end = clock();

	printf("%d %lf\n", n, 1.0*(end-start)/CLOCKS_PER_SEC);
	return 0;
}
