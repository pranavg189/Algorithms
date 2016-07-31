/* Google APAC Round A Problem B: Rain */
#include <cstdio>
#include <limits>
#include <algorithm>

using namespace std;


int R,C;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

bool isEdge(int i, int j)
{
    return (i == 0 || i == R-1 || j == 0 || j == C-1);
}

int main()
{
    freopen("B-large-practice.in","r", stdin);
    freopen("b-out.txt","w", stdout);

    int tc;
    scanf("%d",&tc);
    int casei=1;
    while(tc--)
    {

        scanf("%d%d",&R,&C);

        int H[R][C];

        for(int i=0; i < R;i++)
        {
            for(int j=0;j < C;j++)
            {
                scanf("%d", &H[i][j]);
            }
        }

        // Replace interior cells with Infinity
        int W[R][C];

        for(int i=0;i < R; i++)
        {
            for(int j=0;j < C;j++)
            {
                W[i][j] = isEdge(i,j) ? H[i][j] : numeric_limits<int>::max();
            }
        }

        for(int z=0; z<= (R*C); z++)
        {
            for(int i=0; i < R; i++)
            {
                for(int j=0; j < C;j++)
                {
                    if(!isEdge(i,j))
                    {
                        int min = numeric_limits<int>::max();

                        for(int k=0; k<4;k++)
                        {
                            int x = i + dx[k];
                            int y = j + dy[k];
                            min = std::min(min,W[x][y]);
                        }

                        W[i][j] = std::max(min, H[i][j]);
                    }
                }
            }
        }

        int total=0;
        for(int i=0; i < R;i++)
        {
            for(int j=0; j < C;j++)
            {
                total += W[i][j]-H[i][j];
            }
        }

        printf("Case #%d: %d\n", casei, total);
        casei++;
    }
    return 0;
}