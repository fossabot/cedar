/*
 * MIT License
 *
 * Copyright (c) 2018 Nick Wanninger
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#pragma once

#include <cedar/ref.hpp>
#include <cedar/vm/bytecode.h>
#include <cedar/vm/compiler.h>

#include <cstdio>

namespace cedar {
	namespace vm {


		class machine {
			protected:

				std::vector<ref> constants;
				cedar::vm::compiler m_compiler;

				friend cedar::vm::compiler;

				// mapping from symbol names to references
				std::map<cedar::runes, ref> global_bindings;

				uint64_t stacksize = 0;
				ref *stack = nullptr;

			public:
				machine(void);
				~machine(void);

				/*
				 * given some object reference,
				 * compile it into this specific target
				 */
				ref eval(ref);
		};
	}
}
