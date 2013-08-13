#include <stdio.h>
#include <stdlib.h>


#define N 100000

void Swap (int *a, int *b)
{
  if (a == b) return;
  *a = *a + *b;
  *b = *a - *b;
  *a = *a - *b;
}

int partition3 (int *A, int l, int r);


long long  quicksortMedian (int *A, int l, int r);


int partition2 (int *A, int l, int r);
int partition (int *A, int l, int r);

long long  quicksortLast (int *A, int l, int r);
long long  quicksort (int *A, int l, int r);

int partition(int *A, int l, int r)
{
  int p = A[l]; // Pivot
  int i = l+1;
  int j;
  
  for(j= l+1; j <= r; j++)
    {
      if (A[j] < p)
	{
	  Swap(&(A[j]), &(A[i]));
	  i = i + 1;
	}
    }
  
  Swap(A+l, A+i-1);
  return i-1; // pivot location
}

long long  quicksort (int *A, int l, int r)
{
  int p; // pivot index
  long long c1 = r-l;
  if (r < l) return 0;  
if (r == 0) return c1;

 // Partition A around p 
  p = partition(A, l, r); 

   // Recursively sort 1st Part
  long long comp1 = quicksort(A, l,  p-1);
 // Recursively sort 2nd Part 
  long long comp2 = quicksort(A, p+1, r); 

  return comp1 + comp2 + c1;
}

int main(int argc, char *argv[])
{
  int arr[N] = {0};
  int B[N]   = {0};
  int C[N]  = {0}; 
  int i;
  int E = 0; // Error

  i = 0;
  for(;;)
    {
     E =  scanf("%d", &(arr[i]));
     if (EOF == E)
       {
	 break;
       }
     //  printf("%d\t%d\n", E,arr[i]);
      i++;
    }
  printf("No.of Elements = %d\n",i);

  for (int k = 0; k < i; k++)
    {
      B[k] = arr[k];
      C[k] = arr[k];
    }
  

  long long comp = quicksort(arr,0, i-1);
  printf("No. of comparisons = %lld\n",comp);

  comp = quicksortLast(B, 0, i-1);
  printf("No. of comparisons Pivot last Element = %lld\n",comp);

   comp = quicksortMedian(C, 0, i-1);
  printf("No. of comparisons Pivot Median Element = %lld\n",comp);

#if 0
  printf("Sorted array\n");

  for(int k = 0; k < i; k++)
    {
      printf("%d\t%d\t%d\n",arr[k],B[k],C[k]);
    }
#endif 
  return 0;
}


long long  quicksortLast (int *A, int l, int r)
{
  int p; // pivot index
  long long c1 = r-l;
  if (r < l) return 0;  
if (r == 0) return c1;

 // Partition A around p 
  p = partition2(A, l, r); 

   // Recursively sort 1st Part
  long long comp1 = quicksortLast(A, l,  p-1);
 // Recursively sort 2nd Part 
  long long comp2 = quicksortLast(A, p+1, r); 

  return comp1 + comp2 + c1;
}


int partition2(int *A, int l, int r)
{
  int p = A[r]; // Pivot
  int i = l+1;
  int j;
  //Select Pivot as Last Element
   Swap(&(A[l]), &(A[r]));
  
  for(j= l+1; j <= r; j++)
    {
      if (A[j] < p)
	{
	  Swap(&(A[j]), &(A[i]));
	  i = i + 1;
	}
    }
  
  Swap(A+l, A+i-1);
  return i-1; // pivot location
}


long long  quicksortMedian (int *A, int l, int r)
{
  int p; // pivot index
  long long c1 = r-l;
  if (r < l) return 0;  
  if (r == 0) return c1;

 // Partition A around p 
  p = partition3(A, l, r); 

   // Recursively sort 1st Part
  long long comp1 = quicksortMedian(A, l,  p-1);
 // Recursively sort 2nd Part 
  long long comp2 = quicksortMedian(A, p+1, r); 

  return comp1 + comp2 + c1;
}

#if 0
void choosePivot(int *A, int l, int r, int m)
{
  int a = A[l];
  int b = A[r];
  int c = A[m];
  int Midx = m;

if(((a<b)&&(b<c)) || ((a>b)&&(a<c)))
    {
      // min=a;
      Midx= r; //b;
	// max=c;
       Swap(&(A[l]), &(A[r]));
    }
    if(((b<a)&&(a>c)) || ((a>b)&&(a<c)))
    {
      //min=c;
      //mid=a;
      Midx = l;
        //max=b;
    }
    if(((c<a)&&(c>b)) || ((c>a)&&(c<b)))
    {
      //min=b;
      //mid=c;
      Midx = m;
 Swap(&(A[l]), &(A[m]));
        //max=a;
    }
  printf(" a = %d\tb = %d\tc = %d\tMedian = %d\n",a,b,c,A[l]);
}
#endif

int FindMedianIdx(int *A, int l, int r, int m)
{
  int a = A[l];
  int b = A[r];
  int c = A[m];  

   if(a < c)
    {
  	if(a >= b) return l;      
	else if (c < b)
	{
	  return m;
	}       
    }
    else
    {
	if (a < b) return l;
	else if (c >= b)
	{
	  return m;	   
	}
    }
    return r;  
}


int partition3(int *A, int l, int r)
{
  int p = 0; // Pivot
  int i = l+1;
  int j;
  int len;
  //Select Pivot as Median Element
 // int mid = l + (r - l + 1 + 1)/2;
  len = r - l + 1;
  int mid = l + ((len + (len & 1))/2);

  //choosePivot(A, l, r,  mid-1);
  p = FindMedianIdx(A, l, r, mid-1);
  Swap(&(A[p]), &(A[l]));
 
   p = A[l];
  for(j= l+1; j <= r; j++)
    {
      if (A[j] < p)
	{
	  Swap(&(A[j]), &(A[i]));
	  i = i + 1;
	}
    }
  
  Swap(A+l, A+i-1);
  return i-1; // pivot location
}
