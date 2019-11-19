#include "ft_printf.h"
#include "./libft/libft.h"

int main(void)
{
	int nombre = 42000;
	int nbr = 45226987;
	char test[] = "Coucou";
	char car = 'f';
	void	*p = &nbr;
	int	hexa = 42;
	unsigned int max = 4294967295;
	int i = 0;
	int j = 0;

	//i = ft_printf("coucou je suis %10.15d une phrase%-9.8d je me call %.3s et %.5s avec un %c et 42 en hexa : %.10X et %.90u et pour l'adresse de p : %p et je test cela : %% \n", nombre, nbr, p, p, car, hexa, max, p);

	//j = printf("coucou je suis %10.15d une phrase%-9.8d je me call %.3s et %.5s avec un %c et 42 en hexa : %.10X et %.90u et pour l'adresse de p : %p et je test cela : %% \n", nombre, nbr, p, p, car, hexa, max, p);

	//ft_printf("\nMon ft_printf return : %d\n", i);
	//ft_printf("le printf return : %d\n", j);
	
	i = ft_printf("WYASg%-12c06ygRp:%0*X:1E", 'S', -10, 2147483647);
	printf("\n");
	j = printf("WYASg%-12c06ygRp:%0*X:1E", 'S', -10, 2147483647);

	//ft_printf("-- %d --\n", ft_printf("b1RbhVqT5\n"));
	//printf("-- %d --\n", ft_printf("b1RbhVqT5\n"));
    //ft_printf("-- %d --\n", ft_printf("HMu\n"));
    //printf("-- %d --\n", ft_printf("HMu\n"));
    //ft_printf("-- %d --\n", ft_printf("%-8.*u%016X%0uL7Sg E7\n", -5, 0, -2147483647, 2147483647));
    //printf("-- %d --\n", ft_printf("%-8.*u%016X%0uL7Sg E7\n", -5, 0, -2147483647, 2147483647));
    //ft_printf("-- %d --\n", ft_printf("%-1.2uNetv2jgnM\n", 0));
    //printf("-- %d --\n", ft_printf("%-1.2uNetv2jgnM\n", 0));
    //ft_printf("-- %d --\n", ft_printf("Jh%1s%4.5irliU%%%.4dds6%c\n", NULL, -1963413025, -1616692938, 's'));
    //printf("-- %d --\n", ft_printf("Jh%1s%4.5irliU%%%.4dds6%c\n", NULL, -1963413025, -1616692938, 's'));
    //ft_printf("-- %d --\n", ft_printf("%1sy6bNm\n", "\n"));
    //printf("-- %d --\n", ft_printf("%1sy6bNm\n", "\n"));
	
	//ft_printf("%0*i\n", 8, 0);
	//printf("%0*i\n", 8, 0);
	
	printf("\nMon ft_printf return : %d\n", i);
	printf("le printf return : %d\n", j);
	return (0);
}
