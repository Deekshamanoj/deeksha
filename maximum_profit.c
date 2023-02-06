#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_jobs 100

//structure to store the start_time, end_time and profit
struct job{
    int start_time;
    int end_time;
    int profit;
};

//function to compare the profit of two jobs
int compare(const void *a, const void *b){
    struct job *j1 = a;
    struct job *j2 = b;
    return j2->profit - j1->profit;
}

int main(){
    int n;
    //asking user to enter the no of jobs
    printf("Enter the number of Jobs: ");
    scanf("%d", &n);

    struct job jobs[n];
    //asking user to enter details of different jobs
    printf("Enter job start time, end time, and earnings:\n");
    for(int i=0; i<n; i++){
        scanf("%d%d%d", &jobs[i].start_time, &jobs[i].end_time, &jobs[i].profit);
    }

//sorting the sort the profits which are compared in compare function
    qsort(jobs, n, sizeof(struct job), compare);

/* variables to store the no of task(count), earnings for other members and to store end time of current work */
    int count=0, earnings=0, end_time=0;
    // calculating the no of task and earnings for rest of members
    for(int i=0; i<n; i++){
        if(jobs[i].start_time >= end_time){
            count++;
            end_time = jobs[i].end_time;
           
        }
        else{
             earnings += jobs[i].profit;
        }
    }

// printing the final output
    printf("The number of tasks and earnings available for others\nTask: %d\nEarnings: %d\n", n-count, earnings);

    return 0;
}
