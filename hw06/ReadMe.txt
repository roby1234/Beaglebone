To 	: Mr.Mark A Yoder

From 	: Onkar Singh(B13321)						

Date	: 5 Nov 2015

Subject	: Device Tree Overlays and Debian Releases

The P9_42 was configured to be an input pin, with a pull­up resistor by using a device tree overlay.
The dts file named 'os-gpio-set.dts' contains my dts edited for this homework.

The following steps were followed:

1) To set the variables, following commands were executed :

bone$ export SLOTS=/sys/devices/bone_capemgr.*/slots
bone$ export PINS=/sys/kernel/debug/pinctrl/44e10800.pinmux/pins
bone$ export PINMUX=/sys/kernel/debug/pinctrl/44e10800.pinmux/pinmux-pins
bone$ export PINGROUPS=/sys/kernel/debug/pinctrl/44e10800.pinmux/pingroups

2) To see which pins were unclaimed, execute the following command :

grep "(MUX UNCLAIMED) (GPIO UNCLAIMED)" $PINMUX

3) The available pins were displayed with their pin numbers by executing the following command

bone$ cd exercises/gpio
bone$ ./freeGPIO

4) We found information about P9_42 by running this:

bone$ ./findGPIO.js P9_16

5) Then we edited the .dts file and added this line:

0x164 0x37  /* P9_42 7  INPUT  MODE7 pullup */

6) The Overlay was made active by compiling the file.
	
For the next part, we explored stuff related to Debian Releases. This information is contained in 'jessie.txt'

