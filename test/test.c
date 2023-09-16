# include <mlx.h>
# include <stdio.h>

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		i, j;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 400, 400, "Title");

	i = 0;
	while (++i < 20)
	{
		j = -1;
		while (++j < 400)
		{
				mlx_pixel_put(mlx_ptr, win_ptr, j, i * 20, 255);
				mlx_pixel_put(mlx_ptr, win_ptr, i * 20, j, 255);
		}
	}
	float	x0, y0;

	x0 = 0;
	y0 = 0;
	i = -1;
	while (++i < 400)
	{
		x0 += 10;
		y0 += 5;
		if (x0 < 400)
			printf("P(%f, %f)\n", x0, y0);
		mlx_pixel_put(mlx_ptr, win_ptr, i, 2 * i, (255 << 16));
		if (i == 40 && 2 * i == 20)
			break ;
	}
	mlx_loop(mlx_ptr);
	return (0);
}
