# **Module 1: Mouse input, list methods, dictionaries**

# Memory (Concentration) — SimpleGUI

**Short description:**  

A small interactive implementation of the classic Memory (Concentration) card game using the SimpleGUI API. The game presents 16 face-down cards (8 pairs). Click two cards to reveal them; matching pairs stay exposed. The game counts turns and lets you reset to start a new shuffled game.

---

## Features
- 16-card board (8 pairs) shuffled each game.  
- Click-to-reveal interaction via mouse clicks.  
- Turn counter displayed in the UI.  
- Simple visual representation: face-down cards (green) and revealed values (white text).  
- Minimal dependencies — originally designed for the CodeSkulptor SimpleGUI environment.

---

## Files
- `Memory.py` — Code

---

## How to run

1. Access the code in CodeSkulptor with the following link: https://py2.codeskulptor.org/#user52_QrJWBLYbOj_3.py

**Note:** Cannot be run locally due to the `simplegui` library. The original `simplegui` API runs in the browser on CodeSkulptor.

---

## How it works

1. The deck is represented as a list of integers (`card_deck`) containing two copies of values `0...7`; it is shuffled on `new_game()`.
2. `exposed` is a boolean list tracking which cards are revealed.
3. The `mouseclick(pos)` handler interprets the horizontal coordinate to figure out which card index was clicked (`pos[0] // 50`), updates game `state` (0,1,2) and the counter (turns), and implements matching logic: when two cards have been revealed, non-matching cards are flipped back on the next click.
4. The `draw(canvas)` handler renders either a green face-down rectangle or the revealed card value (as text). The label shows the number of turns taken.
