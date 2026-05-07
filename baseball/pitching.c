#include <stdio.h>
#include <string.h>

int main(){
    char name[50];
    float inningsPitched, earnedRuns;
    int strikeouts, walks;

    printf("Name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;

    printf("Innings Pitched: ");
    scanf("%f", &inningsPitched);

    printf("Earned Runs: ");
    scanf("%f", &earnedRuns);

    printf("Strikeouts: ");
    scanf("%d", &strikeouts);

    printf("Walks: ");
    scanf("%d", &walks);

    float ERA = (earnedRuns * 9) / inningsPitched;

    printf("\n--- Pitching Stats ---\n");
    printf("Name: %s\n", name);
    printf("Strikeouts (K): %d\n", strikeouts);
    printf("Walks (W): %d\n", walks);
    printf("ERA: %.2f\n", ERA);
    

    return 0;
}