#include<stdio.h>
struct proc{
    int pid;
    int at;
    int bt;
    int ct;
    int wt;
    int tat;
int prior;
};
int main(){
    printf("Enter the number of processes\n");
    int n;
    int m;
    scanf("%d",&n);
    struct proc p[n];
    printf("Enter all arrival times\n");
    for(int i=0;i<n;i++){
        scanf("%d",&m);
        p[i].at=m;
        p[i].pid=i;
    }
    /*for(int i=0;i<n;i++){
        printf("%d",p[i].at);
    }*/
    printf("Enter all burst times\n");
    for(int i=0;i<n;i++){
        scanf("%d",&m);
        p[i].bt=m;
    }
printf("Enter all the priorities\n");\
for(int i=0;i<n;i++)
{
scanf("%d",&p[i].prior);
}
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(p[j].prior-p[j+1].prior>0){
                struct proc x=p[j];
                p[j]=p[j+1];
                p[j+1]=x;
            }
            else if(p[j].prior-p[j+1].prior==0){
                if(p[j].at-p[j+1].at>0){
                    struct proc x=p[j];
                    p[j]=p[j+1];
                    p[j+1]=x;
                }
            }
        }
    }
    /*for(int i=0;i<n;i++){
        printf("%d",p[i].pid);
    }*/
    p[0].ct=p[0].at+p[0].bt;
    for(int i=1;i<n;i++){
        if(p[i].at<=p[i-1].ct)
            p[i].ct=p[i-1].ct+p[i].bt;
        else
            p[i].ct=p[i].at+p[i].bt;
    }
    double wtsum=0,tatsum=0;
    for(int i=0;i<n;i++){
        p[i].tat=p[i].ct-p[i].at;
        p[i].wt=p[i].tat-p[i].bt;
        wtsum+=p[i].wt;
        tatsum+=p[i].tat;
    }
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
    }
    printf("\nAverage TAT = %lf",tatsum/n);
    printf("\nAverage WT = %lf\n",wtsum/n);
}
