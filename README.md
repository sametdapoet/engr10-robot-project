# ENGR 10 Robot Project

ROBOTC programs for the VEX Cortex robot in the ENGR 10 robot project: turn off the red IR beacon, then push the green IR beacon out of the arena.

- `robot_project.c`: full run (Tasks 1–4), built on the GOTO_BEACON sample
- `gotobeacon.c`: original GOTO_BEACON sample program from the course

## Wiring assumed by robot_project.c

| Port | Device |
|------|--------|
| in1, dgtl10–12 | IR receiver board |
| dgtl1 | Front limit switch |
| dgtl2 | Bumper switch |
| dgtl3–4 | Ultrasonic sensor (INPUT in dgtl3, OUTPUT in dgtl4) |
| port1 / port10 | Right / left drive motors |
| port2 | Arm motor (via Motor Controller 29) |

Tune the arm timings and Task 4 values at the top of `robot_project.c` on the real robot.
