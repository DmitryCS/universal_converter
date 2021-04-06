#include "udecoder/dummy.h"
#include "gmpxx.h"

std::string udecoder::sum(const std::string& lhs, const std::string& rhs)
{
	mpz_class result{ lhs };
	result += mpz_class{ rhs };
	return result.get_str();
}
