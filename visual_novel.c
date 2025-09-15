#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to clear the console screen (works on Windows and Unix OS)
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Function to display text slowly for dramatic effort
void printSlowly(const char *text, int delay) {
    for (int i = 0; text[i] != '\0'; i++){
        printf("%c", text[i]);
        fflush(stdout);
        // Simulate typing delay (in miliseconds)
        for (int j = 0; j < delay * 10000; j++);
    }
    printf("\n");
}

// Function to handle user input for choices
int getChoices(int maxChoices) {
    int choice;
    char input[100];
    do{
        printf("\nEnter your choice (1-%d): ", maxChoices);
        scanf("%s", input);
        choice = atoi(input);
        if(choice < 1 || choice > maxChoices){
            printf("Invalid choice! Please select a number between 1 and %d.\n", maxChoices);
        }
    } while(choice < 1 || choice > maxChoices);
    return choice;
}

void visualNovel() {
    clearScreen();
    printf("=== A Brief Encounter with Ado ===\n\n");
    printSlowly("You find yourself in a vibrant city at night, neon lights flickering around you", 500);
    printSlowly("A figure stands under a streetlamp, her long blue hair glowing faintly", 500);
    printSlowly("She turns on you, her eyes sharp yet curious. It's Ado, the enigmatic singer.", 500);
    printSlowly("Ado: 'Hey, you look like someone who gets it. Wanna hear a secret?'", 500);

    // First choice
    printf("\nWhat do you do?\n");
    printf("1. Nod eagerly and say, 'Tell me everything!'\n");
    printf("2. Shrug and reply, 'I'm not sure I'm ready for secrets.'\n");
    int choice1 = getChoices(2);

    clearScreen();
    if (choice1 == 1){
        printSlowly("Ado smirks, her voice lowering to a whisper", 500);
        printSlowly("Ado: 'The music I sing... it's more than sound. It's a spark that can change the world.'", 500);
        printSlowly("She hands you a glowing blue rose, its petals pulsing faintly.", 500);
        printSlowly("Ado: 'Keep this. It'll guide you when the time comes'", 500);
        printSlowly("You feel a surge of inspiration. The rose hums with potential", 500);
        printSlowly("=== Ending 1: The Spark of Inspiration ===\n", 500);
        printSlowly("You leave, determined to create something extraordinary.", 500);
    }
    else{
        printSlowly("Ado tilts her head, a faint smile on her lips.", 500);
        printSlowly("Ado: 'Fair enough. Not everyone is ready to dive into the unknown.'", 500);
        printSlowly("She waves and vanishes into the crowd, her voice echoing in your mind", 500);
        printSlowly("You walk away, wondering what could have been", 500);
        printSlowly("=== Ending 2: The Path Not Taken ===\n", 500);
        printSlowly("Life continues, but a spark of curiosity lingers.", 500);
    }

    printf("=== The End ===\n");
    printf("Press ENTER to exit...\n");
    getchar();
    getchar();
}

int main() {
    visualNovel();
    return 0;
}