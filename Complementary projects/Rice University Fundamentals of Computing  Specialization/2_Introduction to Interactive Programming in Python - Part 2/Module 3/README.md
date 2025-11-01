# **Module 3: Sets and animation**

# RiceRocks / Spaceship (Asteroids) — SimpleGUI

**Short description:**  

A full-featured browser-style "Spaceship / Asteroids" game (RiceRocks) implemented using the SimpleGUI API (in CodeSkulptor). The player controls a spaceship, fires missiles, avoids asteroids and earns points for destroying rocks. The program uses sprite sheets and sound assets loaded from remote URLs.

---

## Features
- Ship movement with rotation, thrust and inertia.  
- Missile firing and explosion animations.  
- Asteroid spawning with random positions, velocities and angular velocities.  
- Collision detection: ship vs rocks (loses life), missiles vs rocks (score).  
- Background animation using debris/nebula images and soundtrack / SFX.  
- Uses sprite sheets for graphics and supports animated explosions.  
- Minimal dependencies when run in CodeSkulptor (browser).

---

## Files
- `RiceRocks.py` — Code 

---

## How to run

1. Access the code in CodeSkulptor with the following link: https://py2.codeskulptor.org/#user52_mXJwwCY0SM_2.py

**Note:** Cannot be run locally due to the `simplegui` library. The original `simplegui` API runs in the browser on CodeSkulptor.

---

## How it works

1. `ImageInfo`, `Ship`, and `Sprite` classes encapsulate sprite metadata, ship logic and moving objects (rocks, missiles, explosions).
2. `process_sprite_group`, `group_collide`, `group_group_collide` manage updates/draws and collision logic for sets of sprites.
3. `rock_spawner` (timer) creates new asteroids periodically while the game is running.
4. Keyboard controls: left/right rotate, up toggles thrust, space fires missiles. Mouse click on splash screen starts the game.
5. Game state variables track `score`, `lives`, `started`, and background soundtrack playback.
