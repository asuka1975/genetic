#ifndef _GENE_H
#define _GENE_H

#include <bitset>
#include <functional>

template <size_t _Len>
class gene {
public:
	gene();
	double eval(std::function<double(std::bitset<_Len>)> env) const;
	void reset();
	
	constexpr size_t length() const;
private:
	std::bitset<_Len> dna;
};

#endif