#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int i,j=0,c=0;
    printf("\nenter data");
    char word[100];
    scanf("\n%s",word);
    int n=strlen(word);
    printf("enter flag");
    char d;
    scanf("\n%c",&d);
    char arr[100];
    for(i=0;i<n;i++)
    {
      if(word[i]==d)
      {
          arr[j]='#';
          c++;
          arr[j+1]=word[i];
          j++;//imp
      }
      else
      {
          arr[j]=word[i];
      }
      j++;//imp

    }
    arr[n+c-1]='\0';
    printf("\nflag%sflag",arr);
}
