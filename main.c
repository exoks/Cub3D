# include <unistd.h>
# include <mlx.h>
# include <stdio.h>


int	main(void)
{
	int	i;
	int	x, y;
	float x0, y0;

	x = 0;
	y = 0;
	i = 0;
	while (i < 100)
	{
		x0 = (((float) y) / 10.0f) / 2.0f;
		printf("Py = (%f, %f)\n", x0, (float) y / 10);
		y0 = 3.0f * ((float) x / 10.0f);
		printf("Px = (%f, %f)\n", ((float) x / 10.0f), y0);
		// unit = 10
		y += 10;
		x += 10;
		i += 10;
	}	
	return (0);
}


// I have the check these two points and decide where to stop the ray stop where min(y)
// to find the x0 we use the known method
// to find y0 all you need to do is calcul y since i know x y0 = a * x0 + b
//
// Understand DDA:
// it allow us to know the exact mouvment on x and y each time (value)
