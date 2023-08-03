#pragma once

#include <cstdio>

namespace vapour {
	namespace core {
		namespace console {
			void breakpoint();
			void breakpoint(char id);

			void log(int size, ...);
			void blank();

			/*char        query_c(const char* str...);
			int         query_i(const char* str...);
			float       query_f(const char* str...);
			double      query_d(const char* str...);
			const char* query_s(...);*/
		}
	}
}