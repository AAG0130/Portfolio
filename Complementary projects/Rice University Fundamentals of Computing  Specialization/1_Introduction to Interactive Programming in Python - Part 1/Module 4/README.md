# **Module 4: Lists, keyboard input, the basics of modeling motion**

# Classic Pong - SimpleGUI

**Short description:**  

A minimal implementation of the classic Pong game using the SimpleGUI API (as in CodeSkulptor). Two paddles (W/S for left player, Up/Down for right player) try to bounce the ball past the opponent's paddle. Ball velocity increases slightly on paddle hit. Scores are shown on the screen.

---

## Features
- Two-player local game (keyboard controls):  
  - Left paddle: `W` (up), `S` (down)  
  - Right paddle: Up / Down arrow keys  
- Ball bounces off top/bottom walls, speeds up slightly when hitting a paddle.  
- Simple scoring and automatic respawn of ball on miss.  
- Lightweight: uses the SimpleGUI API (CodeSkulptor) or a local SimpleGUI wrapper.

---

## Files
- `Pong.py` — Code

---

## How to run

1. Access the code in CodeSkulptor with the following link: https://py2.codeskulptor.org/#user52_WR7a730krQ_4.py

**Note:** Cannot be run locally due to the `simplegui` library. The original `simplegui` API runs in the browser on CodeSkulptor.

---

## How it works

1. Global constants define canvas size, paddle dimensions and ball radius.
2. `spawn_ball(direction)` positions the ball in the middle and gives it a random initial velocity (left or right).
3. `draw(canvas)` updates ball and paddle positions each frame, draws the game elements, handles wall bounces, detects paddle collisions (and speeds up the ball), and updates scores on misses.
4. `keydown` / `keyup` handlers change paddle velocities.
5. `new_game()` resets scores and spawns a new ball.
