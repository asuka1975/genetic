#ifndef _RAND_GEN_H
#define _RAND_GEN_H

#include <ctime>
#include <random>
#include <map>
#include <thread>
#include <limits>

class rand_gen {
public:
	template <class _Typ>
	static _Typ getrand() noexcept;
private:
	static std::map<std::thread::id, std::mt19937> gen_list;
};

template <>
inline int rand_gen::getrand<int>() noexcept {
	const std::thread::id main_tid = std::this_thread::get_id();
	if(gen_list.find(main_tid) == gen_list.end()) {
		std::mt19937 mt(std::hash<std::thread::id>()(main_tid) * std::time(nullptr));
		gen_list[main_tid] = std::move(mt);
	}
	std::uniform_int_distribution<> dist;
	return dist(gen_list[main_tid]);
}

template <>
inline double rand_gen::getrand<double>() noexcept {
	const std::thread::id main_tid = std::this_thread::get_id();
	if(gen_list.find(main_tid) == gen_list.end()) {
		std::mt19937 mt(std::hash<std::thread::id>()(main_tid) * std::time(nullptr));
		gen_list[main_tid] = std::move(mt);
	}
	std::uniform_real_distribution<> dist;
	return dist(gen_list[main_tid]);
}

#endif