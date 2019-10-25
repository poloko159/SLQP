#include "Header.h"

int inverse_kinematics(real_t x, real_t y)
{
	real_t phi3 = 0;
	phi3=atan(0.2e1 * (0.1250000000e-2 * cos(x) * sin(y) + 0.1250000000e-2 * sin(x) * sqrt(0.3e1) - 0.3250000000e-2 + sqrt(pow(-0.2500000000e-2 * cos(y) + 0.1250000000e-2, 0.2e1) + pow(-0.1250000000e-2 * cos(x) * sin(y) - 0.1250000000e-2 * sin(x) * sqrt(0.3e1) + 0.3250000000e-2, 0.2e1) - pow(0.2500000000e-2 * pow(cos(y), 0.2e1) - 0.2500000000e-2 * cos(y) - 0.2975000000e-2 + pow(-0.5000000000e-1 * cos(x) * sin(y) - 0.5000000000e-1 * sin(x) * sqrt(0.3e1) + 0.13e0, 0.2e1) / 0.4e1, 0.2e1))) / (0.2500000000e-2 * pow(cos(y), 0.2e1) - 0.4225000000e-2 + pow(-0.5000000000e-1 * cos(x) * sin(y) - 0.5000000000e-1 * sin(x) * sqrt(0.3e1) + 0.13e0, 0.2e1) / 0.4e1));

	real_t phi2;
	phi2 = atan(0.2e1 * (-0.10e-1 * cos(x) * sin(y) - 0.130e-1 + sqrt(pow(-0.10e-1 * cos(y) + 0.50e-2, 0.2e1) + pow(0.10e-1 * cos(x) * sin(y) + 0.130e-1, 0.2e1) - pow(0.1e-1 * pow(cos(y), 0.2e1) - 0.10e-1 * cos(y) - 0.119e-1 + pow(0.1e0 * cos(x) * sin(y) + 0.13e0, 0.2e1), 0.2e1))) / (0.1e-1 * pow(cos(y), 0.2e1) - 0.169e-1 + pow(0.1e0 * cos(x) * sin(y) + 0.13e0, 0.2e1)));

	real_t phi1;
	
	phi1 = atan(0.2e1 * (0.1250000000e-2 * cos(x) * sin(y) - 0.1250000000e-2 * sin(x) * sqrt(0.3e1) - 0.3250000000e-2 + sqrt(pow(-0.2500000000e-2 * cos(y) + 0.1250000000e-2, 0.2e1) + pow(-0.1250000000e-2 * cos(x) * sin(y) + 0.1250000000e-2 * sin(x) * sqrt(0.3e1) + 0.3250000000e-2, 0.2e1) - pow(0.2500000000e-2 * pow(cos(y), 0.2e1) - 0.2500000000e-2 * cos(y) - 0.2975000000e-2 + pow(-0.5000000000e-1 * cos(x) * sin(y) + 0.5000000000e-1 * sin(x) * sqrt(0.3e1) + 0.13e0, 0.2e1) / 0.4e1, 0.2e1))) / (0.2500000000e-2 * pow(cos(y), 0.2e1) - 0.4225000000e-2 + pow(-0.5000000000e-1 * cos(x) * sin(y) + 0.5000000000e-1 * sin(x) * sqrt(0.3e1) + 0.13e0, 0.2e1) / 0.4e1));
#if 0
	std::cout << "phi 1 = " << phi1 << std::endl;
	std::cout << "phi 2 = " << phi2 << std::endl;
	std::cout << "phi 3 = " << phi3 << std::endl;
#endif
	return 0;
}