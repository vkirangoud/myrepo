#include <stdio.h>
#include <stdlib.h>


#define N 100000
FILE *fin = NULL;



long long M_Sort(int *A, int *B, int n);
long long joinLeftRight( int *lf, int *rt, int *b, int ln, int rn);

int main(int argc, char *argv[])
{
  int arr[N] = {0};
  int B[N]   = {0};
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
  
  // int inv = merge_sort(arr, B, i);
  long long inv = M_Sort(arr, B, i);
  printf("No. of inversions = %lld\n",inv);
#if 0
  printf("Sorted array\n");

  for(int k = 0; k < i; k++)
    {
      printf("%d\n",arr[k]);
    }
#endif 
  return 0;
}

long long M_Sort(int *A, int *B, int n)
{
  if (n == 1)
    {      
      return 0;
    }

  int left_len = n/2;
  int rt_len = n - left_len;
  int *lef_arr = A;
  int *rt_arr  = A+left_len;
 

  long long X = M_Sort(lef_arr, B, left_len);
  long long Y = M_Sort(rt_arr,B,rt_len);
  long long Z = joinLeftRight(lef_arr, rt_arr, B, left_len, rt_len);
 
  return (X + Y + Z);

}

long long joinLeftRight( int *lf, int *rt, int *b, int ln, int rn)
{
  int i = 0;  
  int k = 0;
  int j = 0;
  long long inv = 0;
  
  for (i = 0; i < ln; i++)
    {
      b[i] = lf[i];
    }
  i = 0;
  while((i < ln) && (j < rn))  
    {
      if (b[i] < rt[j])
	{
	  lf[k++] = b[i++];
	}      else
	{
	  lf[k++] = rt[j++];
	  inv += (ln - i);
	}	
    }

  while(i < ln)
    {
      lf[k++] = b[i++];
    }

  return inv;
  
}
