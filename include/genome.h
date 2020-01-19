#ifndef _GENOME_H
#define _GENOMEGENE_H

#include <cstdint>
#include <bitset>
#include <functional>

#include "rand_gen.h"

template <size_t _Len>
class genome {
public:
	genome() noexcept;
	genome(cosnt std::bitset<_Len>& dna) noexcept;
	double eval(std::function<double(std::bitset<_Len>)> env) const;
	std::bitset<_Len> apply(std::function<std::bitset<_Len>(std::bitset<_Len>)> op) const;
	void reset() noexcept;
	constexpr size_t length() const noexcept;
private:
	std::bitset<_Len> dna;
};

template <size_t _Len>
inline genome<_Len>::genome() noexcept {
	reset();
}

template <size_t _Len>
inline genome<_Len>::genome(const std::bitset<_Len>& dna) noexcept : dna(dna) { }

template <size_t _Len>
inline double genome<_Len>::eval(std::function<double(std::bitset<_Len>)> env) const {
	return env(dna);
}

template <size_t _Len>
inline std::bitset<_Len> genome<_Len>::apply(std::function<std::bitset<_Len>(std::bitset<_Len>)> op) const {
	return op(dna);
}

template <size_t _Len>
inline void genome<_Len>::reset() noexcept {
	for(int i = 0; i < _Len / 8 + !(!(_Len % 8)); i++) {
		uint8_t r = static_cast<uint8_t>(rand_gen::getrand<int>());
		dna <<= 8;
		dna |= r;
	}
}

template <size_t _Len>
constexpr inline size_t genome<_Len>::length() const noexcept {
	return _Len;
}

#endif