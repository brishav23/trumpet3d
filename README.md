# Trumpet 3D

This is my attempt at creating a 3d object in a 2d space (the terminal), based on the math used for
[donut.c by Andy Sloane](https://www.a1k0n.net/2011/07/20/donut-math.html).
Instead of recreating a donut, my goal was to use Torricelli's Trumpet since it is a different 3D surface which did not have an existing example.

This made me ensure I could understand and apply the necessary math by myself and helped me gain a more
general understanding of 3d projections, vector interactions, and matrix transformations.


## The Process

The first thing I did was parameterize the surface of Torricelli's Trumpet, which is the graph of f(x) = 1/x rotated around the x-axis.
For this project, I used the y-axis as the rotation axis and parameterized the surface
using x = (1/y) * sin(theta), y = y, and z = (1/y) * cos(theta).
