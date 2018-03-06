#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <string>
#include <sstream>

#include <versioning/version.h>


SCENARIO("version can be created", "[version]") {
    GIVEN("A version") {
        versioning::version v{1, 2, 3};

        REQUIRE(v.major() == 1);
        REQUIRE(v.minor() == 2);
        REQUIRE(v.patch() == 3);

        WHEN("the major is changed") {
            v.major(7);
            THEN("only the major changes") {
                REQUIRE(v.major() == 7);
                REQUIRE(v.minor() == 2);
                REQUIRE(v.patch() == 3);
            }
        }

        WHEN("the minor is changed") {
            v.minor(79);
            THEN("only the minor changes") {
                REQUIRE(v.major() == 1);
                REQUIRE(v.minor() == 79);
                REQUIRE(v.patch() == 3);
            }
        }

        WHEN("the patch is changed") {
            v.patch(175);
            THEN("only the patch changes") {
                REQUIRE(v.major() == 1);
                REQUIRE(v.minor() == 2);
                REQUIRE(v.patch() == 175);
            }
        }
    }
}

SCENARIO("version can be printed", "[version]") {
    GIVEN("A version") {
        versioning::version v{1, 2, 3};

        WHEN("version is printed") {
            std::ostringstream os;
            os << v;
            THEN("version's components are printed separated by period") {
                REQUIRE(os.str() == "1.2.3");
            }
        }
    }
}

SCENARIO("versions can be compared", "[version]") {
    GIVEN("Two versions") {
        versioning::version a{1, 2, 3};
        versioning::version b{1, 2, 3};

        WHEN("all components are equal") {
            THEN("versions are equal") {
                REQUIRE(a == b);
                REQUIRE(!(a != b));

                REQUIRE(!(a < b));
                REQUIRE((a <= b));
                REQUIRE(!(a > b));
                REQUIRE((a >= b));
            }
        }

        WHEN("majors differ") {
            a.major(2);
            THEN("versions differ") {
                REQUIRE(!(a == b));
                REQUIRE(a != b);

                REQUIRE(!(a < b));
                REQUIRE(!(a <= b));
                REQUIRE((a > b));
                REQUIRE((a >= b));
            }
        }

        WHEN("minors differ") {
            a.minor(1);
            THEN("versions differ") {
                REQUIRE(!(a == b));
                REQUIRE(a != b);

                REQUIRE((a < b));
                REQUIRE((a <= b));
                REQUIRE(!(a > b));
                REQUIRE(!(a >= b));
            }
        }

        WHEN("patches differ") {
            a.patch(6);
            THEN("versions differ") {
                REQUIRE(!(a == b));
                REQUIRE(a != b);

                REQUIRE(!(a < b));
                REQUIRE(!(a <= b));
                REQUIRE((a > b));
                REQUIRE((a >= b));
            }
        }
    }
}