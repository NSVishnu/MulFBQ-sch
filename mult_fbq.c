#include<stdio.h>
#include<string.h>
#include<conio.h>
struct process
{
    char na[20];
    int at,bt,ft,tat,rem,rem1,pr,start,end;
    float ntat;
}Q[5],temp;
main()
{
    int f,r,n,i,j,tt=0,qt,t,burst=0;

    
    printf("Enter the no. of jobs:");
    scanf("%d",&n);
    for(r=0;r<n;r++)
    {
        printf("Enter process name :\n");
        scanf("%s",Q[r].na);
		printf("Enter the arrival time :\n");
        scanf("%d",&Q[r].at);
		printf("Enter burst time :\n");
        scanf("%d",&Q[r].bt);
		printf("Enter priority :\n");
		scanf("%d",&Q[r].pr);
    }
    qt=8;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(Q[i].at>Q[j].at)
            {
                temp=Q[i];
                Q[i]=Q[j];
                Q[j]=temp;
            }
		}
	}
	for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(Q[i].at==Q[j].at)
            {
                if(Q[i].pr>Q[j].pr)
				{
				temp=Q[i];
                Q[i]=Q[j];
                Q[j]=temp;
            	}
            }
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%s \n",Q[i].na);
		burst=burst+Q[i].bt;
	}
	int gant[burst];
	
	int start=Q[0].at;
	printf("Queue 1 : ROUND ROBIN SCHEDULING OF TIME QUANTUM =8");
