// Google Code Jam : Qualification Round 2016
// Problem A: Counting Sheep

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc,n,d;
    set<int> S;
    int result;
    int j=1;

    scanf("%d", &tc);

    while(tc--)
    {
        int n;
        int found=0;

        scanf("%d",&n);

        S.clear();

        if(n==0)
        {
            printf("Case #%d: INSOMNIA\n",j);
            j++;
            continue;
        }

        int k=1;
        int l=n;
        while(true)
        {

            int temp=l;
            while(temp)
            {
                d = temp % 10;
                S.insert(d);
                temp = temp/10;
            }

            for(int i=0;i<=9;i++)
            {
                if(S.find(i) != S.end())
                {
                    found=1;
                }
                else
                {
                    found = 2;
                    break;
                }
            }


            if(found==1)
            {
                break;
            }
            else
            {
                k++;
                l=n*k;
            }
        }

        printf("Case #%d: %d\n",j,l);
        j++;

    }

    return 0;
}
