#include "gmock/gmock.h"
#include "SimilarityChecker.cpp"

class SimilarityCheckerFixture : public testing::Test {
public:
	SimilarityChecker checker;
};

TEST_F(SimilarityCheckerFixture, lengthTest) {

}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}
