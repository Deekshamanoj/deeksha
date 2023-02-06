#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_jobs 100

struct job{
    int start_time;
    int end_time;
    int profit;
};

int compare(const void *a, const void *b){
    struct job *j1 = a;
    struct job *j2 = b;
    return j2->profit - j1->profit;
}

int main(){
    int n;
    printf("Enter the number of Jobs: ");
    scanf("%d", &n);

    struct job jobs[n];
    printf("Enter job start time, end time, and earnings:\n");
    for(int i=0; i<n; i++){
        scanf("%d%d%d", &jobs[i].start_time, &jobs[i].end_time, &jobs[i].profit);
    }

    qsort(jobs, n, sizeof(struct job), compare);

    int count=0, earnings=0, end_time=0;
    for(int i=0; i<n; i++){
        if(jobs[i].start_time >= end_time){
            count++;
            end_time = jobs[i].end_time;
           
        }
        else{
             earnings += jobs[i].profit;
        }
    }

    printf("The number of tasks and earnings available for others\nTask: %d\nEarnings: %d\n", n-count, earnings);

    return 0;
}