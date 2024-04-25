#include <iostream>
#include <string>
#include <cstdlib>

int main(int argc, char *argv[])
{

    if (argc < 3)
    {
        std::cerr << "Usage: " << argv[0] << " (temperature) -f OR (temperature) -c\n";
        return 1; // Indicate error
    }

    double fahr_to_celc(double fahr);
    double celc_to_fahr(double celc);

    std::string temp_unit = argv[2];

    if (temp_unit == "-c")
    {
        std::cout << "Temperature in celcius: " << fahr_to_celc(std::stod(argv[1])) << "\n";
    }
    else if (temp_unit == "-f")
    {
        std::cout << "Temperature in fahrenheit: " << celc_to_fahr(std::stod(argv[1])) << "\n";
    }
    else
    {
        std::cout << "(temperature) -f OR (temperature) -c\n";
    }

    return 0;
}

double fahr_to_celc(double fahr)
{
    return (fahr - 32) * 5 / 9;
}

double celc_to_fahr(double celc)
{
    return ((celc * 9 / 5) + 32);
}