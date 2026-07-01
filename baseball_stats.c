#include <stdio.h>
#include <string.h>

#define MAX_PLAYERS 10
#define NAME_LEN 50
#define TEAM_LEN 10

// Structures
typedef struct {
    char name[NAME_LEN];
    char team[TEAM_LEN];
    int at_bats;
    int hits;
    int home_runs;
    int rbi;
    int walks;
} Batter;

typedef struct {
    char name[NAME_LEN];
    char team[TEAM_LEN];
    float innings_pitched;
    int earned_runs;
    int strikeouts;
    int walks;
    int hits_allowed;
} Pitcher;

// Math Calculation Helpers
float calculate_avg(int hits, int at_bats) {
    if (at_bats == 0) return 0.0f;
    return (float)hits / (float)at_bats;
}

float calculate_obp(int hits, int walks, int at_bats) {
    int plate_appearances = at_bats + walks;
    if (plate_appearances == 0) return 0.0f;
    return (float)(hits + walks) / (float)plate_appearances;
}

float calculate_era(int earned_runs, float innings_pitched) {
    if (innings_pitched == 0.0f) return 0.0f;
    return ((float)earned_runs * 9.0f) / innings_pitched;
}

float calculate_whip(int walks, int hits_allowed, float innings_pitched) {
    if (innings_pitched == 0.0f) return 0.0f;
    return (float)(walks + hits_allowed) / innings_pitched;
}

// Input Buffer Clear Helper
void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// String Input Helper (Removes Newlines)
void read_string(char *dest, int max_len) {
    fgets(dest, max_len, stdin);
    dest[strcspn(dest, "\n")] = '\0'; // Strip trailing newline character
}

// Formatting Output Functions
void print_batter_row(Batter b) {
    float avg = calculate_avg(b.hits, b.at_bats);
    float obp = calculate_obp(b.hits, b.walks, b.at_bats);

    printf("%-18s %-5s %-4d %-4d %-4d %-4d ", b.name, b.team, b.at_bats, b.hits, b.home_runs, b.rbi);

    if (avg < 1.0f) printf(".%-5.3d ", (int)(avg * 1000 + 0.5));
    else printf("%-6.3f ", avg);

    if (obp < 1.0f) printf(".%-5.3d\n", (int)(obp * 1000 + 0.5));
    else printf("%-6.3f\n", obp);
}

void print_pitcher_row(Pitcher p) {
    float era = calculate_era(p.earned_runs, p.innings_pitched);
    float whip = calculate_whip(p.walks, p.hits_allowed, p.innings_pitched);

    printf("%-18s %-5s %-5.1f %-4d %-4d %-5.2f %-4.2f\n", 
           p.name, p.team, p.innings_pitched, p.earned_runs, p.strikeouts, era, whip);
}

int main() {
    Batter batters[MAX_PLAYERS];
    Pitcher pitchers[MAX_PLAYERS];
    
    int batter_count = 0;
    int pitcher_count = 0;
    int choice = 0;

    while (1) {
        // Main Console Menu
        printf("\n====================================\n");
        printf("     BASEBALL DATABASE MANAGER      \n");
        printf("====================================\n");
        printf("1. Add a Hitter (Batter)\n");
        printf("2. Add a Pitcher\n");
        printf("3. Print Statistics Leaderboard\n");
        printf("4. Exit Program\n");
        printf("Enter your choice (1-4): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid selection. Try again.\n");
            clear_buffer();
            continue;
        }
        clear_buffer(); // Clear standard menu trailing newline

        if (choice == 1) {
            if (batter_count >= MAX_PLAYERS) {
                printf("Error: Batter database capacity reached!\n");
                continue;
            }
            Batter *b = &batters[batter_count];
            
            printf("\n--- Enter Batter Data ---\n");
            printf("Player Name: ");
            read_string(b->name, NAME_LEN);
            printf("Team (Abbreviation): ");
            read_string(b->team, TEAM_LEN);
            printf("At Bats (AB): ");
            scanf("%d", &b->at_bats);
            printf("Hits (H): ");
            scanf("%d", &b->hits);
            printf("Home Runs (HR): ");
            scanf("%d", &b->home_runs);
            printf("RBIs: ");
            scanf("%d", &b->rbi);
            printf("Walks (BB): ");
            scanf("%d", &b->walks);
            
            batter_count++;
            printf("Successfully added Hitter!\n");

        } else if (choice == 2) {
            if (pitcher_count >= MAX_PLAYERS) {
                printf("Error: Pitcher database capacity reached!\n");
                continue;
            }
            Pitcher *p = &pitchers[pitcher_count];

            printf("\n--- Enter Pitcher Data ---\n");
            printf("Player Name: ");
            read_string(p->name, NAME_LEN);
            printf("Team (Abbreviation): ");
            read_string(p->team, TEAM_LEN);
            printf("Innings Pitched (IP): ");
            scanf("%f", &p->innings_pitched);
            printf("Earned Runs (ER): ");
            scanf("%d", &p->earned_runs);
            printf("Strikeouts (SO): ");
            scanf("%d", &p->strikeouts);
            printf("Walks (BB): ");
            scanf("%d", &p->walks);
            printf("Hits Allowed: ");
            scanf("%d", &p->hits_allowed);

            pitcher_count++;
            printf("Successfully added Pitcher!\n");

        } else if (choice == 3) {
            // Print out accumulated databases
            printf("\n============================================================\n");
            printf("                 CURRENT BASEBALL DASHBOARD\n");
            printf("============================================================\n");

            printf("\n--- BATTING STATS ---\n");
            printf("%-18s %-5s %-4s %-4s %-4s %-4s %-6s %-6s\n", "Player", "Team", "AB", "H", "HR", "RBI", "AVG", "OBP");
            printf("------------------------------------------------------------\n");
            if (batter_count == 0) printf("[No batter records found]\n");
            for (int i = 0; i < batter_count; i++) {
                print_batter_row(batters[i]);
            }

            printf("\n--- PITCHING STATS ---\n");
            printf("%-18s %-5s %-5s %-4s %-4s %-5s %-4s\n", "Player", "Team", "IP", "ER", "SO", "ERA", "WHIP");
            printf("------------------------------------------------------------\n");
            if (pitcher_count == 0) printf("[No pitcher records found]\n");
            for (int i = 0; i < pitcher_count; i++) {
                print_pitcher_row(pitchers[i]);
            }
            printf("============================================================\n");

        } else if (choice == 4) {
            printf("Exiting database. Goodbye!\n");
            break;
        } else {
            printf("Invalid input options. Use options 1 through 4.\n");
        }
    }

    return 0;
}