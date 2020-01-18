#include "rand_gen.h"

std::map<std::thread::id, std::mt19937> rand_gen::gen_list;