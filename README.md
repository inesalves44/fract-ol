# Fract-ol
## Overview

This is a repository for the 42 school project of fract-ol.
The point for this project is to create a program that renders different fractals.

### What is a fractal?

According to Wikipedia a fractal is: "In mathematics, a fractal is a geometric shape containing detailed structure at arbitrarily small scales, usually having a fractal dimension strictly exceeding the topological dimension".

Basically a fractal is a geometric figure with a never ending pattern. 

## Mandatory Part

For the mandatory part, the objective was to use mlx library to create, in a window the Mandelbrot set and the Julia set.

To run the mandatory part in the project directory write: make all.

The project runs like this:

```
./fractol FRACTAL
 ```
 
For the mandatory part for both fractals here are the options:

1) To change the window size run the program with iwNUMBER and ihNUMBER (in what order you want);
 ```
For example: ./fractol mandelbrot iw300 ih500
 ```
2) The mousewheel zooms in and out in the center;
3) ESC and the cross of the window closes the window.

### Mandelbrot Set
![Screenshot from 2023-02-14 19-55-05](https://user-images.githubusercontent.com/105734074/218847171-2d7cf226-61d6-489e-b853-774298a6e616.png)

Mathematical formula: f(z) = z² + C (iterating different values of C, which is a complex number)

### Julia Set
![Screenshot from 2023-02-14 19-57-07](https://user-images.githubusercontent.com/105734074/218847583-e9be9653-2ff2-437e-b724-b6255d745208.png)

Mathematical formula: f(z) = z² + C -> Here the C is constant.

For the Julia set you can also change the image by runing the program like this:
 
 ```
./fractol Julia cxNUMBER cyNUMBER -> the cx nuber should be between -2 and 1 and the cy should be between -1,5 and 1,5!
 ```

## Bonus

To compile the bonus: make bonus.

For the Bonus you can run the program only by: 
 
 ```
./fractol
 ```

Then this window will be displayed and you should input in the terminal one of the options (numbers or fractals).

![Screenshot from 2023-02-14 20-12-07](https://user-images.githubusercontent.com/105734074/218851111-6bd98990-665b-4d65-bf0d-f2555e2f40c5.png)

After reading the input from the terminal we have this prompt:

![Screenshot from 2023-02-15 19-58-06](https://user-images.githubusercontent.com/105734074/219139128-f4f69ea1-c7c5-41d0-ba58-1ac314c8ea08.png)

This window shows you the rendering options!

### Mandelbrot

![mandelbrot](https://user-images.githubusercontent.com/105734074/219144763-f38e5d2c-050b-4294-9b38-336a6e436090.gif)

zoom

### Julia 

![julia](https://user-images.githubusercontent.com/105734074/219143714-0f892836-7a08-4a55-af68-12a02da54a17.gif)

zoom + changing inputs and colors!

### Burning Ship

![bs](https://user-images.githubusercontent.com/105734074/219145772-2be9ce69-1cca-4653-b092-69d57c48a2f0.gif)

The Burning Ship is a fractal that works with the module of mandelbrot!

### Make Commands
```
make all - creates executable
make bonus - creates executable for bonus
make clean - clean the objects
make fclean - clean executable and any library, also runs clean
make re - runs clean and fclean and then runs all to create the executable
make rebonus - runs clean and fclean and then runs all to create the executable for bonus
 ```
 ## Links
 
 [Mandelbrot example](http://warp.povusers.org/Mandelbrot/)
 
 [Julia example](https://lodev.org/cgtutor/juliamandelbrot.html)
 
 [Minilibx](https://harm-smits.github.io/42docs/libs/minilibx)

Thanks for reading!!

idias-al
