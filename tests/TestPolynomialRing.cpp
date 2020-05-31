#include "../src/PolynomialRing.hpp"

#include "catch.hpp"

TEST_CASE("Polynomial Rings test", "[Polynomial ring]") {
    using namespace lab;

    SECTION("Addition") {
        SECTION("simple") {
            const PolynomialRing ring17{17};
            const Polynomial p1{};
            const Polynomial p2{};
            REQUIRE(ring17.add(p1, p2) == Polynomial{});

            const PolynomialRing ring23{23};
            const Polynomial p3{11, 13, 1, 21, 22, 0, 19, 7, 16, 5};
            const Polynomial p4{2, 5, 11, 0, 0, 0, 2, 7, 5, 3};
            REQUIRE(ring23.add(p3, p4) == Polynomial{13, 18, 12, 21, 22, 0, 21, 14, 21, 8});

            const PolynomialRing ring131{131};
            const Polynomial p5{21, 34, 56, 0, 0, 23, 19, 0, 78, 5, 1, 32, 45, 24, 94, 100, 55};
            const Polynomial p6{56, 21, 11, 7, 0, 88, 2, 7, 5, 0};
            REQUIRE(ring131.add(p5, p6) == Polynomial{77, 55, 67, 7, 0, 111, 21, 7, 83, 5, 1, 32, 45, 24, 94, 100, 55});

            const PolynomialRing ring71{71};
            const Polynomial p7{43, 23, 6, 2, 0, 1, 45, 11};
            const Polynomial p8{22, 0, 9, 2, 6, 2, 12, 34, 21, 56, 67, 55, 33};
            REQUIRE(ring71.add(p7, p8) == Polynomial{65, 23, 15, 4, 6, 3, 57, 45, 21, 56, 67, 55, 33});
        }

        SECTION("with modification") {
            const PolynomialRing ring2{2};
            const Polynomial p1{1, 1, 1, 1, 0, 0, 1, 1, 0, 1};
            const Polynomial p2{0, 1, 1, 0, 0, 0, 0, 1, 1};
            REQUIRE(ring2.add(p1, p2) == Polynomial{1, 0, 0, 1, 0, 0, 1, 0, 1, 1});

            const PolynomialRing ring37{37};
            const Polynomial p3{21, 34, 21, 25, 2, 3, 4, 21, 0, 21, 35};
            const Polynomial p4{21, 34, 26, 3, 9, 36, 32, 21, 21, 20, 24, 34, 36, 36, 36, 21, 23};
            REQUIRE(ring37.add(p3, p4) == Polynomial{5, 31, 10, 28, 11, 2, 36, 5, 21, 4, 22, 34, 36, 36, 36, 21, 23});

            const PolynomialRing ring199{199};
            const Polynomial p5{123, 145, 165, 134, 23, 146, 175, 123, 198, 111, 143, 43, 98, 143, 165, 129};
            const Polynomial p6{154, 162, 153, 141, 123, 67, 89, 98, 123, 198, 176, 187, 134, 123, 123, 123, 198};
            REQUIRE(ring199.add(p5, p6) == Polynomial{78, 108, 119, 76, 146, 14, 65, 22, 122, 110, 120, 31, 33, 67, 89, 53, 198});
        }

        SECTION("tail of zeros in result") {
            const PolynomialRing ring2{2};
            const Polynomial p1{1, 0, 1, 1, 1, 1, 1, 1, 1};
            const Polynomial p2{0, 1, 1, 1, 1, 1, 1, 1, 1};
            REQUIRE(ring2.add(p1, p2) == Polynomial{1, 1});

            const PolynomialRing ring5{5};
            const Polynomial p3{1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4};
            const Polynomial p4{1, 1, 1, 1, 4, 3, 2, 1, 4, 3, 2, 1};
            REQUIRE(ring5.add(p3, p4) == Polynomial{2, 3, 4});

            const PolynomialRing ring11{11};
            const Polynomial p5{10, 1, 10, 1, 10, 1, 10, 1, 10};
            const Polynomial p6{1, 10, 1, 10, 1, 10, 1, 10, 1};
            REQUIRE(ring11.add(p5, p6) == Polynomial{});
        }
    }

    SECTION("Subtraction") {
        SECTION("simple") {
            const PolynomialRing ring17{17};
            const Polynomial p1{};
            const Polynomial p2{};
            REQUIRE(ring17.subtract(p1, p2) == Polynomial{});

            const PolynomialRing ring71{71};
            const Polynomial p3{45, 32, 45, 57, 43, 59, 67, 70, 34};
            const Polynomial p4{12, 23, 44, 57, 12, 23, 45, 67, 12};
            REQUIRE(ring71.subtract(p3, p4) == Polynomial{33, 9, 1, 0, 31, 36, 22, 3, 22});

            REQUIRE(ring71.subtract(p3, Polynomial{}) == p3);
            REQUIRE(ring71.subtract(p4, Polynomial{}) == p4);

            const PolynomialRing ring47{47};
            const Polynomial p5{34, 35, 32, 35, 23, 34, 14, 25, 43, 42, 45, 37, 39, 40};
            const Polynomial p6{12, 13, 14, 15, 16, 17, 14, 25, 43, 12, 12};
            REQUIRE(ring47.subtract(p5, p6) == Polynomial{22, 22, 18, 20, 7, 17, 0, 0, 0, 30, 33, 37, 39, 40});
        }

        SECTION("with modification") {
            const PolynomialRing ring5{5};
            const Polynomial p1{1, 2, 1, 2, 3, 4, 2, 1, 3, 1};
            const Polynomial p2{4, 3, 3, 3, 4, 2, 3, 3, 3, 4};
            REQUIRE(ring5.subtract(p1, p2) == Polynomial{2, 4, 3, 4, 4, 2, 4, 3, 0, 2});

            const PolynomialRing ring37{37};
            const Polynomial p3{21, 34, 21, 25, 2, 3, 4, 21, 0, 21, 35};
            const Polynomial p4{21, 34, 26, 3, 9, 36, 32, 21, 21, 20, 24, 34, 36, 36, 36, 21, 23};
            REQUIRE(ring37.subtract(p3, p4) == Polynomial{0, 0, 32, 22, 30, 4, 9, 0, 16, 1, 11, 3, 1, 1, 1, 16, 14});

            const PolynomialRing ring199{199};
            const Polynomial p5{123, 145, 165, 134, 23, 146, 175, 123, 198, 111, 143, 43, 98, 143};
            const Polynomial p6{154, 162, 153, 141, 123, 67, 89, 98, 123, 198, 176, 187, 134, 123, 123, 123, 198};
            REQUIRE(ring199.subtract(p5, p6) == Polynomial{168, 182, 12, 192, 99, 79, 86, 25, 75, 112, 166, 55, 163, 20, 76, 76, 1});
        }

        SECTION("tail of zeros in result") {
            const PolynomialRing ring11{11};
            const Polynomial p1{5, 5, 5, 5, 6, 10, 10, 3, 2};
            REQUIRE(ring11.subtract(p1, p1) == Polynomial{});

            const Polynomial p2{1, 7, 5, 5, 10, 10, 10, 3, 2};
            REQUIRE(ring11.subtract(p1, p2) == Polynomial{4, 9, 0, 0, 7});

            const PolynomialRing ring199{199};
            const Polynomial p3{123, 43, 125, 22, 43, 154, 143, 124, 132, 1, 4, 34, 45};
            const Polynomial p4{122, 43, 126, 22, 42, 154, 144, 124, 132, 1, 4, 34, 45};
            REQUIRE(ring199.subtract(p3, p4) == Polynomial{1, 0, 156, 0, 1, 0, 156});
        }
    }

    SECTION("Multiplication") {
        SECTION("by number") {
            const PolynomialRing ring11{11};
            const Polynomial p1{5, 4, 7, 5, 6, 10, 10, 3, 2};
            uint64_t num = 0;

            REQUIRE(ring11.multiply(p1, num) == Polynomial{});
            REQUIRE(ring11.multiply(num, p1) == Polynomial{});

            num = 11;
            REQUIRE(ring11.multiply(p1, num) == Polynomial{});
            REQUIRE(ring11.multiply(num, p1) == Polynomial{});

            num = 3;
            REQUIRE(ring11.multiply(p1, num) == Polynomial{4, 1, 10, 4, 7, 8, 8, 9, 6});
            REQUIRE(ring11.multiply(num, p1) == Polynomial{4, 1, 10, 4, 7, 8, 8, 9, 6});

            const PolynomialRing ring37{37};
            const Polynomial p2{21, 34, 21, 25, 2, 3, 4, 21, 0, 21, 35};
            num = 321;
            REQUIRE(ring37.multiply(p2, num) == Polynomial{7, 36, 7, 33, 13, 1, 26, 7, 0, 7, 24});
            REQUIRE(ring37.multiply(num, p2) == Polynomial{7, 36, 7, 33, 13, 1, 26, 7, 0, 7, 24});

            const PolynomialRing ring181{181};
            const Polynomial p3{123, 145, 165, 134, 23, 146, 175, 123, 178, 111, 143, 43, 98, 143};
            num = 654;
            REQUIRE(ring181.multiply(p3, num) == Polynomial{78, 167, 34, 32, 19, 97, 58, 78, 29, 13, 126, 67, 18, 126});
            REQUIRE(ring181.multiply(num, p3) == Polynomial{78, 167, 34, 32, 19, 97, 58, 78, 29, 13, 126, 67, 18, 126});
        }

        SECTION("by polynomial") {
            const PolynomialRing ring11{11};
            const Polynomial p1{1, 5, 1};
            const Polynomial p2{2, 6, 7, 1};
            REQUIRE(ring11.multiply(p1, p2) == Polynomial{2, 5, 6, 9, 1, 1});
            REQUIRE(ring11.multiply(p2, p1) == Polynomial{2, 5, 6, 9, 1, 1});

            REQUIRE(ring11.multiply(p1, Polynomial{}) == Polynomial{});
            REQUIRE(ring11.multiply(Polynomial{}, p1) == Polynomial{});

            const PolynomialRing ring5{5};
            const Polynomial p3{1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4};
            const Polynomial p4{4, 3, 2, 1, 4, 3, 2, 1};
            REQUIRE(ring5.multiply(p3, p4) == Polynomial{4, 1, 0, 0, 3, 3, 4, 0, 3, 4, 3, 0, 4, 3, 3, 0, 0, 1, 4});
            REQUIRE(ring5.multiply(p4, p3) == Polynomial{4, 1, 0, 0, 3, 3, 4, 0, 3, 4, 3, 0, 4, 3, 3, 0, 0, 1, 4});

            const PolynomialRing ring157{157};
            const Polynomial p5{123, 145, 5, 134, 23, 146};
            const Polynomial p6{122, 43, 126, 22, 42, 154, 144, 124, 132, 1, 4, 34, 45};
            REQUIRE(ring157.multiply(p5, p6) == Polynomial{91, 57, 49, 16, 127, 68, 95, 45, 90, 26, 63, 16, 45, 150, 152, 17, 33, 133});
            REQUIRE(ring157.multiply(p6, p5) == Polynomial{91, 57, 49, 16, 127, 68, 95, 45, 90, 26, 63, 16, 45, 150, 152, 17, 33, 133});
        }
    }
}
