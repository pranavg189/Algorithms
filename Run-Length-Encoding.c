/* Problem:

Given an input string, write a function that returns the Run Length Encoded string for the input string.

For example, if the input string is “wwwwaaadexxxxxx”, then the function should return “w4a3d1e1x6″.

*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_LENGTH 50

char *encode(char *src)
{
        int rlen; /*Running length of the variable*/
        int len = strlen(src);
        int count[MAX_LENGTH];

        char *dest = (char*)malloc(sizeof(char)*(2*len+1)); /* max length of dest string can be twice the length of original string */

        int i,j=0,k=0;
        for(i=0;i<len;i++)
        {
            dest[j]=src[i];
            j++;

            rlen=1;
            while(i+1<len && str[i]==str[i+1])
            {
                rlen++;
                i++;
            }

        }
}
