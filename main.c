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

	//i = ft_printf("coucou je suis %d une phrase%d je me call %.3s et %.5s avec un %c et 42 en hexa : %.10X et %.90u et pour l'adresse de p : %p et je test cela : %% \n", nombre, nbr, test, test, car, hexa, max, p);

	//j = printf("coucou je suis %d une phrase%d je me call %.3s et %.5s avec un %c et 42 en hexa : %.10X et %.90u et pour l'adresse de p : %p et je test cela : %% \n", nombre, nbr, test, test, car, hexa, max, p);

	//ft_printf("\nMon ft_printf return : %d\n", i);
	//ft_printf("le printf return : %d\n", j);
	
	//i = ft_printf("%-*.*d\n", 30, 16, nbr);
	//j = printf("%-*.*d\n", 30, 16, nbr);
	
	ft_printf("%*.*X\n", -15, 10, nbr);
	printf("%*.*X\n", -15, 10, nbr);
	
	printf("\nMon ft_printf return : %d\n", i);
	printf("le printf return : %d\n", j);
	return (0);
}
