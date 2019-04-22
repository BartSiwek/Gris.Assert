# GrisAssert
Provides a set of preprocessor asserions macros, GRIS_ALAWYS_ASSERT, GRIS_FAST_ASSERT, GRIS_SLOW_ASSERT with the purpose of providing redundant runtime checks. If an assertion argument evaluates to false, a configurable callback function is calld with the current filename, line number, and a nul-terminated message.

Inspired by [BDE 3.0: bsls_assert](https://bloomberg.github.io/bde/group__bsls__assert.html)

# Assert Maros
- GRIS_ALAWYS_ASSERT
- GRIS_FAST_ASSERT
- GRIS_SLOW_ASSERT

# Semantics
- Redundant - no observable difference in program behavior apart from performance
- No side-effects - asserted expressions should not have side effects
- No impact on ABI compatibility - except for when GRIS_SLOW_ASSERT macro is enabled

The macros differ in their intended purpose, object file ABI compatibility and performance impact:

| Macro              | Performance impact          | ABI compatibility between translation units | Purpose                 |
| ------------------ | --------------------------- | ------------------------------------------- | ----------------------- |
| GRIS_ALAWYS_ASSERT | Negligible                  | Required                                    | Always performed checks |
| GRIS_FAST_ASSERT   | Max. 5-10% overhead         | Required                                    | Debug checks            |
| GRIS_SLOW_ASSERT   | Order of magnitude overhead | Optional                                    | Troubleshooting checks  |

The ABI compatibility is related to the target-level modes and tu modes [FIXME]

# Target-level modes
The following macros can be used by the build system/development environment to specify target-wide assert semantics. If more than one is is defined an compile-time error is reported. 
- GRIS_TARGET_MODE_NONE - none of the assert macros are active. Used mostly to verify assertions have no observable side-effects. 
- GRIS_TARGET_MODE_RELEASE - deafult build mode. Only GRIS_ALAWYS_ASSERT is active.
- GRIS_TARGET_MODE_DEBUG - GRIS_FAST_ASSERT and GRIS_ALAWYS_ASSERT are active.
- GRIS_TARGET_MODE_SAFE - GRIS_SLOW_ASSERT, GRIS_FAST_ASSERT and GRIS_ALAWYS_ASSERT are active.

# Translation unit-level modes
The following macros can be used to override target-level modes on a per-translation-unit basis. If more GRIS_TU_MODE_NONE is defined defining any other translation unit-level macros will result in a compile-time error. GRIS_TU_MODE_ALWAYS, GRIS_TU_MODE_FAST and GRIS_TU_MODE_SLOW can be freely mixed.
- GRIS_TU_MODE_NONE - convinience macro, none of the assert macros will be active.
- GRIS_TU_MODE_ALWAYS - GRIS_ALAWYS_ASSERT will be active.
- GRIS_TU_MODE_DISABLE_ALWAYS - GRIS_ALAWYS_ASSERT will not be active.
- GRIS_TU_MODE_FAST - GRIS_FAST_ASSERT will be active.
- GRIS_TU_MODE_DISABLE_FAST - GRIS_FAST_ASSERT will not be active.
- GRIS_TU_MODE_SLOW - GRIS_SLOW_ASSERT will be active.
- GRIS_TU_MODE_DISABLE_SLOW - GRIS_SLOW_ASSERT will not be active.

# Assertion failure callbacks
Two types of callbacks:
- Failure logging callback
- Failure handler

How to install callback.
Standard callbacks
- stdout logging callback
- seterr logging callback
- null logging callback
- abort handler
- throwing handler
- null handler

Method to invoke callbacks - should not be used by client code.
Scope related handler change.

# Checking if assertion macro is enabled
Useful for conditional compilation of the headers when intorducing code that would break ABI compatibility, which is only allowed when GRIS_TARGET_MODE_SAFE is defined.
- GRIS_ALWAYS_ASSERT_IS_ACTIVE
- GRIS_FAST_ASSERT_IS_ACTIVE
- GRIS_SLOW_ASSERT_IS_ACTIVE

# Tests
0. Test standard callbacks and handlers (as much as it makes sense)
1. Test setting calbacks and handlers
2. Test various macro combinations
