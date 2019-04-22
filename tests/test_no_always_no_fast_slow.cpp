#include <catch2/catch.hpp>

#define GRIS_TU_MODE_DISABLE_ALWAYS
#define GRIS_TU_MODE_DISABLE_FAST
#define GRIS_TU_MODE_SLOW

#include <gris/assert.h>

namespace
{

void assert_true_always()
{
    GRIS_ALAWYS_ASSERT(1 == 1, "One is equal to one");
}

void assert_false_always()
{
    GRIS_ALAWYS_ASSERT(1 == 2, "One is not equal to two");
}

void assert_true_fast()
{
    GRIS_FAST_ASSERT(1 == 1, "One is equal to one");
}

void assert_false_fast()
{
    GRIS_FAST_ASSERT(1 == 2, "One is not equal to two");
}

void assert_true_slow()
{
    GRIS_SLOW_ASSERT(1 == 1, "One is equal to one");
}

void assert_false_slow()
{
    GRIS_SLOW_ASSERT(1 == 2, "One is not equal to two");
}

}  // namespace <anonymous>

TEST_CASE("Assert with always disabled, fast disabled and slow", "[assert rules]")
{
  Gris::Assert::SetLoggingCallback(&Gris::Assert::NullLoggigCallback);
  Gris::Assert::SetFailureHandler(&Gris::Assert::ThrowHandler);

  SECTION("Always does not fire on success")
  {
    CHECK_NOTHROW(assert_true_always());
  }

  SECTION("Always does not fire on failure (disabled)")
  {
    CHECK_NOTHROW(assert_false_always());
  }

  SECTION("Fast does not fire on success")
  {
    CHECK_NOTHROW(assert_true_fast());
  }

  SECTION("Fast does not fire on failure (disabled)")
  {
    CHECK_NOTHROW(assert_false_fast());
  }

  SECTION("Slow does not fire on success")
  {
    CHECK_NOTHROW(assert_true_slow());
  }

  SECTION("Slow fires on failure")
  {
    CHECK_THROWS_AS(assert_false_slow(), Gris::Assert::AssertionException);
  }
}

