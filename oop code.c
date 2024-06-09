//Write a c program to simulate the CPU scheduling algorithm-First Come first Serve.
#include<stdio.h>
struct Process
{
    int process_id;
    int burst_time;
    int waiting_time;
    int turn_around_time;
};
int main()
{
    int n;
    printf("Enter the number of processes:");
    scanf("%d",&n);
    struct Process processes[n];
    printf("Enter the Burst time for each processes:\n");
    for(int i=0; i<n; i++)
    {
        processes[i].process_id=i+1;
        printf("Process %d: ", i + 1);
        scanf("%d",&processes[i].burst_time);
    }
    int total_waiting_time=0;
    int total_turn_around_time=0;

    processes[0].waiting_time=0;
    processes[0].turn_around_time=0;

    for(int i=1; i<n; i++)
    {
        processes[i].waiting_time=processes[i - 1].waiting_time + processes[i - 1].burst_time;
        // processes[i].turn_around_time= processes[i].waiting_time + processes[i].burst_time;
        total_waiting_time=total_waiting_time+processes[i].waiting_time;
        // total_turn_around_time=total_turn_around_time+processes[i].turn_around_time;
    }
    for(int i=0; i<n; i++)
    {
        processes[i].turn_around_time= processes[i].waiting_time + processes[i].burst_time;
        total_turn_around_time=total_turn_around_time+processes[i].turn_around_time;
    }

    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(int i=0; i<n; i++)
    {
        printf("P%d\t\t%d\t\t%d\t\t%d\n", processes[i].process_id,processes[i].burst_time, processes[i].waiting_time, processes[i].turn_around_time);
    }

    printf("\nAverage Waiting Time: %.2f\n", (float)total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turn_around_time / n);

    return 0;

}
