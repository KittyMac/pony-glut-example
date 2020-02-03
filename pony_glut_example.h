#ifndef pony_pony_glut_example_h
#define pony_pony_glut_example_h

/* This is an auto-generated header file. Do not edit. */

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _MSC_VER
typedef struct __int128_t { uint64_t low; int64_t high; } __int128_t;
typedef struct __uint128_t { uint64_t low; uint64_t high; } __uint128_t;
#endif

/*
  A String is an ordered collection of characters.

  Strings don't specify an encoding.

  Example usage of some common String methods:

```pony
actor Main
  new create(env: Env) =>
    try
      // construct a new string
      let str = "Hello"

      // make an uppercased version
      let str_upper = str.upper()
      // make a reversed version
      let str_reversed = str.reverse()

      // add " world" to the end of our original string
      let str_new = str.add(" world")

      // count occurrences of letter "l"
      let count = str_new.count("l")

      // find first occurrence of letter "w"
      let first_w = str_new.find("w")
      // find first occurrence of letter "d"
      let first_d = str_new.find("d")

      // get substring capturing "world"
      let substr = str_new.substring(first_w, first_d+1)
      // clone substring
      let substr_clone = substr.clone()

      // print our substr
      env.out.print(consume substr)
  end
```
*/
typedef struct String String;

/*
A Pointer[A] is a raw memory pointer. It has no descriptor and thus can't be
included in a union or intersection, or be a subtype of any interface. Most
functions on a Pointer[A] are private to maintain memory safety.
*/
/*
Allocated by the glut_main.c. It gets allocated, then unscheduled (so pony itself doesn't run)
it, and then it "becomes" the actor.
*/
typedef struct MainThreadActor MainThreadActor;

typedef struct OpenGL OpenGL;

typedef struct None None;

/*
A Pointer[A] is a raw memory pointer. It has no descriptor and thus can't be
included in a union or intersection, or be a subtype of any interface. Most
functions on a Pointer[A] are private to maintain memory safety.
*/
/* Allocate a String without initialising it. */
String* String_Alloc();

/*
Unsafe update, used internally.
*/
char String_ref__set_ZCC(String* self, size_t i, char value);

/*
Returns a C compatible pointer to a null-terminated version of the
string, safe to pass to an FFI function that doesn't accept a size
argument, expecting a null-terminator. If the underlying string
is already null terminated, this is returned; otherwise the string
is copied into a new, null-terminated allocation.
*/
char* String_box_cstring_o(String* self);

/*
Returns a C compatible pointer to a null-terminated version of the
string, safe to pass to an FFI function that doesn't accept a size
argument, expecting a null-terminator. If the underlying string
is already null terminated, this is returned; otherwise the string
is copied into a new, null-terminated allocation.
*/
char* String_val_cstring_o(String* self);

/*
Returns a C compatible pointer to a null-terminated version of the
string, safe to pass to an FFI function that doesn't accept a size
argument, expecting a null-terminator. If the underlying string
is already null terminated, this is returned; otherwise the string
is copied into a new, null-terminated allocation.
*/
char* String_ref_cstring_o(String* self);

/*
An empty string. Enough space for len bytes is reserved.
*/
String* String_ref_create_Zo(String* self, size_t len);

/*
Return true if the string is null-terminated and safe to pass to an FFI
function that doesn't accept a size argument, expecting a null-terminator.
This method checks that there is a null byte just after the final position
of populated bytes in the string, but does not check for other null bytes
which may be present earlier in the content of the string.
If you need a null-terminated copy of this string, use the clone method.
*/
bool String_ref_is_null_terminated_b(String* self);

/*
Return true if the string is null-terminated and safe to pass to an FFI
function that doesn't accept a size argument, expecting a null-terminator.
This method checks that there is a null byte just after the final position
of populated bytes in the string, but does not check for other null bytes
which may be present earlier in the content of the string.
If you need a null-terminated copy of this string, use the clone method.
*/
bool String_box_is_null_terminated_b(String* self);

