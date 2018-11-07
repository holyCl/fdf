# fdf
A simple 3D height-map renderer. You can rotate models and zoom models.

### What is fdf?
fdf (which stand for "fil de fer" in French or Wire frame) is the first graphic project in UNIT Factory(42) using minilibx (Minilibx is a very basic graphical library writting in C).

The program take a map as arguments which content different number as their height and render it in 3D.
Mandatory part is **just** rendering and expose hook. All the other features are bonus.

### Features:
 - *Rotation arrows*
 - *Zoom in "+"   Zoom out "-"*
 - *Height modification*

 ### Compiling and running:

 Run `make`. An executable will compile. Currently only tested on OS X.

 Run it with `./fdf [map]`. A bunch of sample maps are provided in the `maps`
 directory.

 Example (./fdf maps/42.fdf ):

    0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
    0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
    0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0
    0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
    0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
    0  0 10 10 10 10 10 10  0  0  0  0 10 10 10 10  0  0  0
    0  0  0 10 10 10 10 10  0  0  0 10 10  0  0  0  0  0  0
    0  0  0  0  0  0 10 10  0  0  0 10 10  0  0  0  0  0  0
    0  0  0  0  0  0 10 10  0  0  0 10 10 10 10 10 10  0  0
    0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
    0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
