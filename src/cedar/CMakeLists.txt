
# generated by tools/scripts/generate_src_cmakelists.py. DO NOT MODIFY

add_library(cedar-lib SHARED
	src/cedar/ref.cpp
	src/cedar/context.cpp
	src/cedar/object.cpp
	src/cedar/passes.cpp
	src/cedar/runes.cpp
	src/cedar/parser.cpp
	src/cedar/vm/compiler.cpp
	src/cedar/vm/instruction.cpp
	src/cedar/vm/machine.cpp
	src/cedar/object/symbol.cpp
	src/cedar/object/string.cpp
	src/cedar/object/lambda.cpp
	src/cedar/object/nil.cpp
	src/cedar/object/list.cpp
	src/cedar/object/number.cpp
)

set_target_properties(cedar-lib PROPERTIES OUTPUT_NAME cedar)
