#include <iostream>
#include <string>
#include <algorithm>
#include <charconv>
#include <cstdlib>
#include <numeric>
#include <vector>
#include <cmath>
// Credit: Found from_chars() and exit() in NumberConversion() through googling
// Credit: Used example code to understand the syntax
unsigned int NumberConversion(std::string str);
unsigned long long int power (unsigned int a, unsigned int b);
int sum_vector(std::vector<int> v);
std::vector<int> vectorize_digits(unsigned long long n);
std::string vec_to_string(std::vector<int> vec);

int main (int argc, char* argv[] ) {
	if (argc == 3) {
		//converts the strings to unsigned shorts
		unsigned int a = NumberConversion(argv[1]);
		unsigned int b = NumberConversion(argv[2]);
		// if b * log10(a) is larger than or equal to 64 * log10(2) than the value of the computed power 
		// will risk overflowing the unsigned long long int type so we check it to make sure it will fit
		if (b * log10(a) >= 64 * log10(2)){
			std::cout <<"\nThe power you are trying to compute is too large, try different values for 'a' and 'b'.\n";
			std::exit(EXIT_FAILURE);
		}
		unsigned long long int power_tot = power(a, b);
		std::vector<int> v = vectorize_digits(power_tot);
		int sum = sum_vector(v);
		std::string vect = vec_to_string(v);
		//std::cout << "\n " << vect << " \n"; used this to make sure vec_to_string() formatted correctly
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
unsigned long long int power (unsigned int a, unsigned int b) {
	unsigned int power_tot = 0;
	if (b == 0){
		return power_tot = 1;
	} else{
		power_tot = a;
		for (unsigned int i = 0; i < b - 1; i++){
			power_tot = power_tot * a;
		}
		return power_tot;
	}
}

// Turns the calculated power into a vector seperating it by its place values
std::vector<int> vectorize_digits(unsigned long long n){
	std::vector<int> v;
	if (n == 0){
		v.push_back(0);
	}
	else{
		while (n != 0){
			v.push_back(n % 10);
			n /= 10;
		}
		// flips the vector so the numbers are in the correct order
		std::reverse(v.begin(), v.end());
	}
	return v;
}

int sum_vector(std::vector<int> v){
	return std::accumulate(v.begin(), v.end(), 0);
}

//converts a vector of ints into a string with a list style format
std::string vec_to_string(std::vector<int> vec){
	
	std::string vec_str = "[";
	
	for (size_t i = 0; i < vec.size(); i++){
		vec_str += std::to_string(vec[i]);
		if (i+1 != vec.size()){
			vec_str += ", ";
		}
	}
	vec_str += "]";
	return vec_str;
}

// this attempts to convert the string given throug hthe terminal into an unsigned
// returning an error if it can not
unsigned int NumberConversion(std::string str){
	unsigned int num = 0;
	
	// attempts to parse the string to turn it into a unsigned int
	// if it fails then it prints an error statement and terminates the execution
	auto [ptr, ec] = std::from_chars(str.data(), str.data() + str.size(), num);
	std::cout << "\nAttempting Number Conversion on "<<str<<" \n";
	if (ec == std::errc::result_out_of_range) {
		std::cout << "\nError: "<< str <<  " outside of unsigned int bounds!\n";
		std::exit(EXIT_FAILURE);
	} else if (!str.empty() && str[0] == '-') {
		std::cout << "\nNegative detected. Negative values are not allowed.\n";
		std::exit(EXIT_FAILURE);
	} else if (ec == std::errc::invalid_argument) {
		std::cout << "\nError: Not a valid number!\n";
		std::exit(EXIT_FAILURE);
	} else if (str.find(".") != std::string::npos) {
		std::cout << "\nDecimal detected. Decimals are not allowed.\n";
		std::exit(EXIT_FAILURE);
	} else {
		std::cout << "\nSuccess: " << num << std::endl;
		return num;
	}
	return -1;
}


