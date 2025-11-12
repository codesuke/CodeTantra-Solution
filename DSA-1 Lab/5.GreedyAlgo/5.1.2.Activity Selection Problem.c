#include <stdio.h>
#include <stdlib.h>

struct Activity {
    int start;
    int end;
};

int compareActivities(const void *a, const void *b) {
    struct Activity *actA = (struct Activity *)a;
    struct Activity *actB = (struct Activity *)b;
    
    if (actA->end < actB->end) {
        return -1;
    } else if (actA->end > actB->end) {
        return 1;
    }
    
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    struct Activity *activities = malloc(n * sizeof(struct Activity));
    if (activities == NULL) {
        return 1; 
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &activities[i].start);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &activities[i].end);
    }

    qsort(activities, n, sizeof(struct Activity), compareActivities);

    int maxCount = 1;
    int lastFinishTime = activities[0].end;

    for (int i = 1; i < n; i++) {
        if (activities[i].start > lastFinishTime) {
            maxCount++;
            lastFinishTime = activities[i].end;
        }
    }

    printf("%d\n", maxCount);

    free(activities);
    return 0;
}