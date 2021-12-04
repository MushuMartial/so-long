#include "so_long.h"
#include "mlx.h"

int main()
{
	void *mlx; 
	mlx = mlx_init();
	void *window; 
	window = mlx_new_window(mlx, 1000, 1000, "hello");
	mlx_loop(mlx);
	return (0);
}