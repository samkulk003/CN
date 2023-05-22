#include<stdio.h>
#include<stdlib.h>
char findclass(char str[])
{
    int i=0,j=1,ip;
    char arr[100];
    while(str[i]!='.')
    {
        arr[i]=str[i];
        i++;
    }
    i--;
    while(i>=0)
    {
    ip=ip+(arr[i]-'0')*j;
    j=j*10;
    i--;
    }
    if(ip>=1 && ip<=127)
        return 'A';
    else if(ip>=128 && ip<=191)
        return 'B';
    else if(ip>=192 && ip<=223)
        return 'C';
    else if(ip>=224 && ip<=239)
        return 'D';
    else if(ip>=240 && ip<=254)
        return 'E';
}
void seperate(char str[],char ipclass)
{
    int k,i,j,count;
    char network[32],host[32];
    for(k=0;k<12;k++)
        network[k]=host[k]='\0';
        printf("%s",network);
    if(ipclass=='A')
    {
         i=0;j=0;//imp
        while(str[j]!='.')
        {
            network[i]=str[j];
            i++;
            j++;
        }
        i=0;
        j++;

        while(str[j]!='\0')
        {
            host[i]=str[j];
            i++;
            j++;
        }
        printf("\nnetwork add is :%s.0.0.0 \nSubnet mask is : 255.0.0.0",network);

    }
    else if(ipclass=='B')
    {
        i=0;j=0;
        count=0;
        while(count<2)
        {
            network[i]=str[j];
            i++;j++;
            if(str[j]=='.')
                count++;

        }
        i=0;j++;
        while(str[j]!='\0')
            host[i]=str[j];
        printf("\nnetwork add is :%s.0.0 \nSubnet mask is : 255.255.0.0",network);

    }
    else if(ipclass=='c')
    {
         i=0;j=0;
        count=0;
        while(count<3)
        {
            network[i]=str[j];
            i++;j++;
            if(str[j]=='.')
                count++;

        }
        i=0;j++;
        while(str[j]!='\0')
            host[i]=str[j];

        printf("\nnetwork add is :%s.0 \nSubnet mask is : 255.255.255.0",network);

    }
    else
        printf("in class d and e ip is not divided in net and host and thee is no subnet mask");
}

void main()//imp
{
    int i;
    char str[32];
    char ipclass;
    printf("\nenetr ip address =");

    scanf("%s",str);
    //fgets(str,sizeof(str),stdin);
    //str[strcspn(str,"\n")]="\0";
    ipclass=findclass(str);
    printf("\n given ip addredd belongs to %c: ",ipclass);
    seperate(str,ipclass);
}
