# Prerequisites
* Xlib headers
* ttf-font-awesome - Provides pretty icons for each module
* mpc - Prints song artist & title if mpd is installed and configured
* pulsemixer - Prints volume levels
* freetype2 - Ensures that font-awesome glyphs display correctly.

# Installation
`cd` into the slstatus folder, then run `sudo make clean install`. If using xinit, ensure that a line containing `slstatus &` is added to .xinitrc before `exec <WM>`.
