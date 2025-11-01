# **Module 2: Classes and object-oriented programming**

# Blackjack - SimpleGUI

**Short description:**  

A browser-style Blackjack (21) game implemented with the SimpleGUI API (as used in CodeSkulptor). The game deals cards from a shuffled deck, lets the player `Hit` or `Stand`, shows dealer behavior, tracks the running score, and renders card graphics loaded from an online sprite sheet.

---

## Features
- Full deck implementation with `Card`, `Hand` and `Deck` classes.  
- Correct Ace scoring (counts as 11 when it doesn't cause a bust).  
- Graphical card rendering using a sprite sheet; card-back shown for dealer when the round is in play.  
- Buttons: **Deal**, **Hit**, **Stand**, and **Restart** (resets score).  
- Score tracking and simple win/lose/bust logic.

---

## Files
- `Blackjack.py` — Code 

---

## How to run

1. Access the code in CodeSkulptor with the following link: https://py2.codeskulptor.org/#user52_fJ9XBHHj5G_3.py

**Note:** Cannot be run locally due to the `simplegui` library. The original `simplegui` API runs in the browser on CodeSkulptor.

---

## How it works

1. Classes

* `Card`: stores suit and rank and knows how to draw itself from the sprite sheet.
* `Hand`: stores a list of `Card` objects, can compute its Blackjack value (handles Aces).
* `Deck`: builds a standard 52-card deck, can shuffle and deal cards.

2. Gameplay

* `deal()` starts a round: if a round was already in play, the player loses the current round; a new shuffled deck and hands are created and two cards are dealt to player and dealer.
* `hit()` adds a card to the player's hand and checks for bust.
* `stand()` plays out the dealer: dealer keeps hitting while their hand value is `<= 17` (per current code), then compares values to assign win/lose and update score.
* `draw()` renders player and dealer hands on the canvas, shows outcome messages, current score and hides one dealer card while `in_play` is `True`.
* `restart()` resets the cumulative score to zero.
