#include<stdio.h>
int main()
{
	//disk scheduling-SCAN
	int counter=0,pos=0,i,n,m,j,a[10],temp,head,c;
	printf("\nEnter no. of cylinders: ");
	scanf("%d", &m);
	printf("\nEnter no. of requests: ");
	scanf("%d", &n);
	printf("\nEnter request queue: ");
	for(i=0;i<n;i++)
	{
		scanf("%d", &a[i]);
		if(a[i]>=m)
		{
			printf("\nInvalid Input\nEnter again: ");
			scanf("%d", &a[i]);
		}
	}
	printf("\nScheduling Service The Request In The Order That Follows: ");
	for(i=0;i<n;i++)
		for(j=0;j<n-i-1;j++)
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
	for(i=0;i<n;i++)
		if(a[i]<head)		//Head is the pointing variable that holds the index value
			pos++;
	for(i=0;i<pos;i++)
		for(j=0;j<pos-i-1;j++) //pos is the curent position of the head
			if(a[j]<a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
			temp=head;
	printf("%d\t", temp);
	for(i=0;i<pos;i++)
	{
		c=a[i]-temp;
		if(c<0)
			counter=c*-1;
		else
			counter=c;
		temp=a[i];
		printf("\n%d\t", temp);
	}
	c=temp;
		if(c<0)
			counter=c*-1;
		else
			counter=c;
	temp=0;
	printf("%d\t", temp);
	for(i=pos;i<n;i++)
	{
		c=a[i]-temp;
		if(c<0)
			counter+=c*-1;
		else
			counter+=c;
		temp=a[i];
		printf("%d\t", temp);
	}
	printf("\nTotal Head Movement: %d Cylinders.", counter);
	return 0;
}