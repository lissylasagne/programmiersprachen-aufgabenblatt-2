#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"
#include "mat2.hpp"

TEST_CASE("test vectors", "[Vec2]") 
	{
		SECTION ("constructors") {
			REQUIRE (Vec2().x == 0);
			REQUIRE (Vec2().y == 0);
			REQUIRE (Vec2(2.0, 3.5).x == 2.0);
			REQUIRE (Vec2(2.0, 3.5).y == 3.5);
			REQUIRE (Vec2(0, 3.5).x == 0);
			REQUIRE (Vec2(0, 6.23).y == 6.23);
		}

		SECTION ("plus equals operator") {
			Vec2 vecA(2.0, 2.0);
			Vec2 vecB(0.0, 5.2);
			Vec2 vecC(3.6, 1.0);
			
			vecA += vecB;
			REQUIRE (vecA.x == 2.0);
			REQUIRE (vecA.y == 7.2);
			REQUIRE (vecB.x == 0.0);
			REQUIRE (vecB.y == 5.2);

			vecB += vecC;
			REQUIRE (vecB.x == 3.6);
			REQUIRE (vecB.y == 6.2);
			REQUIRE (vecC.x == 3.6);
			REQUIRE (vecC.y == 1.0);

			vecC += vecA;
			REQUIRE (vecC.x == 5.6);
			REQUIRE (vecC.y == 8.2);
			REQUIRE (vecA.x == 2.0);
			REQUIRE (vecA.y == 7.2);
		}

		SECTION ("minus equals operator") {
			Vec2 vecA(2.0, 2.0);
			Vec2 vecB(0.0, 5.2);
			Vec2 vecC(3.6, 1.0);

			vecA -= vecB;
			REQUIRE (vecA.x == 2.0);
			REQUIRE (vecA.y == -3.2);
			REQUIRE (vecB.x == 0.0);
			REQUIRE (vecB.y == 5.2);

			vecB -= vecC;
			REQUIRE (vecB.x == -3.6);
			REQUIRE (vecB.y == 4.2);
			REQUIRE (vecC.x == 3.6);
			REQUIRE (vecC.y == 1.0);

			vecC -= vecA;
			REQUIRE (vecC.x == 1.6);
			REQUIRE (vecC.y == 4.2);
			REQUIRE (vecA.x == 2.0);
			REQUIRE (vecA.y == -3.2);
		}

		SECTION ("multiply equals operator") {

			Vec2 vecA(2.0, 2.0);
			Vec2 vecB(0.0, 5.2);
			Vec2 vecC(3.6, 1.0);
			float a = 2.0;
			float b = 0.0;
			float c = -3.9;

			vecA *= a;
			REQUIRE (vecA.x == 4.0);
			REQUIRE (vecA.y == 4.0);

			vecB *= b;
			REQUIRE (vecB.x == 0.0);
			REQUIRE (vecB.y == 0.0);

			vecC *= c;
			REQUIRE (vecC.x == -14.04);
			REQUIRE (vecC.y == -3.9);
			
		}

		SECTION ("divided equals operator") {
			
			Vec2 vecA(2.0, 2.0);
			Vec2 vecB(0.0, 5.2);
			Vec2 vecC(3.6, 1.0);
			float a = 2.0;
			float b = 1.0;
			float c = -3.9;

			vecA /= a;
			REQUIRE (vecA.x == 1.0);
			REQUIRE (vecA.y == 1.0);

			vecB /= b;
			REQUIRE (vecB.x == 0.0);
			REQUIRE (vecB.y == 5.2);

			vecC /= c;
			REQUIRE (vecC.x == Approx(-0.923));
			REQUIRE (vecC.y == Approx(-0.256));
		}

		SECTION ("plus operator") {

			Vec2 vecA(2.0, 2.0);
			Vec2 vecB(0.0, 5.2);
			Vec2 vecC(3.6, 1.0);
			
			Vec2 vecD = vecA + vecB;
			REQUIRE (vecD.x == 2.0);
			REQUIRE (vecD.y == 7.2);

			Vec2 vecE = vecB + vecC;
			REQUIRE (vecE.x == 3.6);
			REQUIRE (vecE.y == 6.2);

			Vec2 vecF = vecC + vecA;
			REQUIRE (vecF.x == 5.6);
			REQUIRE (vecF.y == 3.0);
			
		}

		SECTION ("minus operator") {

			Vec2 vecA(2.0, 2.0);
			Vec2 vecB(0.0, 5.2);
			Vec2 vecC(3.6, 1.0);
			
			Vec2 vecD = vecA - vecB;
			REQUIRE (vecD.x == 2.0);
			REQUIRE (vecD.y == -3.2);

			Vec2 vecE = vecB - vecC;
			REQUIRE (vecE.x == -3.6);
			REQUIRE (vecE.y == 4.2);

			Vec2 vecF = vecC - vecA;
			REQUIRE (vecF.x == 1.6);
			REQUIRE (vecF.y == -1.0);
			
		}

		SECTION ("multiply operator 1") {

			Vec2 vecA(2.0, 2.0);
			Vec2 vecB(0.0, 5.2);
			Vec2 vecC(3.6, 1.0);
			float a = 2.0;
			float b = 0.0;
			float c = -3.9;

			Vec2 vecD = vecA * a;
			REQUIRE (vecD.x == 4.0);
			REQUIRE (vecD.y == 4.0);

			Vec2 vecE = vecB * b;
			REQUIRE (vecE.x == 0.0);
			REQUIRE (vecE.y == 0.0);

			Vec2 vecF = vecC * c;
			REQUIRE (vecF.x == -14.04);
			REQUIRE (vecF.y == -3.9);
			
		}

		SECTION ("divided operator") {

			Vec2 vecA(2.0, 2.0);
			Vec2 vecB(0.0, 5.2);
			Vec2 vecC(3.6, 1.0);
			float a = 2.0;
			float b = 1.0;
			float c = -3.9;

			Vec2 vecD = vecA / a;
			REQUIRE (vecD.x == 1.0);
			REQUIRE (vecD.y == 1.0);

			Vec2 vecE = vecB / b;
			REQUIRE (vecE.x == 0.0);
			REQUIRE (vecE.y == 5.2);

			Vec2 vecF = vecC / c;
			REQUIRE (vecF.x == Approx(-0.923));
			REQUIRE (vecF.y == Approx(-0.256));
			
		}

		SECTION ("multiply operator 2") {
			
			Vec2 vecA(2.0, 2.0);
			Vec2 vecB(0.0, 5.2);
			Vec2 vecC(3.6, 1.0);
			float a = 2.0;
			float b = 0.0;
			float c = -3.9;

			Vec2 vecD = a * vecA;
			REQUIRE (vecD.x == 4.0);
			REQUIRE (vecD.y == 4.0);

			Vec2 vecE = b * vecB;
			REQUIRE (vecE.x == 0.0);
			REQUIRE (vecE.y == 0.0);

			Vec2 vecF = c * vecC;
			REQUIRE (vecF.x == -14.04);
			REQUIRE (vecF.y == -3.9);
				
		}

	}


	TEST_CASE("test matrix", "[Mat2]") {

		SECTION ("constructors") {
			REQUIRE (Mat2().w == 1.0);
			REQUIRE (Mat2().x == 0.0);
			REQUIRE (Mat2().y == 0.0);
			REQUIRE (Mat2().z == 1.0);
			REQUIRE (Mat2(2.0, 5.2, 0.0, -1.0).w == 2.0);
			REQUIRE (Mat2(2.0, 5.2, 0.0, -1.0).x == 5.2);
			REQUIRE (Mat2(2.0, 5.2, 0.0, -1.0).y == 0.0);
			REQUIRE (Mat2(2.0, 5.2, 0.0, -1.0).z == -1.0);
		}

		SECTION("multiply equals operator"){

			Mat2 matA(1.0, 0.0, 0.0, 1.0);
			Mat2 matB(1.0, 2.0, 3.0, 4.0);
			Mat2 matC(3.2, 5.8, 0.0, -2.5);

			matB *= matA;
			REQUIRE (matB.w == 1.0);
			REQUIRE (matB.x == 2.0);
			REQUIRE (matB.y == 3.0);
			REQUIRE (matB.z == 4.0);

			matB *= matB;
			REQUIRE (matB.w == 7.0);
			REQUIRE (matB.x == 10.0);
			REQUIRE (matB.y == 15.0);
			REQUIRE (matB.z == 24.0);

			matB *= matC;
			REQUIRE (matB.w == 22.4);
			REQUIRE (matB.x == 15.6);
			REQUIRE (matB.y == 48);
			REQUIRE (matB.z == 24.5);
		}

		SECTION("multiply operator") {

			Mat2 matA(1.0, 0.0, 0.0, 1.0);
			Mat2 matB(1.0, 2.0, 3.0, 4.0);
			Mat2 matC(3.2, 5.8, 0.0, -2.5);

			Mat2 matD = matB * matA;
			REQUIRE (matD.w == 1.0);
			REQUIRE (matD.x == 2.0);
			REQUIRE (matD.y == 3.0);
			REQUIRE (matD.z == 4.0);

			Mat2 matE = matB * matB;
			REQUIRE (matE.w == 7.0);
			REQUIRE (matE.x == 10.0);
			REQUIRE (matE.y == 15.0);
			REQUIRE (matE.z == 24.0);

			Mat2 matG = matB * matC;
			REQUIRE (matG.w == 22.4);
			REQUIRE (matG.x == 15.6);
			REQUIRE (matG.y == 48);
			REQUIRE (matG.z == 24.5);
		}
	}



int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
