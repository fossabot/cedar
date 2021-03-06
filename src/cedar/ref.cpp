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
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <cedar/object.h>
#include <cedar/object/number.h>
#include <cedar/object/sequence.h>
#include <cedar/ref.hpp>

using namespace cedar;

uint16_t cedar::change_refcount(object *o, int change) {
  if (o->refcount == 0 && change < 0) return 0;
  return o->refcount += change;
}

uint16_t cedar::get_refcount(object *o) { return o->refcount; }

void cedar::delete_object(object *o) {
  if (!o->no_autofree) {
		delete o;
	}
}

ref cedar::ref::get_first() const {
  if (!is_object())
    throw cedar::make_exception("unable to get first of non-object reference");
  return reinterpret_cast<sequence *>(obj)->get_first();
}

ref cedar::ref::get_rest() const {
  if (!is_object())
    throw cedar::make_exception("unable to get rest of non-object reference");
  return reinterpret_cast<sequence *>(obj)->get_rest();
}

void cedar::ref::set_first(ref val) {
  if (!is_object())
    throw cedar::make_exception("unable to set first of non-object reference");
  return reinterpret_cast<sequence *>(obj)->set_first(val);
}

void cedar::ref::set_rest(ref val) {
  if (!is_object())
    throw cedar::make_exception("unable to set rest of non-object reference");
  return reinterpret_cast<sequence *>(obj)->set_rest(val);
}

void cedar::ref::set_const(bool c) { obj->no_autofree = c; }

cedar::runes ref::to_string(bool human) {
  if (is_number()) {
    if (is_float()) {
      return std::to_string(m_float);
    }
    return std::to_string(m_int);
  }

	if (obj == nullptr) return U"nil";
  return obj->to_string(human);
}


const std::type_info &cedar::get_number_typeid(void) { return typeid(cedar::number); }
const std::type_info &cedar::get_object_typeid(object *obj) { return typeid(*obj); }