/*
Return true if the string is null-terminated and safe to pass to an FFI
function that doesn't accept a size argument, expecting a null-terminator.
This method checks that there is a null byte just after the final position
of populated bytes in the string, but does not check for other null bytes
which may be present earlier in the content of the string.
If you need a null-terminated copy of this string, use the clone method.
*/
bool String_val_is_null_terminated_b(String* self);

bool Bool_val_create_bb(bool self, bool from);

bool Bool_box_op_and_bb(bool self, bool y);

bool Bool_val_op_and_bb(bool self, bool y);

int32_t I32_val_create_ii(int32_t self, int32_t value);

/* Allocate a MainThreadActor without initialising it. */
MainThreadActor* MainThreadActor_Alloc();

MainThreadActor* MainThreadActor_tag_create_o__send(MainThreadActor* self);

void MainThreadActor_displayFunc_o();

/* Allocate a OpenGL without initialising it. */
OpenGL* OpenGL_Alloc();

OpenGL* OpenGL_val_create_o(OpenGL* self);

int32_t OpenGL_val_glColorBufferBit_i(OpenGL* self);

int32_t OpenGL_box_glColorBufferBit_i(OpenGL* self);

size_t USize_box_sub_ZZ(size_t self, size_t y);

size_t USize_val_sub_ZZ(size_t self, size_t y);

bool USize_val_ne_Zb(size_t self, size_t y);

bool USize_box_ne_Zb(size_t self, size_t y);

size_t USize_val_max_value_Z(size_t self);

size_t USize_val_add_ZZ(size_t self, size_t y);

size_t USize_box_add_ZZ(size_t self, size_t y);

size_t USize_val_min_ZZ(size_t self, size_t y);

size_t USize_box_min_ZZ(size_t self, size_t y);

size_t USize_val_create_ZZ(size_t self, size_t value);

bool USize_val_lt_Zb(size_t self, size_t y);

bool USize_box_lt_Zb(size_t self, size_t y);

bool USize_val_gt_Zb(size_t self, size_t y);

bool USize_box_gt_Zb(size_t self, size_t y);

/* Allocate a None without initialising it. */
None* None_Alloc();

None* None_val_create_o(None* self);

float F32_val_create_ff(float self, float value);

bool U8_val_eq_Cb(char self, char y);

bool U8_box_eq_Cb(char self, char y);

char U8_val_create_CC(char self, char value);

/*
Space for len instances of A.
*/
char* Pointer_U8_val_ref__alloc_Zo(char* self, size_t len);

/*
Set index i and return the previous value.
*/
char Pointer_U8_val_ref__update_ZCC(char* self, size_t i, char value);

/*
Retrieve index i.
*/
char Pointer_U8_val_val__apply_ZC(char* self, size_t i);

/*
Retrieve index i.
*/
char Pointer_U8_val_ref__apply_ZC(char* self, size_t i);

/*
Retrieve index i.
*/
char Pointer_U8_val_box__apply_ZC(char* self, size_t i);

/*
Unsafe change in reference capability.
*/
char* Pointer_U8_val_val__unsafe_o(char* self);

/*
Unsafe change in reference capability.
*/
char* Pointer_U8_val_box__unsafe_o(char* self);

/*
Unsafe change in reference capability.
*/
char* Pointer_U8_val_ref__unsafe_o(char* self);

/*
Unsafe change in reference capability.
*/
char* Pointer_U8_val_tag__unsafe_o(char* self);

/*
Copy n elements from this to that.
*/
char* Pointer_U8_val_ref__copy_to_oZo(char* self, char* that, size_t n);

/*
Copy n elements from this to that.
*/
char* Pointer_U8_val_val__copy_to_oZo(char* self, char* that, size_t n);

/*
Copy n elements from this to that.
*/
char* Pointer_U8_val_box__copy_to_oZo(char* self, char* that, size_t n);


#ifdef __cplusplus
}
#endif

#endif
