
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
#include <cstdio>
#include <vector>
#include <stack>

namespace cedar {
	namespace vm {

		// forwared declaration
		class machine;


		class compiler {
			protected:
				cedar::vm::machine *m_vm;
			public:
				compiler(cedar::vm::machine *vm);
				~compiler();

				/*
				 * given some object reference,
				 * compile it into bytecode and return
				 * the address of the start of the bytecode
				 * representation of that object
				 */
				ref compile(ref);



		};


		// a bytecode compilation pass that takes in the compiler
		// oboejct
		ref bytecode_pass(ref, compiler*);
	}
}
