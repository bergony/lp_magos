# MAGOS

**Wellcome to MAGOS Project.**
This is a MAze GenaratOr Solve(MAGOS) Program: The magos creates an MAze on canvas build and solve is two way first Backtrack and left hand by your choice.


# Run

**Step 1: Make ./magos**

```
$ g++ -Wall -std=c++11 src/main.cpp src/canvas.cpp src/render.cpp src/build.cpp src/solve src/game_loop.cpp -I include/ -o magos
```

**Step 2: Run ./magos**

Dont forgot rows, colums, width and height.

```
$ ./keno data/bet.dat 40, 60, 1200, 800
```
Dont forgot rows(2x3), colums(3x2), width(100x100) and height(100x100).
lower configuration (2x3) or (3x2) and (100x100).

On class Build you can choose how much map can be random, if the map is to big
can take to long time to build because the cell are pick randomly to fix this
can set percent random to 40%.

Left-hand Solve on this setup the the alway will begin face the north and your left
hand on left every time them is not have free pass to front we will turn to clockwise.

**Step 4: Magos Running**

when magos start image will be creates on specific folder.

# Author
**Bergony Bandeira**

`Date 05/12/2018`



