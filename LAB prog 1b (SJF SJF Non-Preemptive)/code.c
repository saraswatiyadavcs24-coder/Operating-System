#include <stdio.h>

int main() {

    int n, at[20], bt[20], ct[20], wt[20], tat[20];
    int completed[20] = {0};
    int time = 0, done = 0;
    int i, min_index;
    float twt = 0, ttat = 0, awt, att;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter Arrival Time for P%d: ", i+1);
        scanf("%d", &at[i]);

        printf("Enter Burst Time for P%d: ", i+1);
        scanf("%d", &bt[i]);
    }

    while(done < n) {

        min_index = -1;

        for(i = 0; i < n; i++) {

            if(at[i] <= time && completed[i] == 0) {

                if(min_index == -1 || bt[i] < bt[min_index]) {
                    min_index = i;
                }

            }

        }

        if(min_index == -1) {
            time++;
        }

        else {

            ct[min_index] = time + bt[min_index];
            tat[min_index] = ct[min_index] - at[min_index];
            wt[min_index] = tat[min_index] - bt[min_index];

            time = ct[min_index];

            completed[min_index] = 1;
            done++;

            twt += wt[min_index];
            ttat += tat[min_index];
        }
    }

    awt = twt / n;
    att = ttat / n;

    printf("\nPROCESS\tAT\tBT\tCT\tWT\tTAT");

    for(i = 0; i < n; i++) {
        printf("\nP%d\t%d\t%d\t%d\t%d\t%d",
        i+1, at[i], bt[i], ct[i], wt[i], tat[i]);
    }

    printf("\n\nAverage Waiting Time = %.2f", awt);
    printf("\nAverage Turnaround Time = %.2f", att);

    return 0;
}
