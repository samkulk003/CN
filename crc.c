#include<conio.h>
#include<string.h>
#include<stdlib.h>
void crc_g(int data[],int g[],int n1,int n);
void crc_c(int crc[],int g[],int n1,int n);
int main()
{
    int i,j,n1,n,choice;
    printf("\nenter length of generating fn");
    scanf("%d",&n);
    int g[n];
    printf("\nenter  generating fn");
    for(i=0;i<n;i++)
    scanf("%d",&g[i]);


    do{
            printf("\nenter 1 to generate and 2 to check crc ");
    scanf("%d",&choice);

   if(choice==1){
        printf("\nenter length  data");
        scanf("%d",&n1);
        int data[n1];
        printf("\nenter  data");
        for(i=0;i<n1;i++)
         scanf("%d",&data[i]);
         crc_g(data,g,n1,n);
   }
   if(choice==2){
        printf("\nenter length  crc");
        scanf("%d",&n1);
        int crc[n1];
        printf("\nenter crc");
        for(i=0;i<n1;i++)
         scanf("%d",&crc[i]);
         crc_c(crc,g,n1,n);
   }
    if(choice==0)
        printf("exit");
    }while(choice!=0);

}
void crc_g(int data[],int g[],int n1,int n)
{
    int i,j,crc[n+n1],k;
    for(i=0;i<n1;i++)
    {
        crc[i]=data[i];
    }
    for(i=n1;i<n+n1-1;i++)
    {
        crc[i]=0;
    }
    for(i=0;i<n+n1-1;i++)
    printf("%d",crc[i]);
    printf("\n");
    for(i=0;i<n1;i++)
    {
        if(crc[i]==1)
        {
            for(j=i,k=0;j<i+n;j++,k++)//imp
            {
                crc[j]=(crc[j])^(g[k]);
            }
        }
        else
        {
            for(j=i;j<i+n;j++)//imp
            {
                crc[j]=(crc[j])^(0);//imp
            }

        }
    }
    for(i=0;i<n1;i++)
        crc[i]=data[i];
    printf("\ncrc:");
    for(i=0;i<n1+n-1;i++)
        printf("%d",crc[i]);
}
void crc_c(int crc[],int g[],int n1,int n)
{
  int i,j,data[n+n1],k,count=0;
    for(i=0;i<n1-n+1;i++)
    {
        data[i]=crc[i];
    }
    for(i=0;i<n-n+1;i++)
    printf("%d",crc[i]);
    printf("\n");
    for(i=0;i<n1-n+1;i++)
    {
        if(crc[i]==1)
        {
            for(j=i,k=0;j<i+n;j++,k++)
            {
                crc[j]=(crc[j])^(g[k]);
            }
        }
        else
        {
            for(j=i;j<i+n;j++)
            {
                crc[j]=(crc[j])^(0);
            }

        }
    }
    for(i=n1-n+1;i<n1;i++)
    {
        if(crc[i]==0)
            count++;
    }
    if(count==n-1)
    {
       printf("correct and data is :");
    for(i=0;i<n1-n+1;i++)
        printf("%d",data[i]);
    }

    else
        printf("error");


}
