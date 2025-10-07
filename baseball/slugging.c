#include <stdio.h>

int main() {
    int singles, doubles, triples, homeRuns, atBats;
    float slugging;

    printf("Enter singles: ");
    scanf("%d", &singles);

    printf("Enter doubles: ");
    scanf("%d", &doubles);

    printf("Enter triples: ");
    scanf("%d", &triples);

    printf("Enter home-runs: ");
    scanf("%d", &homeRuns);

    printf("Enter at bats: ");
    scanf("%d", &atBats);

    int totalBases = singles + (2 * doubles) + (3 * triples) + (4 * homeRuns);

    if(atBats > 0){
        slugging = (float)totalBases / atBats;
        printf("Slugging percentage: %.3f\n", slugging);
    }
    else{
        printf("At bats must be greater than 0.\n");
    }

    return 0;
}