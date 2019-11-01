#include "random.h"
#include <random>
#include <algorithm>
#include <iostream>

RandomNumbers::RandomNumbers (unsigned long int s) 
:seed(s)
{
	if (s==0) {
	std::random_device rd;
	s=rd();
	}
	rng=std::mt19937(s);
}

double RandomNumbers::uniform_double (double lower, double upper) {
	std::uniform_real_distribution<double> distribution(lower, upper);
	return distribution(rng);
}

double RandomNumbers::normal(double mean, double sd) {
   std::normal_distribution<double> distribution(mean,sd);
   return distribution(rng);

}

int RandomNumbers::poisson(double mean) {
	std::poisson_distribution<int> distribution(mean);
	return distribution(rng);
}
void RandomNumbers::uniform_double(std::vector<double>& v, double lower, double upper) {
  for (size_t i(0); i<v.size(); ++i) {      
	  v[i]=uniform_double(lower, upper);
	  }
  
}

void RandomNumbers::normal(std::vector<double>& v, double mean, double sd) {
  for (size_t i(0); i<v.size(); ++i) {      
	  v[i]=normal(mean, sd);
	  }	
}

void RandomNumbers::poisson(std::vector<int>& v, double mean) {
  for (size_t i(0); i<v.size(); ++i) {      
	  v[i]=poisson(mean);
	  }	
}
