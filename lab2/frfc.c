#include<stdio.h>

typedef struct pair{
int first,second;
}pair;



void sort(pair p[],int n){

int i,j;
for(i=0;i<n;i++){
for(j=i+1;j<n;j++){
if(p[i].first>p[j].first){
pair t=p[i];;
p[i]=p[j];
p[j]=t;
}
}
}

}

int main(){

printf("Enter the size of processes\n");
int n;
scanf("%d",&n);
pair p[n];
int i;
for(i=0;i<n;i++){
int a,b;
scanf("%d%d",&a,&b);
p[i].first=a;
p[i].second=b;
}
int ideal=0;
sort(p,n);
int bt[n];
for(i=0;i<n;i++)
bt[i]=p[i].second;

//wt[0]=0;    //waiting time for first process is 0
int wt[n],tat[n],avwt=0,avtat=0,j;
wt[0]=0;
    //calculating waiting time
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
    }

    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");

    //calculating turnaround time
    for(i=0;i<n;i++)
    {

        tat[i]=bt[i]+wt[i];
        avwt+=wt[i];
        avtat+=tat[i];
	int completion =  tat[i] + wt[i];
	
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d",i+1,bt[i],wt[i],tat[i]);
	printf("	Completion time = %d",completion);
    }

    avwt/=i;
    avtat/=i;
    printf("\n\nAverage Waiting Time:%d",avwt);
    printf("\nAverage Turnaround Time:%d",avtat);

}
