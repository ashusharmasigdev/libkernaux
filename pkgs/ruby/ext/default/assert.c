#include <kernaux.h>
#include <ruby.h>

static void assert_cb(const char *file, int line, const char *str);

static VALUE rb_KernAux_assert_cb(VALUE self);
static VALUE rb_KernAux_assert_cb_EQ(VALUE self, VALUE assert_cb);
static
VALUE rb_KernAux_assert_do(VALUE self, VALUE file, VALUE line, VALUE msg);

static ID rb_intern_call = Qnil;
static VALUE rb_KernAux = Qnil;

void init_assert()
{
    rb_gc_register_mark_object(rb_intern_call = rb_intern("call"));
    rb_gc_register_mark_object(rb_KernAux = rb_define_module("KernAux"));

    kernaux_assert_cb = assert_cb;

    rb_define_singleton_method(rb_KernAux, "assert_cb",
                               rb_KernAux_assert_cb, 0);
    rb_define_singleton_method(rb_KernAux, "assert_cb=",
                               rb_KernAux_assert_cb_EQ, 1);
    rb_define_singleton_method(rb_KernAux, "assert_do",
                               rb_KernAux_assert_do, 3);
}

void assert_cb(const char *const file, const int line, const char *const str)
{
    const VALUE assert_cb_rb = rb_iv_get(rb_KernAux, "@assert_cb");
    if (assert_cb_rb == Qnil) return;
    const VALUE file_rb = rb_str_new2(file);
    const VALUE line_rb = INT2FIX(line);
    const VALUE str_rb = rb_str_new2(str);
    rb_funcall(assert_cb_rb, rb_intern_call, 3, file_rb, line_rb, str_rb);
}

VALUE rb_KernAux_assert_cb(const VALUE self)
{
    return rb_iv_get(self, "@assert_cb");
}

VALUE rb_KernAux_assert_cb_EQ(const VALUE self, const VALUE assert_cb_rb)
{
    return rb_iv_set(self, "@assert_cb", assert_cb_rb);
}

VALUE rb_KernAux_assert_do(
    const VALUE self_rb __attribute__((unused)),
    VALUE file_rb,
    const VALUE line_rb,
    VALUE msg_rb
) {
    const char *const file = StringValueCStr(file_rb);
    const int line = FIX2INT(line_rb);
    const char *const msg = StringValueCStr(msg_rb);

    kernaux_assert_do(file, line, msg);

    return Qnil;
}
