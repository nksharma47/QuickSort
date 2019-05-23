#include <stdio.h>

int partition(int a[],int low,int high)
{
    int i,j,key,temp;
    key=a[low];
    i=low+1;
    j=high;
    while(i<=j)
    {
        while(a[i]<key && i<=high)
            i++;
        while(a[j]>key)
            j--;
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    if(i>j)
    {
        temp=a[low];
        a[low]=a[j];
        a[j]=temp;
    }
    
    return j;
}

void q_sort(int a[10],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=partition(a,low,high);
        q_sort(a,low,mid-1);
        q_sort(a,mid+1,high);
    }
}

int main(void) 
{
    int a[10],n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    
    q_sort(a,0,n-1);
    
    printf("Sorted Array:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
	return 0;
}

