#include<conio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
  int n,i;
  char arr[100][100],word[100][100];
  printf("\nenter no of frames");
  scanf("\n%d",&n);
  printf("\nenter no of frames");
  for(i=0;i<n;i++)
  {
  scanf("\n%s",word);
  strcpy(arr[i],word);
  char l[100];
  sprintf(l,"%d",strlen(arr[i]));
  //printf("\n%d",l);
  //printf("\n%d",arr[i]);
  strcat(l,arr[i]);
  strcpy(arr[i],l);
  }
  printf("\nprinting");
  printf("\n");
  for(i=0;i<n;i++)
  printf("%s\t",arr[i]);
}
