#include <stdio.h>

int main()
{
    int n,m;

    scanf("%d%d",&n,&m);

    int u[m],v[m];
    float p[m];

    for(int i=0;i<m;i++)
    {
        scanf("%d%d%f",
              &u[i],&v[i],&p[i]);
    }

    int start,end;

    scanf("%d%d",&start,&end);

    float prob[n];

    for(int i=0;i<n;i++)
        prob[i]=0.0;

    prob[start]=1.0;

    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(prob[u[j]]*p[j] > prob[v[j]])
                prob[v[j]]=prob[u[j]]*p[j];

            if(prob[v[j]]*p[j] > prob[u[j]])
                prob[u[j]]=prob[v[j]]*p[j];
        }
    }

    printf("%.5f",prob[end]);

    return 0;
}