/*
  like quicksort partition method, the following function separate-out positive and non-positive elements of the 
  array in O(n) time and O(1) space
*/

int partition(vector<int> &A)
{
    int n=A.size();
    int q=-1;
    for(int i=0;i<n;i++)
    {
        if(A[i]>0)
        {
            q++;
            swap(A[i],A[q]);
        }
    }
    return q;
}
