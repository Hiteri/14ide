#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PITCHERS 200
#define NAME_LEN 50
#define TEAM_LEN 30
#define FILENAME "pitchers.csv"

typedef struct {
    char name[NAME_LEN];
    char team[TEAM_LEN];
    int wins;
    int losses;
    int saves;
    double innings;
    int earned_runs;
    int hits_allowed;
    int walks;
    int strikeouts;
    int games;
} Pitcher;

Pitcher roster[MAX_PITCHERS];
int count = 0;

void chomp(char *s) {
    size_t n = strlen(s);
    if(n > 0 && s[n-1] == '\n') s[n-1] = '\0';
}

void input_string(const char *prompt, char *buffer, int len){
    printf("%s", prompt);
    if(fgets(buffer, len, stdin) == NULL){
        buffer[0] = '\0';
    }
    else{
        chomp(buffer);
    }
}

int input_int(const char *prompt) {
    double x;
    char buf[64];
    while(1){
        printf("%s", prompt);
        if(!fgets(buf, sizeof(buf), stdin)) return 0.0;
        if(sscanf(buf, "%lf", &x) == 1) return x;
        printf("Invalid number, try again.\n");
    }
}

double compute_era(const Pitcher *p) {
    if(p->innings <= 0.0) return 0.0;
    return (p->earned_runs * 9.0) / p->innings;
}

double compute_whip(const Pitcher *p) {
    if(p->innings <= 0.0) return 0.0;
    return ((double)(p->walks + p->hits_allowed)) / p->innings;
}

void add_pitcher() {
    if(count >= MAX_PITCHERS){
        printf("Roster full (name %d).\n", MAX_PITCHERS);
        return;
    }
    Pitcher p;
    memset(&p, 0, sizeof(Pitcher));
    input_string("Name: ", p.name, NAME_LEN);
    input_string("Team: ", p.team, TEAM_LEN);
    p.wins = input_int("Win: ");
    p.losses = input_int("Loses: ");
    p.saves = input_int("Saves: ");
    p.games = input_int("Games: ");
    p.innings = input_int("Innings pitched (use decimal): ");
    p.earned_runs = input_int("Earned runs: ");
    p.hits_allowed = input_int("Hits allowed: ");
    p.walks = input_int("Walks: ");
    p.strikeouts = input_int("Strikeouts: ");
    roster[count++] = p;
    printf("Pitcher added.\n");
}

void print_pitcher(const Pitcher *p, int idx) {
    printf("--- [%d] %s (%s)\n", idx, p->name, p->team);
    printf("W-L: %d-%d  Saves: %d  Games: %d\n", p->wins, p->losses, p->saves, p->games);
    printf("IP: %.2f  ER: %d  H: %d  BB: %d  K: %d\n",
           p->innings, p->earned_runs, p->hits_allowed, p->walks, p->strikeouts);
    printf("ERA: %.2f  WHIP: %.3f\n", compute_era(p), compute_whip(p));
}

void list_pitchers() {
    if(count == 0){
        printf("No pitchers in roster.\n");
        return;
    }
    for(int i = 0; i < count; ++i){
        print_pitcher(&roster[i], i);
    }
}

int find_by_name(const char *name) {
    for(int i = 0; i < count; ++i){
        if(strcasecmp(roster[i].name, name) == 0) return i;
    }
    return -1;
}

void search_pitcher() {
    char name[NAME_LEN];
    input_string("Enter name to search: ", name, NAME_LEN);
    int idx = find_by_name(name);
    if(idx == -1){
        printf("Pitcher not found.\n");
    }
    else{
        print_pitcher(&roster[idx], idx);
    }
}

void edit_pitcher() {
    char name[NAME_LEN];
    input_string("Enter name to edit: ", name, NAME_LEN);
    int idx = find_by_name(name);
    if(idx == -1){
        printf("Pitcher not found.\n");
        return;
    }
    Pitcher *p = &roster[idx];
    printf("Editing %s (leave blank to keep continue value)\n", p->name);

    char buf[128];

    printf("Current name: %s\nNew name: ", p->name);
    if(fgets(buf, sizeof(buf), stdin)){
        chomp(buf);
        if(strlen(buf) > 0) strncpy(p->name, buf, NAME_LEN);
    }

    printf("Current team: %s\nNew team: ", p->team);
    if(fgets(buf, sizeof(buf), stdin)){
        chomp(buf);
        if(strlen(buf) > 0) strncpy(p->team, buf, TEAM_LEN);
    }

    printf("Current wins: %d\nNew wins (blank to keep): ", p->wins);
    if(fgets(buf, sizeof(buf), stdin)){
        chomp(buf);
        if(strlen(buf) > 0) p->wins = atoi(buf);
    }

    printf("Current losses: %d\nNew losses (blank to keep): ", p->losses);
    if(fgets(buf, sizeof(buf), stdin)){
        chomp(buf);
        if(strlen(buf) > 0) p->losses = atoi(buf);
    }

    printf("Current saves: %d\nNew saves (blank to keep): ", p->saves);
    if(fgets(buf, sizeof(buf), stdin)){
        chomp(buf);
        if(strlen(buf) > 0) p->saves = atoi(buf);
    }

    printf("Current games: %d\nNew games (blank to keep): ", p->games);
    if(fgets(buf, sizeof(buf), stdin)){
        chomp(buf);
        if(strlen(buf) > 0) p->games = atoi(buf);
    }

    printf("Current innings: %.2f\nNew innings (blank to keep): ", p->innings);
    if(fgets(buf, sizeof(buf), stdin)){
        chomp(buf);
        if(strlen(buf) > 0) p->innings = atof(buf);
    }

    printf("Current earned runs: %d\nNew earned runs (blank to keep): ", p->earned_runs);
    if(fgets(buf, sizeof(buf), stdin)){
        chomp(buf);
        if(strlen(buf) > 0) p->earned_runs = atoi(buf);
    }

    printf("Current hits allowed: %d\nNew hits allowed (blank to keep): ", p->hits_allowed);
    if(fgets(buf, sizeof(buf), stdin)){
        chomp(buf);
        if(strlen(buf) > 0) p->hits_allowed = atoi(buf);
    }

    printf("Current walks: %d\nNew walks (blank to keep): ", p->walks);
    if(fgets(buf, sizeof(buf), stdin)){
        chomp(buf);
        if(strlen(buf) > 0) p->walks = atoi(buf);
    }

    printf("Current strikeouts: %d\nNew strikeouts (blank to keep): ", p->strikeouts);
    if(fgets(buf, sizeof(buf), stdin)){
        chomp(buf);
        if(strlen(buf) > 0) p->strikeouts = atoi(buf);
    }

    printf("Pitcher updated.\n");
}

