/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* a, int n, int ts, int* rs) {
    int* res =(int*)malloc(2* sizeof(int));
    *rs=2;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]+a[j] == ts)
            {
                res[0]=i;
                res[1]=j;
                return res;
            }
        }
    }
    return 0;
    }