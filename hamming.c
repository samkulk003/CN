#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include <stdio.h>
int ham[100],d_c[100],data[100];
void main()
{
    int n,p=0,i,j,c;
    printf("\nenter length of data");
    scanf("%d",&n);
    for(i=0;i<=n;i++)
    {
        c=(int)pow(2,i);
        //printf("%d",c);
        if(c>=(n+i-1))
        {
            p=i;
            //printf("%d",p);
            break;
        }
    }
    printf("\nthe no of parity bits arev :%d",p);
    printf("\nenter data");
    for(i=0;i<n;i++)
        scanf("%d",&data[i]);
    hamming(p,n);
    printf("\n");
    for(i=0;i<n+p;i++)
        printf("%d",ham[i]);
}

void hamming(int p,int n)
{
    int i,j=0,k;
    for(i=n-1;i>=0;i--)
    {
        d_c[j]=data[i];
        j++;
    }
    for(i=0;i<p;i++)
    {
        j=(int)pow(2,i);
        ham[j-1]=-1;
    }
    for(i=0,j=0;i<n+p;i++)
    {
        if(ham[i]!=-1)
        {
            ham[i]=d_c[j];
            j++;
        }
    }
    for(i=0,j=0;i<n+p;i++)
    {
        if(ham[i]==-1)
        {
            k=cal(i,(n+p));
            ham[i]=k;
        }
    }

}

int cal(int pos,int len)
{
    int i=pos,count=0,j;
    while(i<len)
    {
        for(j=i;j<=pos+i;j++)
        {
            if(ham[j]==1)
            count++;

        }
        i+=((pos+1)*2);

    }
    if(count%2==0)
        return 0;
    else
        return 1;
}