void delete_pitcher() {
    char name[NAME_LEN];
    input_string("Enter name to delete: ", name, NAME_LEN);
    int idx = find_by_name(name);
    if(idx = -1){
        printf("Pitcher not found.\n");
        return;
    }
    for(int i = idx; i < count - 1; ++i) roster[i] = roster[i+1];
    count--;
    printf("Deleted.\n");
}

void save_to_file() {
    FILE *f = fopen(FILENAME, "w");
    if(!f){
        perror("Failed to open file for saving");
        return;
    }
    // header
    fprintf(f, "name,team,win,losses,saves,games,innings,earned_runs,hits_allowed,walks,strikeouts\n");
    for(int i = 0; i < count; ++i){
        Pitcher *p = &roster[i];
        // Note: we avoid commas inside names/teams for simplicity
        fprintf(f, "%s,%s,%d,%d,%d,%d,%.2f,%d,%d,%d,%d\n",
                p->name, p->team, p->wins, p->losses, p->saves, p->games,
                p->innings, p->earned_runs, p->hits_allowed, p->walks, p->strikeouts);
    }
    fclose(f);
    printf("Saved %d pitchers to %s\n", count, FILENAME);
}

void load_from_file() {
    FILE *f = fopen(FILENAME, "r");
    if(!f){
        // no file found: not an error
        return;
    }
    char line[512];
    // skip header
    if(!fgets(line, sizeof(line), f)) { fclose(f); return; }
    count = 0;
    while(fgets(line, sizeof(line), f) && count < MAX_PITCHERS){
        Pitcher p;
        memset(&p, 0, sizeof(Pitcher));
        // parse CSV fields (simple, expects no embedded commas)
        char *tok = strtok(line, ",");
        if(!tok) continue; strncpy(p.name, tok, NAME_LEN);
        tok = strtok(NULL, ","); if (!tok) continue; strncpy(p.team, tok, TEAM_LEN);
        tok = strtok(NULL, ","); if (!tok) continue; p.wins = atoi(tok);
        tok = strtok(NULL, ","); if (!tok) continue; p.losses = atoi(tok);
        tok = strtok(NULL, ","); if (!tok) continue; p.saves = atoi(tok);
        tok = strtok(NULL, ","); if (!tok) continue; p.games = atoi(tok);
        tok = strtok(NULL, ","); if (!tok) continue; p.innings = atof(tok);
        tok = strtok(NULL, ","); if (!tok) continue; p.earned_runs = atoi(tok);
        tok = strtok(NULL, ","); if (!tok) continue; p.hits_allowed = atoi(tok);
        tok = strtok(NULL, ","); if (!tok) continue; p.walks = atoi(tok);
        tok = strtok(NULL, ","); if (!tok) continue; p.strikeouts = atoi(tok);
        // remove newline from name/team if present
        chomp(p.name);
        chomp(p.team);
        roster[count++] = p;
    }
    fclose(f);
    if(count > 0) printf("Loaded %d pitchers from %s\n", count, FILENAME);
}

/* menu */
void menu() {
    printf("\nPitching Stats Manager\n");
    printf("1. Add pitcher\n");
    printf("2. List pitchers\n");
    printf("3. Search pitcher by name\n");
    printf("4. Edit pitcher\n");
    printf("5. Delete pitcher\n");
    printf("6. Save to file\n");
    printf("7. Load from file\n");
    printf("8. Exit\n");
}

int main(void) {
    load_from_file();

    while(1){
        menu();
        int choice = input_int("Choose an option: ");
        switch(choice){
            case 1: add_pitcher(); break;
            case 2: list_pitchers(); break;
            case 3: search_pitcher(); break;
            case 4: edit_pitcher(); break;
            case 5: delete_pitcher(); break;
            case 6: save_to_file(); break;
            case 7: load_from_file(); break;
            case 8: 
                printf("Saving before exit...\n");
                save_to_file();
                printf("Goodbye.\n");
                return 0;
            default:
                printf("Invalid option.\n");
        }
    }
    return 0;
}