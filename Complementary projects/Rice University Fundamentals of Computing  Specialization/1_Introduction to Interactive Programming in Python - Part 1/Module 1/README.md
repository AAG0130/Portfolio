# **Module 1: Functions, Logic, Conditionals**

# Rock — Paper — Scissors — Lizard — Spock (RPSLS)

**Short description**  
A compact Python implementation of the expanded "Rock, Paper, Scissors, Lizard, Spock" game. The program maps each choice to a number, generates a random computer choice, compares the two using modular arithmetic, and prints the winner for several example rounds.

---

## Features
- Converts human-readable choices (`"rock"`, `"Spock"`, `"paper"`, `"lizard"`, `"scissors"`) to numeric codes and back.
- Generates a random computer move and determines the winner using a simple modulo-5 rule.
- Prints round-by-round results to the console.
- No external dependencies — runs with the Python standard library.

---

## Files
- `Rock_paper_scissors_lizard_Spock.py` — Code.

---

## Requirements
- Python 3.8+ recommended.
- No third-party packages required.

---

## How to run

### Option A - CodeSkulptor (online)

1. Access the code in CodeSkulptor with the following link: https://py2.codeskulptor.org/#user52_yo1WGR6Hlz_1.py

### Option B - Local

1. Save the code into a file, e.g. `Rock_paper_scissors_lizard_Spock.py`.
2. Run the script from the command line:

`python Rock_paper_scissors_lizard_Spock.py`

The script will execute a sequence of example games and print output similar to:

`Player chooses rock
Computer chooses scissors
Player wins!`

`Player chooses Spock
Computer chooses paper
Computer wins!`

---

## How it works

1. `name_to_number(name)` — maps a choice string to an integer:
  * 0: rock
  * 1: Spock
  * 2: paper
  * 3: lizard
  * 4: scissors
2. `number_to_name(number)` — inverse mapping.
3. `rpsls(player_choice)` — main round function:
  * Prints player's choice.
  * Converts it to a number.
  * Randomly picks a computer number with random.randrange(0,5).
  * Converts computer number back to a string and prints it.
  * Computes `(comp_number - player_number)` % 5:
    * results 3 or 4 → player wins
    * results 1 or 2 → computer wins
    * result 0 → tie
This modulo trick encodes the game's win/loss relationships compactly.
