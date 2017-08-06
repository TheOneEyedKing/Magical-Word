#include <stdio.h>
#include <string.h>
int abs(int x)
{
    if(x<0)
        return -x;
    else
        return x;
}
int main()
{
    int i,j,k,num[255],set[255],T,N;
    char word[500];
    scanf("%d",&T);
    for(i=0;i<255;i++)
        num[i]=i;
    //Sieve of Eratosthenes. Eliminating all composite number one by one
    for(i=2;i<255;i++)
    {
        for(j=i+1;j<255;j++)
        {
            if(num[i])
            {
                if(num[j]%num[i]==0)
                    num[j]=0;//Very important.
            }
        }
    }
    //TO make new array of only required prime nos.
    for(i=2,j=0;i<252;i++)
    {
        if(num[i]!=0&&((num[i]>=65&&num[i]<=90)||(num[i]>=97&&num[i]<=122)))
        {
            set[j]=num[i];
            j++;
        }
    }
    set[12]='\0';
    //Loop for main evaluation
    for(k=1;k<=T;k++)
    {
        scanf("%d",&N);
        scanf("%s",word);
        for(i=0;i<N;i++)
        {
            if((int)word[i]<set[0])
                    word[i]=(char)set[0];
            else if((int)word[i]>set[11])
                    word[i]=(char)set[11];
            else
            {
                for(j=0;j<12;j++)
                {
                    if((int)word[i]>set[j]&&(int)word[i]<set[j+1])
                    {
                        if(abs((int)word[i]-set[j])>abs((int)word[i]-set[j+1]))
                            word[i]=(char)set[j+1];
                        else if(abs((int)word[i]-set[j])<=abs((int)word[i]-set[j+1]))
                            word[i]=(char)set[j];
                    }
                }
            }

        }
        printf("%s\n",word);
    }
    return 0;
}
