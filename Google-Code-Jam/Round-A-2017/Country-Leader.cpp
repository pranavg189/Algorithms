#include <cstdio>
#include <cstring>
#include <iostream>
#include <limits>

using namespace std;

int main()
{
    freopen("in.txt","r", stdin);
    freopen("out.txt","w", stdout);

    int tc;
    cin >> tc;
    int counter=1;

    while(tc--)
    {
        int n;
        cin >> n;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        int maxsize=0;
        char string[300];

        for(int i=0; i<n;i++)
        {
            int present[26]={0};
            char input[300];

            int size=0;
            int index=0;

            cin.getline(input, sizeof(input));

            for(int j=0; input[j]!='\0';j++)
            {
                if(present[input[j]-65] == 0 && input[j]!=' ')
                {
                    present[input[j]-65]=1;
                    size++;
                }
            }

            if(maxsize < size)
            {
                maxsize = size;
                strcpy(string, input);
            }
            else if(maxsize == size)
            {
                /* One way of checking the alphabetical order of string using std::min

                std::string minstring = min(std::string(string), std::string(input));
                strcpy(string, minstring.c_str());

                */

                /* Another way of checking alphabetical order using strcmp() */
                if(strcmp(input, string) < 0)
                {
                    strcpy(string, input);
                }

            }

        }

        printf("Case #%d: %s\n", counter, string);
        counter++;
    }
    return 0;
}