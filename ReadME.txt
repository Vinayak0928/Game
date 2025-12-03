Overview

This project is a simple console-based lane-dodging game written in C for Windows. It uses keyboard input (_kbhit, getch), console cursor manipulation, and sound playback to provide an interactive experience.

The game features:

A player character that moves left and right across three lanes.

A falling obstacle that randomly appears in one of the lanes.

Background music (looping) and a collision sound effect.

Smooth screen refresh using a custom fast-clear method to reduce flicker.

File Breakdown

1. Header Files Used

<stdio.h>: Standard I/O.

<conio.h>: For non-blocking keyboard input.

<windows.h>: For cursor control, sleep, and console functions.

<stdlib.h> and <time.h>: For random obstacle placement.

<mmsystem.h>: For playing background and impact sound effects.

Core Components

1. Flicker-Free Display (clear_screen_fast)

Instead of using system("cls") (slow and flickers), the screen cursor is reset to (0,0) using:

COORD pos = {0, 0};
SetConsoleCursorPosition(h, pos);

This redraws the screen instantly and smoothly.

2. Game Variables

x: Player lane (0, 1, 2).

step: Represents obstacle vertical movement.

obstaclePos: Random lane for obstacle.

3. Input Handling

Non-blocking keyboard detection using _kbhit() and getch() allows real-time control.

Left Arrow → Lane -1

Right Arrow → Lane +1

Boundary checks prevent the player from leaving the 3-lane grid.

4. Drawing the Game

Each frame:

The top boundary is drawn.

A loop draws 10 vertical rows; one row may contain the obstacle.

The player is printed on the bottom row in their corresponding lane.

Character codes:

Obstacle = ASCII 1

Player = ASCII 6

5. Collision Logic

Collision occurs when:

The obstacle reaches the final row (step == 10).

AND the player is in the same lane.

When detected:

Background music stops.

Impact sound plays.

"GAME OVER" message displayed.

6. Sound System

Uses PlaySound() from Windows Multimedia API.

Background: looped using SND_LOOP and SND_ASYNC.

Impact: played once on collision.

7. Obstacle Reset

After falling past the player row, the obstacle resets:

New lane generated using rand() % 3.

step is reset to 0.

Performance Considerations

Uses efficient screen refresh (no screen flickering).

Sleep(120) controls game speed; adjusting this changes difficulty.

Sound is async, so it doesn’t block rendering.

