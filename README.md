# QUIK-Knobs
Welcome to the official repository for the PHOBOS QUIK-Knobs MIDI controller.

This is the first [PHOBOS Instruments](https://www.facebook.com/phobos.instruments/) release: the plans for _**QUIK**_, an open-source midi controller with 8 analog potentiometers, leveraging the capabilities of the Arduino Pro Micro.

Plans include the actual [code](https://github.com/phobos-instruments/QUIK-Knobs/blob/master/code/QUIK.ino) that makes the controller run, a laser cut [template](https://github.com/phobos-instruments/QUIK-Knobs/blob/master/assets/enclosure.svg) to realize the enclosure (with wood, plexiglass or whatever you like), and the [schematics](https://github.com/phobos-instruments/QUIK-Knobs/blob/master/assets/schematics.png) to wire it all up.

# Why QUIK?
The market of MIDI controllers is very saturated, and full of appliances the satisfy the all-around multimedia producer, or performer, with plenty of knobs, faders, buttons, and various sensors. The problem lies with the cost of these machines, the fact that their technology is usually proprietary and not very hackable, and the actual physical space that they occupy on your desk, which is often exaggerated, and awkward. This is the scenario where QUIK Knobs comes into place. We wanted to provide and easy-to-use, programmable, open-source, portable unit that would QUIKly satisfy the ever-lasting need of potentiometers in your life. QUIK Knobs is portable, plug-and-play, and ready to use as soon as you plug it in with your USB cable. The fact that QUIK is open-source might open plenty of possibilities for the programmers and for the engineers of tomorrow, giving plenty of space for improvement, and flexibility to reprogram the unit.

# What do I need to use QUIK?
You can download all the plans from our Github page, source the material necessary to build it, program it and mod it as you go. You can then just plug your micro-USB cable to your DAW of choice. It will work right out of the box, being class complaint, and it will work with any software supporting the MIDI protocol. You could use it to control your live sets (Ableton, Pd, Max), video sets (Resolume etc) or any other piece of software that needs a QUIK knob fix. In the next few months we will also provide kits to help you assemble the unit, as well as thorough instructions on how to program it, using Arduino boards. Specifically, we focused on the **ATmega32U4** chip as it provides native USB support, as well as giving us plenty of analog inputs to play ([see pic](https://i.stack.imgur.com/SEiwb.png)). We might consider building and shipping fully assembled units in the future.

# How to build QUIK?
The equipment used to build the first QUIK prototype included:
* [x8 10kΩ rotary resistors and knobs](https://amzn.to/3k9vBNa)
* [Baltic birch 3mm wood sheets](https://amzn.to/33n5P1l) (acrylic version coming out soon!)
* [Arduino Pro Micro](https://amzn.to/35uFa58)
* [Solder iron](https://amzn.to/33mGC7c) and solder wire
* [22 awg Solid Wire](https://amzn.to/2RlHK5f) of different colors (red, black and blue recommended)
* [Micro-USB cable](https://amzn.to/3kdsOCF)
* [K40 CO2 laser cutter](https://amzn.to/2ZtSumr)
* [Geeetech A20M 3D printer](https://amzn.to/35xCeFa) (optional)
* [Inkscape](https://inkscape.org/), [Fritzing](https://fritzing.org/) and [Arduino IDE](https://www.arduino.cc/en/main/software) software (they're all free)
* A few dreams, hours and boozes ❤️

# Requirements
Be sure to have the [MIDIUSB](https://www.arduino.cc/en/Reference/MIDIUSB) library installed, as well as the last version of the [Arduino IDE](https://www.arduino.cc/en/main/software). If you're laser cutting with a K40 laser engraver, the free software [K40 Whisperer](https://www.scorchworks.com/K40whisperer/k40whisperer.html) is recommended. [Inkscape](https://inkscape.org/) is recommended over Illustrator to edit the laser template because it's free and multiplatform.

# Software Instructions
* Install and open the [Arduino IDE](https://www.arduino.cc/en/main/software)
* Install the MIDIUSB library from *"Sketch->Include Library->Manage Libraries"*. Search for **"MIDIUSB"** and install the last version
* Be sure your Arduino Micro Pro is detected
* Under *"Tools->Board Manager"*, select **"Arduino Leonardo"**
* Upload and edit our [source code](https://github.com/phobos-instruments/QUIK-Knobs/blob/master/code/QUIK.ino) as you please

# Wiring Instructions
Every potentiometer will need 3 wires attached: **+5V**, **GND**, and **DATA**. You can connect all the +5V wires in **serial**, then attach it to the **VCC** pin of your board.
Do the same with all the **GND**, while every **DATA** cable will have their individual connection to the board. The Arduino Pro Micro will support up to 10 analog inputs. This is a brief table to resume the wiring situation. Please refer to the [wiring diagram](https://github.com/phobos-instruments/QUIK-Knobs/blob/master/assets/schematics.png) for further information.
INPUT | PIN
------------ | -------------
IN 1 | A0
IN 2 | A1
IN 3 | A2
IN 4 | A3
IN 5 | D4
IN 6 | D6
IN 7 | D8
IN 8 | D9

# Enclosure
The PHOBOS Instruments QUIK Knobs prototype's enclosure has been cut using baltic birch 3mm wood sheets. This type of wood is quite soft and easy to cut with an entry level laser cut such as the K40.

K40 Whisperer detects all the red strokes as levels to cut, blues to engrave, and blacks to raster engrave. As you will see from the template, the QUIK logo is a raster engrave, while all the other cuts and holes are vectorial cuts. We would recommend to engrave the raster first, and cutting last.

We have used the following settings to cut and engrave the QUIK Knobs:
* Raster engrave: Power: 10%, Speed: 100mm/s
* Vector cut: Power: 20%, Speed: 7mm/s (one pass)

**WARNING**: A CO2 laser cutter is not a toy, be sure to know how to use this device and never cut wood or similar material if you have not installed an air-assist mod. **This is very important as not having air assist in place might result into a fire hazard!!** Also, be sure to wear eye protection when using the laser.
