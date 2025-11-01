# **Module 2: Event-driven programming, local/global variables**

# Guess the Number — SimpleGUI

**Short description:**  

A small interactive "Guess the Number" game implemented with the SimpleGUI-style API. The program provides two range buttons ([0,100) and [0,1000)) and an input field for the player to guess a secret number. The game prints messages and remaining guesses to the console and automatically restarts when the player wins or runs out of attempts.

---

## Features
- Two selectable ranges: `[0, 100)` (7 guesses) and `[0, 1000)` (10 guesses).  
- Text input for entering guesses.  
- Console output that reports the player's guess, hints ("Higher"/"Lower"), remaining attempts and when the game restarts.  
- Minimal, dependency-light implementation intended for SimpleGUI (CodeSkulptor) or a local SimpleGUI-compatible wrapper.

---

## Files
- `guess_the_number.py` — Code

---

## How to run

1. Access the code in CodeSkulptor with the following link: https://py2.codeskulptor.org/#user52_j2abej0GVq_2.py

**Note:** Cannot be run locally due to the `simplegui` library. The original `simplegui` API runs in the browser on CodeSkulptor.

---

## How it works

1. `new_game()` initializes the secret number (random within the selected range) and sets the allowed number of guesses (`n`) depending on range.

2. `range100()` and `range1000()` switch between the two predefined ranges and restart the game.

3. `input_guess(guess)` handles a player's guess:

  * Decrements the remaining guesses.
  * Converts input to integer and compares to the secret number.
  * Prints hints ("Higher"/"Lower"), remaining guesses, or the win/lose messages.
  * Automatically restarts the game on win or when guesses run out.
