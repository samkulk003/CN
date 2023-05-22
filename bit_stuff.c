#include<conio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
  int n,i,count=0,j=0;
  char data[100],arr[100];
  printf("\nenetr data");
  printf("\n");
  scanf("%s",data);
  int l=strlen(data);
  printf("%d", l);
  for(i=0;i<l;i++)
  {
      if(data[i]=='1')
      {
          count++;
          if(count==5)
          {
              arr[j]='1';
              arr[j+1]='0';
              count=0;//imp
              j++;
          }
          else
          {
              arr[j]=data[i];
          }
      }
      else
      {
          arr[j]=data[i];
          count=0;//imp
      }
      j++;

  }
  //arr[l+1]='\0';
  printf("\n");
  printf("%s", arr);
}
