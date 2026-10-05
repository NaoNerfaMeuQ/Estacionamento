#include <iostream>
#include <iomanip>
#include <cctype>
#include <cmath>


int main()
{
	int minutos;
	char fimDeSemana;

	std::cout << "Tempo estacionado em minutos: ";
	std::cin >> minutos;

	std::cout << "E fim de semana? (S/N): ";
	std::cin >> fimDeSemana;

	int horasCobradas = static_cast<int>(std::ceil(minutos / 60.0));

	std::cout << "Horas cobradas: " << horasCobradas << "\n";

	double valorAntesDesconto = 0.0;

	if (horasCobradas > 0)
	{
		// R$ 6.00 pela primeira hora e R$ 4.00 por cada hora a mais (horasCobradas - 1)
		valorAntesDesconto = 6.0 + (horasCobradas - 1) * 4.0;

		if (valorAntesDesconto > 30.0)
		{
			valorAntesDesconto = 30.0;
		}
	}

	double valorDesconto = 0.0;
	if (std::toupper(static_cast<unsigned char>(fimDeSemana)) == 'S')
	{
		valorDesconto = valorAntesDesconto * 0.10;
	}

	double totalPagar = valorAntesDesconto - valorDesconto;

	std::cout << std::fixed << std::setprecision(2);
	std::cout << "Horas cobradas: " << horasCobradas << "h\n";
	std::cout << "Valor bruto: R$ " << valorAntesDesconto << "\n";
	std::cout << "Desconto: R$" << valorDesconto << "\n";
	std::cout << "Total a pagar: R$" << totalPagar << "\n";


	return 0;


}


