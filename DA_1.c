#include<stdio.h>
#include<stdlib.h>
int main()
{
int dist[10][10],sta[10],min[10],via[10];
int i,j,k,source,dest,amin,n,dd,t;
printf("Enter Number Of Nodes");
scanf("%d",&n);
printf("Enter Weights");
for(i=0;i<n;i++)
for(j=0;j<n;j++)
scanf("%d",&dist[i][j]);
for(i=0;i<n;i++)
            {
            sta[i]=0;
            min[i]=32767;
            }
printf("Enter Source AND Destination indexes");
scanf("%d%d",&source,&dest);
k=source;
amin=0;
while(sta[dest]!=2)
            {
                        sta[k]=2;
                        for(i=0;i<n;i++)
                        {
                                    if(dist[k][i]&&sta[i]!=2)
                                    {
                                                dd=amin+dist[k][i];

                                                if(dd<min[i])
                                                {
                                                            min[i]=dd;
                                                            via[i]=k;
                                                }
                                                sta[i]=1;
                                    }
                        }
                        amin=32767;
                        for(i=0;i<n;i++)
                       if(sta[i]==1 && min[i]<amin)
                        {
                                    amin=min[i];
                                    k=i;
                        }
            }
            printf("Shortest path between destination and source\n");
            printf("%d->",0+dest);
            for(k=via[dest];k!=source;k=via[k])
            printf("%d->",0+k);
            printf("%d",0+source);
            return 0;
}
