//fcfs
//disk scheduling
#include<stdio.h>
int main()
{
	int proc[20],bt[10],wt[10],tat[10],total_tat,total_wt,i,j,lim;
	printf("\nEnter no. of proccesses: ");
	scanf("%d", &lim);
	for(i=0;i<lim;i++)
	{
		printf("\nEnter proccess[%d]: ",i+1);
		scanf("%d", &proc[i]);
	}
	int n=sizeof proc /sizeof proc[0];
	wt[0]=0;
	//Waiting Time
	for(i=0;i<n;i++)
		wt[i]=bt[i-1]+wt[i-1];
	//TurnAroundTime
	for (i = 0; i < n ; i++)
		tat[i] = bt[i] + wt[i];
	printf("Processes Burst time Waiting time Turn around time\n");
	// Calculate total waiting time and total turn
	// around time
	for (i=0; i<n; i++)
	{
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		printf(" %d ",(i+1));
		printf("	 %d ", bt[i] );
		printf("	 %d",wt[i] );
		printf("	 %d\n",tat[i] );
	}
	int s=(float)total_wt / (float)n;
	int t=(float)total_tat / (float)n;
	printf("Average waiting time = %d",s);
	printf("\n");
	printf("Average turn around time = %d ",t);	
	return 0;
}
