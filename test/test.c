# include <mlx.h>

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
	i = -1;
	while (++i < 400)
		mlx_pixel_put(mlx_ptr, win_ptr, i, 2 * i, (255 << 16));
	mlx_loop(mlx_ptr);
	return (0);
}
