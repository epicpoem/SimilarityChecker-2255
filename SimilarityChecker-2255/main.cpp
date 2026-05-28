#include "gmock/gmock.h"
#include "SimilarityChecker.cpp"

class SimilarityCheckerFixture : public testing::Test {
public:
	
};

TEST_F(SimilarityCheckerFixture, lengthTest1) {
	SimilarityChecker checker{ "ASD" };
	double ret = checker.doLengthCheck("DSA");
	EXPECT_EQ(60, ret);
}

TEST_F(SimilarityCheckerFixture, lengthTest2) {
	SimilarityChecker checker{ "A" };
	double ret = checker.doLengthCheck("BB");
	EXPECT_EQ(0, ret);
}

TEST_F(SimilarityCheckerFixture, lengthTest3) {
	SimilarityChecker checker{ "AAABB" };
	double ret = checker.doLengthCheck("BAA");
	EXPECT_EQ((1-((double)2/(double)3))*60, ret);
}

TEST_F(SimilarityCheckerFixture, lengthTest4) {
	SimilarityChecker checker{ "AA" };
	double ret = checker.doLengthCheck("AAE");
	EXPECT_EQ((1 - ((double)1 / (double)2)) * 60, ret);
}

TEST_F(SimilarityCheckerFixture, AlphaTest1) {
	SimilarityChecker checker{ "ASD" };
	double ret = checker.doAlphaCheck("DSA");
	EXPECT_EQ(40, ret);
}

TEST_F(SimilarityCheckerFixture, AlphaTest2) {
	SimilarityChecker checker{ "A" };
	double ret = checker.doAlphaCheck("BB");
	EXPECT_EQ(0, ret);
}

TEST_F(SimilarityCheckerFixture, AlphaTest3) {
	SimilarityChecker checker{ "AAABB" };
	double ret = checker.doAlphaCheck("BA");
	EXPECT_EQ(40, ret);
}

TEST_F(SimilarityCheckerFixture, AlphaTest4) {
	SimilarityChecker checker{ "AA" };
	double ret = checker.doAlphaCheck("AAE");
	EXPECT_EQ( ((double)1/(double)2) * 40, ret);
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}
