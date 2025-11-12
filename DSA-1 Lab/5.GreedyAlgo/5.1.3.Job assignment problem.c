#include <stdio.h>
#include <stdlib.h>

struct Job {
    int difficulty;
    int profit;
};

int compareJobs(const void *a, const void *b) {
    struct Job *jobA = (struct Job *)a;
    struct Job *jobB = (struct Job *)b;
    return jobA->difficulty - jobB->difficulty;
}

int compareWorkers(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Job *jobs = malloc(n * sizeof(struct Job));
    int *worker = malloc(m * sizeof(int));

    if (jobs == NULL || worker == NULL) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &jobs[i].difficulty);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &jobs[i].profit);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &worker[i]);
    }

    qsort(jobs, n, sizeof(struct Job), compareJobs);
    qsort(worker, m, sizeof(int), compareWorkers);

    long long totalProfit = 0;
    int maxProfitSoFar = 0;
    int jobIndex = 0;

    for (int i = 0; i < m; i++) {
        int workerAbility = worker[i];

        while (jobIndex < n && jobs[jobIndex].difficulty <= workerAbility) {
            if (jobs[jobIndex].profit > maxProfitSoFar) {
                maxProfitSoFar = jobs[jobIndex].profit;
            }
            jobIndex++;
        }
        
        totalProfit += maxProfitSoFar;
    }

    printf("%lld\n", totalProfit);

    free(jobs);
    free(worker);

    return 0;
}