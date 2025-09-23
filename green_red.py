import time
import random

def play_game():
    print("Welcome to Green Light, Red Light!")
    print("When you see 'GREEN LIGHT!', press Enter as fast as you can.")
    print("If you press it too early, you lose.")
    time.sleep(3)

    game_running = True
    while game_running:
        # Wait for a random period before starting the round
        wait_time = random.uniform(2, 5)
        time.sleep(wait_time)

        start_time = time.time()
        print("\nGREEN LIGHT! GO!")

        # Wait for player input
        input("Press Enter to stop...")

        end_time = time.time()
        reaction_time = end_time - start_time

        if reaction_time <= 0.01: # Small grace period for instant reaction
            print(f"You stopped on 'RED LIGHT!' and were too fast! You lose!")
            game_running = False
        else:
            print(f"Your reaction time was: {reaction_time:.2f} seconds.")
            continue_playing = input("Play another round? (y/n): ")
            if continue_playing.lower() != 'y':
                game_running = False

    print("\nGame over. Thanks for playing!")

if __name__ == "__main__":
    play_game()