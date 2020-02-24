# E-Paper display high abstraction library.

This is a library which aims to simplify the graphic creation process for E-Paper display, providing an object oriented solution.
Thanks to the object oriented approach, each figure printed on the screen can be modified easily just modiying their properties, avoiding to create again from zero.
On the next list you can see which operations are available for each figure.

On the other hand, one of the weak point of the e-Paper Display is the slow refresh time. This library includes by default the proper configuration to achieve partial refresh with a maximum refresh speed of 20 mS from white to black, which translate in a **frame rate of up to 3 FPS**, allowing some simple animations.

At this moment, this library is only compatible with the **ESP32** and the E-Paper display WFT0420CZ15 which can be found on the next products:
- [Waveshare E-Paper 4.2](https://www.waveshare.com/wiki/4.2inch_e-Paper_Module)
- [Pimorini Inky What](https://www.adafruit.com/product/4142)

But this can be ported easily to any E-Paper display with partial refresh and any other microController with enough resources. I'm working into make it easy to port.

## Basic figures:
(All the operations can be set at build and run time.)

- Line:
    - Resize.
    - Change color.
    - Change angle orientation.
    - Change position.
    - Delete the figure and repaint without creating again the figure.
- Rectangule:
    - Resize on any axis.
    - Fill.
    - Change the line and background color.
    - Change the position.
    - Delete the figure and repaint without creating again the figure.
- Circle:
    - Resize.
    - Fill the circle.
    - Change the position.
    - Change the color
    - Delete the figure and repaint without creating again the figure.

## Images:

At this moment the image module can do the next features:
- Load easily images to screen space.
- Moves freely around the screen.
- Delete the image and repaint without creating again the image.

## Text:
The text ussage has been deeple inspired on the textBox ussage on interface creation programs so you can do the next operation on run time:
- Change the size of the string.
- Change the font of the text.
- Move freely around the screen.
- New line and return characters.
- Index font library.

## Examples:
You can find a set of examples on the [Examples folder](Examples).
This is a list of the available demos:
**WIP**

## TODO:

- [ ] Add more fonts.
- [ ] Improve hardware calls to make it more portable.
- [ ] Improve image handle, to obtain automatically the image size.
- [ ] Add examples.
- [ ] Compilation time image transform into hexadecimal, instead of external transforming.
- [ ] Compilation time fonts transforming.

## Apendix:
### Add a new image:
**WIP**
### Add a new font:
**WIP**

## Credits:

This library was base on the work performed by Waveshare. The original library can find on the next link: [Waveshare E-Paper library](https://github.com/waveshare/e-Paper)

