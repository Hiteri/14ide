name = input("Enter the pitcher's name: ")

innings_pitched = float(input("Innings Pitched: "))
earned_runs = int(input("Earned Runs: "))
strikeouts = int(input("Strikeouts: "))
walks = int(input("Walks: "))
hits = int(input("Hits: "))

era = float(earned_runs * 9) / innings_pitched
whip = float(hits + walks) / innings_pitched

print("--- Pitching Stats ---")
print(f"Name: {name}" )
print(f"Strikeouts (K): {strikeouts}")
print(f"Walks (W): {walks}")
print(f"ERA: {era}")
print(f"WHIP: {whip:.3f}")