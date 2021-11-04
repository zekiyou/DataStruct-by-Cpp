#include <stdio.h>
#include <malloc.h>

long sum1(int n)
{
    long ret = 0;
    int* array = (int*)malloc(n * sizeof(int));
    int i = 0;
    
    for(i=0; i<n; i++)
    {
        array[i] = i + 1;
    }
    
    for(i=0; i<n; i++)
    {
        ret += array[i];
    }
    
    free(array);
    
    return ret;
}

long sum2(int n)
{
    long ret = 0;
    int i = 0;
    
    for(i=1; i<=n; i++)
    {
        ret += i;
    }
    
    return ret;
}

long sum3(int n)
{
    long ret = 0;
    
    if( n > 0 )
    {
        ret = (1 + n) * n / 2;
    }
    
    return ret;
}

// 同样都是1+...+100 
// 不同的解决问题的方式来完成 有着好坏之分

int main()
{
    printf("%d\n", sum1(100));
    printf("%d\n", sum2(100));
    printf("%d\n", sum3(100));
    
    return 0;
}
