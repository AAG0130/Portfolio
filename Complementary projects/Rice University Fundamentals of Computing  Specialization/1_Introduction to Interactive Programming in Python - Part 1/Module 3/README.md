# **Module 3: Canvas, drawing, timers**

# Stopwatch Game — SimpleGUI

**Short description**  
A small interactive stopwatch game implemented using the SimpleGUI-style API. The objective is to stop the timer on whole seconds (i.e., when the tenths-of-second counter ends in zero). The GUI shows the elapsed time in `A:BC.D` format and a score `wins/tries` that increments when the player stops the timer on a whole second.

---

## Features
- Start / Stop / Reset controls.  
- Timer ticks every 0.1 seconds and displays time in `A:BC.D` (minutes:seconds.tenths).  
- Score tracking: `wins` counts successful stops on whole seconds; `tries` counts the number of valid stop attempts.  
- Minimal and dependency-light; originally designed for the CodeSkulptor SimpleGUI API.

---

## Files
- `stopwatch_game.py` — Code  

---

## How to run

1. Access the code in CodeSkulptor with the following link: https://py2.codeskulptor.org/#user52_eKZTrgbg58_1.py

**Note:** Cannot be run locally due to the `simplegui` library. The original `simplegui` API runs in the browser on CodeSkulptor.

---

## How it works

1. `format(t)` converts tenths-of-seconds (`t`) into the string format `A:BC.D`: minutes, two-digit seconds, and tenths.
2. `new_game()` (implicitly via start/stop/reset) manages global counters and picks the starting state.
3. `timer_handler()` increments the tenths-of-seconds counter every 0.1 seconds.
4. `start()`, `stop()`, `reset()` control the timer and update scoring:
  * On `stop()`, if the timer was running the code increments `tries`; if the tenths digit is zero (`n % 10 == 0`) it increments `wins`.
5. Draw handler renders the formatted time and the score `wins/tries`.
