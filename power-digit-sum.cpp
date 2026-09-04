#include <iostream>
#include <string>
#include <algorithm>
#include <charconv>
#include <cstdlib>
// Credit: Found from_chars() and exit() in NumberConversion() through googling
// Credit: Used example code to understand the syntax
unsigned short NumberConversion(std::string str);
unsigned int power (unsigned short a, unsigned short b);
unsigned int power_sum(unsigned int pow);

int main (int argc, char* argv[] ) {
	if (argc == 3) {
		//converts the strings to unsigned shorts
		unsigned short a = NumberConversion(argv[1]);
		unsigned short b = NumberConversion(argv[2]);
		
		unsigned int power_tot = power(a, b);
		unsigned int sum = power_sum(power_tot);
		std::cout << "\n "<< a << "^" << b << " = " << power_tot << std::endl;
		std::cout <<"Sum Of Digits: " << sum << std::endl;
		return 1;
	}
	else {
		std::cout <<"You have provided " << argc <<" arguments. You need to provide 3 arguments.";
		return 0;
	}
}
//takes two unsigned shorts and calculates the power using a for loop (a^b)
unsigned int power (unsigned short a, unsigned short b) {
	unsigned int power_tot = 0;
	if (b == 0){
		return power_tot = 1;
	} else{
		power_tot = a;
		for (int i = 0; i < b - 1; i++){
			power_tot = power_tot * a ;
		}
		return power_tot;
	}
}
// calculates the sum by isloating the far most right digit and adding it to the sum
// and then removing that digit from the original number
unsigned int power_sum(unsigned int pow){
	unsigned int sum = 0;
	while (pow != 0){
		sum += pow % 10;
		pow /= 10;
		
	}
	return sum;
}
// this attempts to convert the string given throug hthe terminal into an unsigned
// returning an error if it can not
unsigned short NumberConversion(std::string str){
	unsigned int num = 0;
	
	// attempts to parse the string to turn it into a unsigned int
	// if it fails then it prints an error statement and terminates the execution
	auto [ptr, ec] = std::from_chars(str.data(), str.data() + str.size(), num);
	std::cout << "\nAttempting Number Conversion\n";
	if (ec == std::errc::result_out_of_range) {
		std::cout << "\nError: Number of unsigned short bounds!\n";
		std::exit(EXIT_FAILURE);
	} else if (ec == std::errc::invalid_argument) {
		std::cout << "\nError: Not a valid numbber!\n";
		std::exit(EXIT_FAILURE);
	} else {
		std::cout << "\nSuccess: " << num << std::endl;
		return num;
	}
	return -1;
}
