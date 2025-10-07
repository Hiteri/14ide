// batting.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_HITTERS 200
#define NAME_LEN 50
#define TEAM_LEN 30
#define FILENAME "batters.csv"

typedef struct {
    char name[NAME_LEN];
    char team[TEAM_LEN];
    int games;
    int at_bats;
    int runs;
    int hits;
    int doubles;
    int triples;
    int homeruns;
    int rbi;       // Runs Batted In
    int walks;
    int strikeouts;
    int stolen_bases;
    int hbp;       // Hit by pitch
    int sac_flies;
} Batter;

Batter roster[MAX_HITTERS];
int count = 0;

/* Helpers */
void chomp(char *s) { size_t n = strlen(s); if (n > 0 && s[n-1] == '\n') s[n-1] = '\0'; }

void input_string(const char *prompt, char *buffer, int len) {
    printf("%s", prompt);
    if (fgets(buffer, len, stdin)) chomp(buffer); else buffer[0] = '\0';
}

int input_int(const char *prompt) {
    int x; char buf[64];
    while (1) {
        printf("%s", prompt);
        if (!fgets(buf, sizeof(buf), stdin)) return 0;
        if (sscanf(buf, "%d", &x) == 1) return x;
        printf("Invalid number, try again.\n");
    }
}

/* Derived stats */
double batting_avg(const Batter *b) {
    return (b->at_bats > 0) ? (double)b->hits / b->at_bats : 0.0;
}

double obp(const Batter *b) {
    double denom = b->at_bats + b->walks + b->hbp + b->sac_flies;
    double num   = b->hits + b->walks + b->hbp;
    return (denom > 0) ? num / denom : 0.0;
}

/* Add batter */
void add_batter() {
    if (count >= MAX_HITTERS) { printf("Roster full!\n"); return; }
    Batter b = {0};
    input_string("Name: ", b.name, NAME_LEN);
    input_string("Team: ", b.team, TEAM_LEN);
    b.games = input_int("Games: ");
    b.at_bats = input_int("At-Bats: ");
    b.runs = input_int("Runs: ");
    b.hits = input_int("Hits: ");
    b.doubles = input_int("Doubles: ");
    b.triples = input_int("Triples: ");
    b.homeruns = input_int("Home Runs: ");
    b.rbi = input_int("RBIs: ");
    b.walks = input_int("Walks: ");
    b.strikeouts = input_int("Strikeouts: ");
    b.stolen_bases = input_int("Stolen Bases: ");
    b.hbp = input_int("Hit By Pitch: ");
    b.sac_flies = input_int("Sacrifice Flies: ");
    roster[count++] = b;
    printf("Batter added!\n");
}

/* Print batter */
void print_batter(const Batter *b, int idx) {
    printf("\n--- [%d] %s (%s) ---\n", idx, b->name, b->team);
    printf("G: %d  AB: %d  R: %d  H: %d  2B: %d  3B: %d  HR: %d  RBI: %d\n",
           b->games, b->at_bats, b->runs, b->hits, b->doubles, b->triples, b->homeruns, b->rbi);
    printf("BB: %d  SO: %d  SB: %d  HBP: %d  SF: %d\n",
           b->walks, b->strikeouts, b->stolen_bases, b->hbp, b->sac_flies);
    printf("AVG: %.3f  OBP: %.3f\n", batting_avg(b), obp(b));
}

void list_batters() {
    if (count == 0) { printf("No batters yet.\n"); return; }
    for (int i = 0; i < count; i++) print_batter(&roster[i], i);
}

/* Find */
int find_by_name(const char *name) {
    for (int i = 0; i < count; i++) if (strcasecmp(roster[i].name, name) == 0) return i;
    return -1;
}

void search_batter() {
    char name[NAME_LEN]; input_string("Search name: ", name, NAME_LEN);
    int idx = find_by_name(name);
    if (idx == -1) printf("Not found.\n");
    else print_batter(&roster[idx], idx);
}

void delete_batter() {
    char name[NAME_LEN]; input_string("Delete name: ", name, NAME_LEN);
    int idx = find_by_name(name);
    if (idx == -1) { printf("Not found.\n"); return; }
    for (int i = idx; i < count-1; i++) roster[i] = roster[i+1];
    count--; printf("Deleted.\n");
}

/* CSV Save/Load */
void save_to_file() {
    FILE *f = fopen(FILENAME, "w");
    if (!f) { perror("Save error"); return; }
    fprintf(f, "name,team,games,at_bats,runs,hits,2b,3b,hr,rbi,bb,so,sb,hbp,sf\n");
    for (int i=0;i<count;i++) {
        Batter *b = &roster[i];
        fprintf(f, "%s,%s,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",
                b->name,b->team,b->games,b->at_bats,b->runs,b->hits,
                b->doubles,b->triples,b->homeruns,b->rbi,
                b->walks,b->strikeouts,b->stolen_bases,b->hbp,b->sac_flies);
    }
    fclose(f);
    printf("Saved %d batters to %s\n", count, FILENAME);
}

void load_from_file() {
    FILE *f = fopen(FILENAME, "r");
    if (!f) return;
    char line[256]; count=0;
    fgets(line,sizeof(line),f); // skip header
    while (fgets(line,sizeof(line),f) && count<MAX_HITTERS) {
        Batter b={0};
        sscanf(line,"%49[^,],%29[^,],%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",
            b.name,b.team,&b.games,&b.at_bats,&b.runs,&b.hits,
            &b.doubles,&b.triples,&b.homeruns,&b.rbi,
            &b.walks,&b.strikeouts,&b.stolen_bases,&b.hbp,&b.sac_flies);
        roster[count++]=b;
    }
    fclose(f);
    if (count>0) printf("Loaded %d batters from %s\n", count, FILENAME);
}

/* Menu */
void menu() {
    printf("\nBatting Stats Manager\n");
    printf("1) Add batter\n2) List batters\n3) Search by name\n4) Delete batter\n5) Save to file\n6) Load from file\n7) Exit\n");
}

int main() {
    load_from_file();
    while (1) {
        menu();
        int c = input_int("Choose: ");
        switch(c) {
            case 1: add_batter(); break;
            case 2: list_batters(); break;
            case 3: search_batter(); break;
            case 4: delete_batter(); break;
            case 5: save_to_file(); break;
            case 6: load_from_file(); break;
            case 7: save_to_file(); printf("Goodbye.\n"); return 0;
            default: printf("Invalid.\n");
        }
    }
}