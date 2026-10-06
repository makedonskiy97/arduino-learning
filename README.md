# arduino-learning

Notes and resources for learning Arduino.

## Software

- [Arduino IDE](https://www.arduino.cc/en/software/) — official IDE for writing and uploading sketches

## Documentation

- [Arduino Language Reference](https://docs.arduino.cc/language-reference/) — functions, variables and structure
- [Arduino Built-in Examples](https://docs.arduino.cc/built-in-examples/) — ready-made sketches to start with

## Online Simulators

Try circuits without real hardware:

- [Tinkercad Circuits](https://www.tinkercad.com/circuits) — beginner-friendly, visual breadboard
- [Wokwi](https://wokwi.com) — fast simulator with support for many boards and sensors

## Linux: USB Port Permissions

If the IDE can't upload to the board (`Permission denied` on `/dev/ttyACM0` or `/dev/ttyUSB0`):

**Permanent fix (recommended)** — add your user to the `dialout` group, then log out and back in:

```bash
sudo usermod -aG dialout $USER
```

**Quick temporary fix** — resets after the board is reconnected or the system reboots:

```bash
sudo chmod a+rw /dev/ttyACM0
```

To find which port your board uses:

```bash
ls /dev/ttyACM* /dev/ttyUSB*
```
