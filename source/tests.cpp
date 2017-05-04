#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"
#include "mat2.hpp"
#include "color.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

TEST_CASE("test vectors", "[Vec2]") 
	{
		SECTION ("constructors") {
			REQUIRE (Vec2().x == 0);
			REQUIRE (Vec2().y == 0);
			REQUIRE (Vec2(2.0, 3.5).x == 2.0);
			REQUIRE (Vec2(2.0, 3.5).y == 3.5);
			REQUIRE (Vec2(0, 3.5).x == 0);
			REQUIRE (Vec2(0, 6.23).y == Approx(6.23));
		}

		SECTION ("plus equals operator") {
			Vec2 vecA(2.0, 2.0);
			Vec2 vecB(0.0, 5.2);
			Vec2 vecC(3.6, 1.0);
			
			vecA += vecB;
			REQUIRE (vecA.x == 2.0);
			REQUIRE (vecA.y == Approx(7.2));
			REQUIRE (vecB.x == 0.0);
			REQUIRE (vecB.y == Approx(5.2));

			vecB += vecC;
			REQUIRE (vecB.x == Approx(3.6));
			REQUIRE (vecB.y == Approx(6.2));
			REQUIRE (vecC.x == Approx(3.6));
			REQUIRE (vecC.y == 1.0);

			vecC += vecA;
			REQUIRE (vecC.x == Approx(5.6));
			REQUIRE (vecC.y == Approx(8.2));
			REQUIRE (vecA.x == Approx(2.0));
			REQUIRE (vecA.y == Approx(7.2));
		}

		SECTION ("minus equals operator") {
			Vec2 vecA(2.0, 2.0);
			Vec2 vecB(0.0, 5.2);
			Vec2 vecC(3.6, 1.0);

			vecA -= vecB;
			REQUIRE (vecA.x == 2.0);
			REQUIRE (vecA.y == Approx(-3.2));
			REQUIRE (vecB.x == 0.0);
			REQUIRE (vecB.y == Approx(5.2));

			vecB -= vecC;
			REQUIRE (vecB.x == Approx(-3.6));
			REQUIRE (vecB.y == Approx(4.2));
			REQUIRE (vecC.x == Approx(3.6));
			REQUIRE (vecC.y == 1.0);

			vecC -= vecA;
			REQUIRE (vecC.x == Approx(1.6));
			REQUIRE (vecC.y == Approx(4.2));
			REQUIRE (vecA.x == 2.0);
			REQUIRE (vecA.y == Approx(-3.2));
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
			REQUIRE (vecC.x == Approx(-14.04));
			REQUIRE (vecC.y == Approx(-3.9));
			
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
			REQUIRE (vecB.y == Approx(5.2));

			vecC /= c;
			REQUIRE (vecC.x == Approx(-0.92308));
			REQUIRE (vecC.y == Approx(-0.25641));
		}

		SECTION ("plus operator") {

			Vec2 vecA(2.0, 2.0);
			Vec2 vecB(0.0, 5.2);
			Vec2 vecC(3.6, 1.0);
			
			Vec2 vecD = vecA + vecB;
			REQUIRE (vecD.x == 2.0);
			REQUIRE (vecD.y == Approx(7.2));

			Vec2 vecE = vecB + vecC;
			REQUIRE (vecE.x == Approx(3.6));
			REQUIRE (vecE.y == Approx(6.2));

			Vec2 vecF = vecC + vecA;
			REQUIRE (vecF.x == Approx(5.6));
			REQUIRE (vecF.y == Approx(3.0));
			
		}

		SECTION ("minus operator") {

			Vec2 vecA(2.0, 2.0);
			Vec2 vecB(0.0, 5.2);
			Vec2 vecC(3.6, 1.0);
			
			Vec2 vecD = vecA - vecB;
			REQUIRE (vecD.x == 2.0);
			REQUIRE (vecD.y == Approx(-3.2));

			Vec2 vecE = vecB - vecC;
			REQUIRE (vecE.x == Approx(-3.6));
			REQUIRE (vecE.y == Approx(4.2));

			Vec2 vecF = vecC - vecA;
			REQUIRE (vecF.x == Approx(1.6));
			REQUIRE (vecF.y == Approx(-1.0));
			
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
			REQUIRE (vecF.x == Approx(-14.04));
			REQUIRE (vecF.y == Approx(-3.9));
			
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
			REQUIRE (vecE.y == Approx(5.2));

			Vec2 vecF = vecC / c;
			REQUIRE (vecF.x == Approx(-0.92308));
			REQUIRE (vecF.y == Approx(-0.25641));
			
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
			REQUIRE (vecF.x == Approx(-14.04));
			REQUIRE (vecF.y == Approx(-3.9));
				
		}

	}


	TEST_CASE("test matrix", "[Mat2]") {

		SECTION ("constructors") {
			REQUIRE (Mat2().w == 1.0);
			REQUIRE (Mat2().x == 0.0);
			REQUIRE (Mat2().y == 0.0);
			REQUIRE (Mat2().z == 1.0);
			REQUIRE (Mat2(2.0, 5.2, 0.0, -1.0).w == 2.0);
			REQUIRE (Mat2(2.0, 5.2, 0.0, -1.0).x == Approx(5.2));
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
			REQUIRE (matB.z == 22.0);

			matB *= matC;
			REQUIRE (matB.w == Approx(22.4));
			REQUIRE (matB.x == Approx(15.6));
			REQUIRE (matB.y == 48.0);
			REQUIRE (matB.z == Approx(32.0));
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
			REQUIRE (matE.z == 22.0);

			Mat2 matG = matB * matC;
			REQUIRE (matG.w == Approx(3.2));
			REQUIRE (matG.x == Approx(0.8));
			REQUIRE (matG.y == Approx(9.6));
			REQUIRE (matG.z == Approx(7.4));
		}

		SECTION("matrix vector multiplication"){
			Mat2 matA(1.0, 2.0, 3.0, 4.0);
			Mat2 matB(0.0, 3.8, 2.5, -1.0);
			Vec2 vecA(1.0, 2.0);
			Vec2 vecB(-3.9, 0.0);

			Vec2 vecC = matA.vecmat(vecA);
			REQUIRE (vecC.x == 5.0);
			REQUIRE (vecC.y == 11.0);

			Vec2 vecD = matA.vecmat(vecB);
			REQUIRE (vecD.x == Approx(-3.9));
			REQUIRE (vecD.y == Approx(-11.7));

			Vec2 vecE = matB.vecmat(vecA);
			REQUIRE (vecE.x == Approx(7.6));
			REQUIRE (vecE.y == Approx(0.5));

			Vec2 vecF = matB.vecmat(vecB);
			REQUIRE (vecF.x == 0.0);
			REQUIRE (vecF.y == Approx(-9.75));
		}

		SECTION("determinant"){
			Mat2 matA(1.0, 2.0, 3.0, 4.0);
			Mat2 matB(3.9, -2.6, 0.0, 1.0);

			REQUIRE(matA.det() == -2.0);
			REQUIRE(matB.det() == Approx(3.9));
		}

		SECTION("inverse"){
			Mat2 matA(1.0, 2.0, 3.0, 4.0);
			Mat2 matB(3.9, -2.6, 0.0, 1.0);

			Mat2 matC = matA.inv();
			REQUIRE (matC.w == -2.0);
			REQUIRE (matC.x == 1.0);
			REQUIRE (matC.y == Approx(1.5));
			REQUIRE (matC.z == Approx(-0.5));

			Mat2 matD = matB.inv();
			REQUIRE (matD.w == Approx(0.2564));
			REQUIRE (matD.x == Approx(0.66667));
			REQUIRE (matD.y == 0.0);
			REQUIRE (matD.z == 1.0);
		}

		SECTION("transposed"){
			Mat2 matA(1.0, 2.0, 3.0, 4.0);
			Mat2 matB(3.9, -2.6, 0.0, 1.0);

			Mat2 matC = matA.tra();
			REQUIRE (matC.w == 1.0);
			REQUIRE (matC.x == 3.0);
			REQUIRE (matC.y == 2.0);
			REQUIRE (matC.z == 4.0);

			Mat2 matD = matB.tra();
			REQUIRE (matD.w == Approx(3.9));
			REQUIRE (matD.x == Approx(0.0));
			REQUIRE (matD.y == Approx(-2.6));
			REQUIRE (matD.z == 1.0);

		}

		SECTION("rotation matrix"){
			
			Mat2 matA = rot(0.5);
			REQUIRE (matA.w == Approx(0.87758));
			REQUIRE (matA.x == Approx(-0.47943));
			REQUIRE (matA.y == Approx(0.47943));
			REQUIRE (matA.z == Approx(0.87758));

			Mat2 matB = rot(0.0);
			REQUIRE (matB.w == 1.0);
			REQUIRE (matB.x == 0.0);
			REQUIRE (matB.y == 0.0);
			REQUIRE (matB.z == 1.0);

		}
	}

	TEST_CASE("test circle", "[Circle]"){
		SECTION("attributes and getter"){
			
			Vec2 vecA(0.0, 0.0);
			Vec2 vecB(5.0, 3.5);
			Color color(0.5);
			Circle cirA(7.0, vecA, color);
			Circle cirB(-9.2, vecB, color);

			REQUIRE (cirA.r == 7.0);
			REQUIRE (cirA.mid.x == 0.0);
			REQUIRE (cirA.mid.y == 0.0);

			REQUIRE (cirB.r == Approx(-9.2));
			REQUIRE (cirB.mid.x == 5.0);
			REQUIRE (cirB.mid.y == Approx(3.5));

		}
	}

	TEST_CASE("test rectangle", "[Rectangle]"){
		SECTION("attributes and getter"){
			
			Vec2 vecA(0.0, 0.0);
			Vec2 vecB(5.0, 3.5);
			Vec2 vecC(-1.0, -3.0);
			Color color(0.5);
			Rectangle recA(vecA, vecB, color);
			Rectangle recB(vecC, vecA, color);

			REQUIRE (recA.min_.x == 0.0);
			REQUIRE (recA.min_.y == 0.0);
			REQUIRE (recA.max_.x == 5.0);
			REQUIRE (recA.max_.y == Approx(3.5));

			REQUIRE (recB.min_.x == -1.0);
			REQUIRE (recB.min_.y == -3.0);
			REQUIRE (recB.max_.x == 0.0);
			REQUIRE (recB.max_.y == 0.0);

			Vec2 vecD = recA.getRightLow();
			REQUIRE (vecD.x == 5.0);
			REQUIRE (vecD.y == 0.0);
			
			Vec2 vecE = recA.getLeftHigh();
			REQUIRE (vecE.x == 0.0);
			REQUIRE (vecE.y == 3.5);

			Vec2 vecF = recB.getRightLow();
			REQUIRE (vecF.x == 0.0);
			REQUIRE (vecF.y == -3.0);
			
			Vec2 vecG = recB.getLeftHigh();
			REQUIRE (vecG.x == -1.0);
			REQUIRE (vecG.y == 0.0);

		}

		SECTION("circumference"){
			
			Vec2 vecA(0.0, 0.0);
			Vec2 vecB(5.0, 3.5);
			Vec2 vecC(-1.0, -3.0);
			Color color(0.5);
			Rectangle recA(vecA, vecB, color);
			Rectangle recB(vecC, vecA, color);

			REQUIRE (recA.circumference() == 17.0);
			REQUIRE (recB.circumference() == 8.0);

		}
	}



int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
