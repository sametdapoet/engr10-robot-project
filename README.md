# ENGR 10 Robot Project

ROBOTC programs for the VEX Cortex robot in the ENGR 10 robot project: turn off the red IR beacon, then carry the green IR beacon out of the arena.

ROBOTC setup: Robot → Platform Type → VEX 2.0 Cortex, Natural Language PLTW; communication mode USB Only.

## Week 1 (`week1/`)

| File | Task |
|------|------|
| `practice1_ramp_up.c` | Practice 1: motor speed 0 → max in about 10 s |
| `practice2_swing.c` | Practice 2: speed swings between forward max and reverse max |
| `practice3_bumper.c` | Practice 3: bumper (digital port 1) stops the motor, release reverses it |
| `motor_servo_check.c` | 4.1.4: motor back and forth, servo to a set number of degrees |

All Week 1 programs use the motor on port 1; the servo check assumes the servo on port 2.

## Week 2+

- `gotobeacon.c`: GOTO_BEACON sample program from the course (Week 2: load and test)
- `robot_project.c`: full run (Tasks 1–4), built on GOTO_BEACON
- `servo_center.c`: holds the press-arm servo (port 3) at the center (0) so the arm can be attached at the right angle
- `servo_angle_test.c`: steps the press arm (port 3) through servo positions to find the up and press values

### Robot wiring (from the team's working setup)

| Port | Device |
|------|--------|
| in1, dgtl10–12 | IR receiver board |
| dgtl3 | Front limit switch |
| port1 / port10 | Right / left drive motors (negative speed = forward on this robot) |
| port2 | Claw servo (holds the green beacon) |
| port3 | Press arm servo (presses the red beacon's button, then presses down on the green beacon to hold it while pulling) |

No bumper and no ultrasonic sensor. Task 4 pulls the green beacon backward to the estimated start position.

Before running the full program, calibrate the servo positions and measure `MAX_WHEEL_SPEED_CM_PER_SEC` and `TRACK_WIDTH_CM` (settings at the top of `robot_project.c`).

## Program logic flow

![Robot control program flowchart](docs/flowchart.png)

Source: `docs/flowchart.svg`.
