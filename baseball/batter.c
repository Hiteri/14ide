#include <stdio.h>
#include <string.h>

int main(){
    char name[50], team[50];
    int atBats, hits, walks, doubles, triples, homeRuns, sacrificeFlies;

    printf("Name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;

    printf("Team: ");
    fgets(team, sizeof(team), stdin);
    team[strcspn(team, "\n")] = 0;

    printf("At-Bats (AB): ");
    scanf("%d", &atBats);

    printf("Hits (H): ");
    scanf("%d", &hits);

    printf("Walks (BB): ");
    scanf("%d", &walks);

    printf("Doubles (2B): ");
    scanf("%d", &doubles);

    printf("Triples (3B): ");
    scanf("%d", &triples);

    printf("Home Runs (HR): ");
    scanf("%d", &homeRuns);

    printf("Sacrifice Flies (SF): ");
    scanf("%d", &sacrificeFlies);

    int totalBases = (2 * doubles) + (3 * triples) + (4 * homeRuns);

    float AVG = (float)hits / atBats;
    float OBP = (float)(hits + walks) / (atBats + walks + sacrificeFlies);
    float SLG = (float)totalBases / atBats;
    float OPS = OBP + SLG;

    char buffer[20];

    sprintf(buffer, "%.3f", AVG);

    // imprime sem o zero inicial
    if (buffer[0] == '0')
        printf("%s\n", buffer + 1);
    else
        printf("%s\n", buffer);

    printf("\n--- Batting Stats ---\n");
    printf("Player: %s\n", name);
    printf("Team: %s\n", team);
    printf("AVG: %.3f\n", AVG);
    printf("OBP: %.3f\n", OBP);
    printf("SLG: %.3f\n", SLG);
    printf("OPS: %.3f\n", OPS);
    printf("Home runs: %d\n", homeRuns);

    return 0;
}