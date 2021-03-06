
//
// traffic - A Simple Network Simulator
// Copyright (c) Dave Kilian 2014
//
// test.h - Test declarations and utilities
//

extern char *g_lastTestError;

// Causes a test to fail gracefull
//
#define FAIL(...) do {                              \
    asprintf(&g_lastTestError, __VA_ARGS__);        \
    return false;                                   \
    } while (0)

// Calls FAIL if the given expression evaluates to 0
//
#define ASSERT(expr, ...) do {                      \
        if (!(expr)) {                              \
            FAIL(__VA_ARGS__);                      \
        }                                           \
    } while (0)

#define EQUAL(actual, expected) do {                \
        if ((actual) != (expected)) {               \
            FAIL(                                   \
                "In %s: %d: %s != %s",              \
                __FILE__, __LINE__,                 \
                #actual, #expected);                \
        }                                           \
    } while (0)


// ASSERTs the given expression returns TR_OK
//
#define SUCCEED(expr) do {                          \
        tr_err __error;                             \
        if ((__error = (expr)) != TR_OK) {          \
            FAIL(                                   \
               "In %s:%d: `%s` returned %d: %s",    \
               __FILE__, __LINE__,                  \
               #expr,                               \
               __error,                             \
               tr_errstr(__error));                 \
        }                                           \
    } while (0)

// ASSERTs the given expression returns the given failure code
//
#define ERROR(err, expr) do {                                       \
        tr_err __error;                                             \
        tr_err __expected = (err);                                  \
        if ((__error = (expr)) != TR_OK) {                          \
            FAIL(                                                   \
               "In %s:%d: `%s` returned %d: %s; expected %d: %s",   \
               __FILE__, __LINE__,                                  \
               #expr,                                               \
               __error,                                             \
               tr_errstr(__error),                                  \
               __expected,                                          \
               tr_errstr(__expected));                              \
        }                                                           \
    } while (0)

//
// Unit test declarations
// Add new items to the table in main.c
//


// Tests for vector utility
//
bool test_vector_basics();
bool test_vector_enum();
bool test_vector_stackfuncs();
bool test_vector_growshrink();

// Tests for list utility
//
bool test_list_basics();
bool test_list_enum();
bool test_list_addremove();

// Tests for hashtable utility
//
bool test_hash_basics();
bool test_hash_enum();
bool test_inthash_hashfunc();
bool test_strhash_hashfunc();

// Tests for hash set utility
//
bool test_set_basics();
bool test_set_enum();

