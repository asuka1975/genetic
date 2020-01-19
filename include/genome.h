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
	explicit genome(const std::bitset<_Len>& dna) noexcept;
	template <class _TEvaluator>
	double eval(_TEvaluator env) const;
	template <class _TOperator>
	std::bitset<_Len> apply(_TOperator op) const;
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
template <class _TEvaluator>
inline double genome<_Len>::eval(_TEvaluator env) const {
	return env(dna);
}

template <size_t _Len>
template <class _TOperator>
inline std::bitset<_Len> genome<_Len>::apply(_TOperator op) const {
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