//multi level feedback queue

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
		//printf("%s \n",Q[i].na);
		burst=burst+Q[i].bt;
	}
	int gant[burst];
	
	int start=Q[0].at;
	printf("Queue 1 : ROUND ROBIN SCHEDULING OF TIME QUANTUM =8");
	for(i=0;i<n;i++)
	{
		printf("\n\nProcess %s starts from %d ",Q[i].na,start);
		if(Q[i].at<=start)
		{
			if(Q[i].bt==qt)
			{
				start=start+qt;
				Q[i].rem=0;
			/*for(j=i;j<n-1;j++)
			{
				Q[i].at=Q[i+1].at;
				Q[i].bt=Q[i+1].bt;
				Q[i].rem=Q[i+1].rem;
				Q[i].pr=Q[i+1].pr;
				strcpy(Q[i].na,Q[i+1].na);
			}*/
			}
			if(Q[i].bt<qt)
			{
				start=start+Q[i].bt;
				Q[i].rem=0;
			}
			if(Q[i].bt>qt)
			{
				start=start+qt;
				Q[i].rem=Q[i].bt-qt;
			}
		}
		printf(" and ends on %d",start);
	}
	
	qt=16;
	printf("\n\nQueue 2 : ROUND ROBIN SCHEDULING OF TIME QUANTUM =16");
	for(i=0;i<n;i++)
	{
		if(Q[i].rem==0)
		{
			printf("\n\nProcess %s completed processing",Q[i].na);
			continue;
		}
		
		printf("\n\nProcess %s starts from %d ",Q[i].na,start);
		if(Q[i].at<=start)
		{
			if(Q[i].rem==qt)
			{
				start=start+qt;
				Q[i].rem1=0;
			}
			if(Q[i].rem<qt)
			{
				start=start+Q[i].rem;
				Q[i].rem1=0;
			}
			if(Q[i].rem>qt)
			{
				start=start+qt;
				Q[i].rem1=Q[i].rem-qt;
			}
			
		}
		
		printf(" and ends on %d",start);
	}
	
	printf("\n\nQueue 3 : FIRST COME FIRST SERVE ");
	for(i=0;i<n;i++)
	{
		if(Q[i].rem1==0)
		{
			printf("\n\nProcess %s completed processing",Q[i].na);
			continue;
		}
		
		printf("\n\nProcess %s starts from %d ",Q[i].na,start);
		if(Q[i].at<=start)
		{
			start=start+Q[i].rem1;
		}
		
		printf(" and ends on %d",start);
	}

}
