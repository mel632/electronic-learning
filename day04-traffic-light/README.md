# Day 04 — Traffic light

**Goal:** a traffic light cycle (green → yellow → red) driven by an Arduino Uno, built first in Tinkercad Circuits.

## Components

- Arduino Uno
- Breadboard
- 3 LEDs: green, yellow, red
- 3 × 220 Ω resistors
- Jumper wires

## Wiring

| LED | Arduino pin | Path |
| --- | --- | --- |
| Green | 2 | pin 2 → 220 Ω → LED → GND |
| Yellow | 3 | pin 3 → 220 Ω → LED → GND |
| Red | 4 | pin 4 → 220 Ω → LED → GND |

![Breadboard view](breadboard.png)

![Schematic view](schematic.png)

## How it works

Each LED has its own resistor to limit the current: with a red LED dropping about 2 V on 5 V, I = (5 − 2) / 220 ≈ 13.6 mA, under the ~20 mA limit of an Arduino pin.

The code switches one light on at a time: green for 5 s, yellow for 2 s, red for 5 s, then repeats. Each pin gets a name with `const int` (e.g. `const int GREEN = 2;`), so the code reads clearly and a wire change only needs one line edited.

## Problems and fixes

- **First version was a chase, not a traffic light:** each LED turned off for 1 s before the next one. A traffic light always has exactly one light on, with different durations.
- **LEDs didn't light in the simulation:** the resistors and LEDs were on opposite sides of the breadboard's central gap, which separates rows a–e from f–j. Fix: keep each branch on the same half and place each resistor across two different columns.

## What I learned

- The breadboard's central gap disconnects the two halves of each column.
- A resistor with both legs in the same connected strip is bypassed.
- In Tinkercad, hovering over a hole highlights everything connected to it, a quick way to check a circuit.
- Named constants (`const int`) make code easier to read and change.

## Next step

Add a pedestrian push button on pin 7 with a 10 kΩ pull-down resistor: pressing it switches the light to red.
