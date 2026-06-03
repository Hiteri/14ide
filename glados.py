import random

reputation = 50

# Personality states
personalities = {
    "friendly": {
        "correct": [
            "Correct. Nicely done.",
            "That was actually impressive.",
            "You may be learning."
        ],
        "wrong": [
            "Not quite, but keep trying.",
            "Science believes in second chances.",
            "That answer requires improvement."
        ]
    },

    "normal": {
        "correct": [
            "Correct. This is unusual.",
            "Excellent. Don't get used to it.",
            "That answer appears to be right."
        ],
        "wrong": [
            "Incorrect. Predictable.",
            "I've seen potatoes score higher.",
            "Science is disappointed."
        ]
    },

    "hostile": {
        "correct": [
            "Correct. Against all odds.",
            "Remarkable. You accidentally succeeded.",
            "I expected failure."
        ],
        "wrong": [
            "Wrong. Spectacularly wrong.",
            "The walls are judging you.",
            "You continue to lower expectations."
        ]
    }
}

def get_personality():
    if reputation >= 80:
        return "friendly"
    elif reputation >= 40:
        return "normal"
    else:
        return "hostile"

def respond(correct):
    personality = get_personality()

    if correct:
        print("\nGLaDOS:",
              random.choice(personalities[personality]["correct"]))
    else:
        print("\nGLaDOS:",
              random.choice(personalities[personality]["wrong"]))

def show_status():
    print("\n----------------------")
    print("Reputation:", reputation)
    print("Personality:", get_personality().upper())
    print("----------------------")

while True:

    show_status()

    print("\nAPERTURE TEST CHAMBERS")
    print("1 - Math Chamber")
    print("2 - Logic Chamber")
    print("3 - Memory Chamber")
    print("4 - Reputation Report")
    print("5 - Exit")

    choice = input("\nSelect chamber: ")

    # Chamber 1
    if choice == "1":

        answer = input("\nWhat is 18 + 24? ")

        if answer == "42":
            reputation += 10
            respond(True)
        else:
            reputation -= 10
            respond(False)

    # Chamber 2
    elif choice == "2":

        answer = input(
            "\nWhich number is larger, 150 or 105? ")

        if answer == "150":
            reputation += 10
            respond(True)
        else:
            reputation -= 10
            respond(False)

    # Chamber 3
    elif choice == "3":

        print("\nRemember this number:")
        print("731")

        input("Press Enter when ready...")

        answer = input("What number did you see? ")

        if answer == "731":
            reputation += 15
            respond(True)
        else:
            reputation -= 15
            respond(False)

    elif choice == "4":

        print("\n===== PERFORMANCE REPORT =====")
        print("Current Reputation:", reputation)

        if reputation >= 80:
            print("Assessment: Competent Test Subject")
        elif reputation >= 40:
            print("Assessment: Average Test Subject")
        else:
            print("Assessment: Scientific Liability")

    elif choice == "5":

        print("\n===== FINAL REPORT =====")

        if reputation >= 100:
            print(
                "GLaDOS: You have exceeded expectations. This concerns me."
            )

        elif reputation >= 50:
            print(
                "GLaDOS: Acceptable performance. Barely."
            )

        else:
            print(
                "GLaDOS: Your participation has harmed science."
            )

        break

    else:
        print("\nGLaDOS: Even selecting a menu option proved challenging.")